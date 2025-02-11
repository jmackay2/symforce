# ----------------------------------------------------------------------------
# SymForce - Copyright 2022, Skydio, Inc.
# This source code is under the Apache 2.0 license found in the LICENSE file.
# ----------------------------------------------------------------------------

from symforce import geo
from symforce import sympy as sm
from symforce import typing as T
from symforce.codegen import geo_factors_codegen


def custom_between_factor_residual(
    nav_T_src: geo.Pose3,
    nav_T_target: geo.Pose3,
    target_T_src_prior: geo.Pose3,
    prior_weight: T.Scalar,
    prior_sigmas: geo.Vector6,
    epsilon: T.Scalar,
) -> geo.Vector6:
    """
    Return the 6dof residual on the relative pose between the given two views. Compares
    the relative pose between the optimized poses to the relative pose between the priors.

    This is similar to geo_factors_codegen.between_factor, but it uses a weight and diagonal
    covariance instead of a sqrt information matrix

    Args:
        nav_T_src: Current pose of the src frame
        nav_T_target: Current pose of the target frame
        target_T_src_prior: Prior on the pose of src in the target frame
        prior_weight: The weight of the Gaussian prior
        prior_sigmas: The diagonal of the sqrt covariance matrix
        epsilon: Small positive value

    Outputs:
        res: The residual of the between factor
    """
    # Note: sqrt(weight) is safe and does not need to be pushed away from 0 by epsilon because
    # weight is a hyperparameter, so we don't need to differentiate with respect to weight or worry
    # about it being slightly negative.  Plus, adding epsilon would break the weight==0 case
    sqrt_info = sm.sqrt(prior_weight) * geo.Matrix66.diag(
        prior_sigmas.applyfunc(lambda s: 1 / (s + epsilon)).to_flat_list()
    )

    return geo.Vector6(
        geo_factors_codegen.between_factor(
            nav_T_target, nav_T_src, target_T_src_prior, sqrt_info, epsilon
        )
    )
