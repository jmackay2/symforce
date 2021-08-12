import math
import numpy
import typing as T

import sym  # pylint: disable=unused-import


class GroupOps(object):
    """
    Python GroupOps implementation for <class 'symforce.geo.pose2.Pose2'>.
    """

    @staticmethod
    def identity():
        # type: () -> T.List[float]

        # Total ops: 0

        # Input arrays

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 4
        _res[0] = 1
        _res[1] = 0
        _res[2] = 0
        _res[3] = 0
        return _res

    @staticmethod
    def inverse(a):
        # type: (sym.Pose2) -> T.List[float]

        # Total ops: 10

        # Input arrays
        _a = a.data

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 4
        _res[0] = _a[0]
        _res[1] = -_a[1]
        _res[2] = -_a[0] * _a[2] - _a[1] * _a[3]
        _res[3] = -_a[0] * _a[3] + _a[1] * _a[2]
        return _res

    @staticmethod
    def compose(a, b):
        # type: (sym.Pose2, sym.Pose2) -> T.List[float]

        # Total ops: 16

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 4
        _res[0] = _a[0] * _b[0] - _a[1] * _b[1]
        _res[1] = _a[0] * _b[1] + _a[1] * _b[0]
        _res[2] = _a[0] * _b[2] - _a[1] * _b[3] + _a[2]
        _res[3] = _a[0] * _b[3] + _a[1] * _b[2] + _a[3]
        return _res

    @staticmethod
    def between(a, b):
        # type: (sym.Pose2, sym.Pose2) -> T.List[float]

        # Total ops: 25

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (0)

        # Output terms
        _res = [0.0] * 4
        _res[0] = _a[0] * _b[0] + _a[1] * _b[1]
        _res[1] = _a[0] * _b[1] - _a[1] * _b[0]
        _res[2] = -_a[0] * _a[2] + _a[0] * _b[2] - _a[1] * _a[3] + _a[1] * _b[3]
        _res[3] = -_a[0] * _a[3] + _a[0] * _b[3] + _a[1] * _a[2] - _a[1] * _b[2]
        return _res

    @staticmethod
    def inverse_with_jacobian(a):
        # type: (sym.Pose2) -> T.Tuple[T.List[float], numpy.ndarray]

        # Total ops: 18

        # Input arrays
        _a = a.data

        # Intermediate terms (5)
        _tmp0 = -_a[1]
        _tmp1 = _a[0] * _a[2] + _a[1] * _a[3]
        _tmp2 = _a[0] * _a[3]
        _tmp3 = _a[1] * _a[2]
        _tmp4 = -_a[0]

        # Output terms
        _res = [0.0] * 4
        _res[0] = _a[0]
        _res[1] = _tmp0
        _res[2] = -_tmp1
        _res[3] = -_tmp2 + _tmp3
        _res_D_a = numpy.zeros((3, 3))
        _res_D_a[0, 0] = _tmp4
        _res_D_a[0, 1] = _tmp0
        _res_D_a[0, 2] = -_tmp2 + _tmp3
        _res_D_a[1, 0] = _a[1]
        _res_D_a[1, 1] = _tmp4
        _res_D_a[1, 2] = _tmp1
        _res_D_a[2, 0] = 0
        _res_D_a[2, 1] = 0
        _res_D_a[2, 2] = -_a[0] ** 2 - _a[1] ** 2
        return _res, _res_D_a

    @staticmethod
    def compose_with_jacobians(a, b):
        # type: (sym.Pose2, sym.Pose2) -> T.Tuple[T.List[float], numpy.ndarray, numpy.ndarray]

        # Total ops: 42

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (5)
        _tmp0 = _a[0] * _b[0] - _a[1] * _b[1]
        _tmp1 = _a[0] * _b[1] + _a[1] * _b[0]
        _tmp2 = _a[0] * _b[2] - _a[1] * _b[3]
        _tmp3 = _a[1] * _b[2]
        _tmp4 = _a[0] * _b[3]

        # Output terms
        _res = [0.0] * 4
        _res[0] = _tmp0
        _res[1] = _tmp1
        _res[2] = _a[2] + _tmp2
        _res[3] = _a[3] + _tmp3 + _tmp4
        _res_D_a = numpy.zeros((3, 3))
        _res_D_a[0, 0] = 1
        _res_D_a[0, 1] = 0
        _res_D_a[0, 2] = -_tmp3 - _tmp4
        _res_D_a[1, 0] = 0
        _res_D_a[1, 1] = 1
        _res_D_a[1, 2] = _tmp2
        _res_D_a[2, 0] = 0
        _res_D_a[2, 1] = 0
        _res_D_a[2, 2] = _a[0] * (_b[0] * _tmp0 + _b[1] * _tmp1) - _a[1] * (
            -_b[0] * _tmp1 + _b[1] * _tmp0
        )
        _res_D_b = numpy.zeros((3, 3))
        _res_D_b[0, 0] = _a[0]
        _res_D_b[0, 1] = -_a[1]
        _res_D_b[0, 2] = 0
        _res_D_b[1, 0] = _a[1]
        _res_D_b[1, 1] = _a[0]
        _res_D_b[1, 2] = 0
        _res_D_b[2, 0] = 0
        _res_D_b[2, 1] = 0
        _res_D_b[2, 2] = _b[0] * (_a[0] * _tmp0 + _a[1] * _tmp1) - _b[1] * (
            -_a[0] * _tmp1 + _a[1] * _tmp0
        )
        return _res, _res_D_a, _res_D_b

    @staticmethod
    def between_with_jacobians(a, b):
        # type: (sym.Pose2, sym.Pose2) -> T.Tuple[T.List[float], numpy.ndarray, numpy.ndarray]

        # Total ops: 67

        # Input arrays
        _a = a.data
        _b = b.data

        # Intermediate terms (5)
        _tmp0 = _a[0] * _b[0] + _a[1] * _b[1]
        _tmp1 = _a[0] * _b[1] - _a[1] * _b[0]
        _tmp2 = -_a[0]
        _tmp3 = -_a[1]
        _tmp4 = -_a[3] + _b[3]

        # Output terms
        _res = [0.0] * 4
        _res[0] = _tmp0
        _res[1] = _tmp1
        _res[2] = -_a[0] * _a[2] + _a[0] * _b[2] - _a[1] * _a[3] + _a[1] * _b[3]
        _res[3] = -_a[0] * _a[3] + _a[0] * _b[3] + _a[1] * _a[2] - _a[1] * _b[2]
        _res_D_a = numpy.zeros((3, 3))
        _res_D_a[0, 0] = _tmp2
        _res_D_a[0, 1] = _tmp3
        _res_D_a[0, 2] = _a[0] * _tmp4 - _a[1] * (-_a[2] + _b[2])
        _res_D_a[1, 0] = _a[1]
        _res_D_a[1, 1] = _tmp2
        _res_D_a[1, 2] = _a[0] * (_a[2] - _b[2]) - _a[1] * _tmp4
        _res_D_a[2, 0] = 0
        _res_D_a[2, 1] = 0
        _res_D_a[2, 2] = _a[0] * (-_b[0] * _tmp0 - _b[1] * _tmp1) - _a[1] * (
            -_b[0] * _tmp1 + _b[1] * _tmp0
        )
        _res_D_b = numpy.zeros((3, 3))
        _res_D_b[0, 0] = _a[0]
        _res_D_b[0, 1] = _a[1]
        _res_D_b[0, 2] = 0
        _res_D_b[1, 0] = _tmp3
        _res_D_b[1, 1] = _a[0]
        _res_D_b[1, 2] = 0
        _res_D_b[2, 0] = 0
        _res_D_b[2, 1] = 0
        _res_D_b[2, 2] = _b[0] * (_a[0] * _tmp0 - _a[1] * _tmp1) - _b[1] * (
            -_a[0] * _tmp1 - _a[1] * _tmp0
        )
        return _res, _res_D_a, _res_D_b
