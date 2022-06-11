# ----------------------------------------------------------------------------
# SymForce - Copyright 2022, Skydio, Inc.
# This source code is under the Apache 2.0 license found in the LICENSE file.
# ----------------------------------------------------------------------------

import os

import symforce
from symforce import codegen
from symforce import geo
from symforce.opt.noise_models import BarronNoiseModel
from symforce.test_util import TestCase
from symforce import typing as T

SYMFORCE_DIR = os.path.dirname(os.path.dirname(__file__))
TEST_DATA_DIR = os.path.join(
    SYMFORCE_DIR, "test", "symforce_function_codegen_test_data", symforce.get_symbolic_api()
)


def barron_factor(x: geo.Matrix51, y: geo.Matrix51, mu: T.Scalar, eps: T.Scalar) -> geo.Matrix51:
    # Transform mu, which ranges from 0->1, to alpha in the Barron noise model,
    # by alpha=2-1/(1-mu)
    # This transformation means alpha will range from 1 to -inf, so that
    # the noise model starts as a pseudo-huber and goes to a robust Welsch cost.
    alpha = BarronNoiseModel.compute_alpha_from_mu(mu, eps)

    noise_model = BarronNoiseModel(alpha=alpha, delta=1, scalar_information=1, x_epsilon=eps)
    return noise_model.whiten(x - y)


class SymGncCodegenTest(TestCase):
    """
    Test generating a factor used by symforce_gnc_test.cc
    """

    def test_factor_codegen(self) -> None:
        output_dir = self.make_output_dir("sf_gnc_codegen_test_")

        namespace = "gnc_factors"

        # Compute code
        codegen.Codegen.function(func=barron_factor, config=codegen.CppConfig()).with_linearization(
            which_args=["x"]
        ).generate_function(output_dir=output_dir, namespace=namespace)

        self.compare_or_update_directory(
            actual_dir=output_dir, expected_dir=os.path.join(TEST_DATA_DIR, "gnc_test_data")
        )


if __name__ == "__main__":
    TestCase.main()
