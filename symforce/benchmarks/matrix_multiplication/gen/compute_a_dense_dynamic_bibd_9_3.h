// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once


#include <Eigen/Dense>



namespace sym {


/**
* This function was autogenerated. Do not modify by hand.
*
* Args:
*     x0: Scalar
*     x1: Scalar
*     x2: Scalar
*     x3: Scalar
*     x4: Scalar
*
* Outputs:
*     result: Matrix36_84
*/
template <typename Scalar>
Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> ComputeADenseDynamicBibd93(const Scalar x0, const Scalar x1, const Scalar x2, const Scalar x3, const Scalar x4) {

    // Total ops: 454

    // Input arrays

    // Intermediate terms (92)
    const Scalar _tmp0 = x4 + 1;
    const Scalar _tmp1 = x0*x1;
    const Scalar _tmp2 = -x2;
    const Scalar _tmp3 = _tmp2 + x0;
    const Scalar _tmp4 = x1*x3;
    const Scalar _tmp5 = 2*x3;
    const Scalar _tmp6 = x3 + x4;
    const Scalar _tmp7 = (Scalar(1)/Scalar(2))*x4;
    const Scalar _tmp8 = -x0;
    const Scalar _tmp9 = Scalar(1.0) / (_tmp0);
    const Scalar _tmp10 = x2 + 2;
    const Scalar _tmp11 = 2*x1;
    const Scalar _tmp12 = 2*x2;
    const Scalar _tmp13 = _tmp12 - 2;
    const Scalar _tmp14 = _tmp10 + _tmp8;
    const Scalar _tmp15 = x0 + 1;
    const Scalar _tmp16 = x0 + x3;
    const Scalar _tmp17 = Scalar(1.0) / (x2);
    const Scalar _tmp18 = x3 - 1;
    const Scalar _tmp19 = _tmp18*x0;
    const Scalar _tmp20 = Scalar(1.0) / (x3);
    const Scalar _tmp21 = -x3;
    const Scalar _tmp22 = _tmp21 + x2;
    const Scalar _tmp23 = (Scalar(1)/Scalar(2))*x3;
    const Scalar _tmp24 = 2*x0;
    const Scalar _tmp25 = x0 + x1;
    const Scalar _tmp26 = x2 - 2;
    const Scalar _tmp27 = std::pow(x1, Scalar(2));
    const Scalar _tmp28 = 2*_tmp27;
    const Scalar _tmp29 = Scalar(1.0) / (x1);
    const Scalar _tmp30 = -x4;
    const Scalar _tmp31 = 4*x2;
    const Scalar _tmp32 = -_tmp31;
    const Scalar _tmp33 = x4 - 1;
    const Scalar _tmp34 = 2*_tmp17;
    const Scalar _tmp35 = x3 + 1;
    const Scalar _tmp36 = x0*x3;
    const Scalar _tmp37 = x2*x4;
    const Scalar _tmp38 = -x1;
    const Scalar _tmp39 = x4 + 2;
    const Scalar _tmp40 = _tmp11*x4;
    const Scalar _tmp41 = _tmp17*x1;
    const Scalar _tmp42 = x1 + x4;
    const Scalar _tmp43 = _tmp42*x2;
    const Scalar _tmp44 = x0 - 4;
    const Scalar _tmp45 = _tmp18*x1;
    const Scalar _tmp46 = Scalar(1.0) / (x0);
    const Scalar _tmp47 = x1*x4;
    const Scalar _tmp48 = _tmp12 + 2;
    const Scalar _tmp49 = x1 + 2;
    const Scalar _tmp50 = x0 + x4;
    const Scalar _tmp51 = std::pow(x4, Scalar(2));
    const Scalar _tmp52 = _tmp30 + x2;
    const Scalar _tmp53 = _tmp52*x2;
    const Scalar _tmp54 = x1 + 1;
    const Scalar _tmp55 = x2 + 1;
    const Scalar _tmp56 = x2 + x3;
    const Scalar _tmp57 = Scalar(1.0) / (x4);
    const Scalar _tmp58 = _tmp57*x2;
    const Scalar _tmp59 = _tmp21 + x1;
    const Scalar _tmp60 = x3 + 2;
    const Scalar _tmp61 = std::pow(x0, Scalar(2));
    const Scalar _tmp62 = x1 - 2;
    const Scalar _tmp63 = x1*x2;
    const Scalar _tmp64 = x3 - 2;
    const Scalar _tmp65 = x0 + 3;
    const Scalar _tmp66 = -_tmp34;
    const Scalar _tmp67 = _tmp24 - 2;
    const Scalar _tmp68 = _tmp66 + x4;
    const Scalar _tmp69 = 2*x4;
    const Scalar _tmp70 = _tmp69 - 4;
    const Scalar _tmp71 = x2*x3;
    const Scalar _tmp72 = x0*x4;
    const Scalar _tmp73 = x3*x4;
    const Scalar _tmp74 = x1 + x2;
    const Scalar _tmp75 = x4 - 2;
    const Scalar _tmp76 = x2 - 1;
    const Scalar _tmp77 = -_tmp24;
    const Scalar _tmp78 = _tmp48 + _tmp77;
    const Scalar _tmp79 = x0 - 2;
    const Scalar _tmp80 = -_tmp69;
    const Scalar _tmp81 = std::pow(x2, Scalar(2));
    const Scalar _tmp82 = x0 - 1;
    const Scalar _tmp83 = _tmp24 + 2;
    const Scalar _tmp84 = x1 - 1;
    const Scalar _tmp85 = -_tmp12;
    const Scalar _tmp86 = _tmp30 + x0;
    const Scalar _tmp87 = _tmp69 + 4;
    const Scalar _tmp88 = _tmp4*x0;
    const Scalar _tmp89 = x0*x2;
    const Scalar _tmp90 = 4*x4;
    const Scalar _tmp91 = _tmp24*x1;

    // Output terms (1)
    Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> _result(36, 84);

    _result.setZero();

    _result(0, 0) = _tmp0;
    _result(1, 0) = -Scalar(1)/Scalar(4)*_tmp1;
    _result(8, 0) = -_tmp3 - 4;
    _result(0, 1) = _tmp4;
    _result(2, 1) = -_tmp5*(x3 - 3) + 1;
    _result(9, 1) = -x3*(_tmp2 + _tmp6);
    _result(0, 2) = -x4*(_tmp7 + (Scalar(1)/Scalar(2))*x2);
    _result(3, 2) = _tmp5 + _tmp8 + 2;
    _result(10, 2) = _tmp9*x0 + x3;
    _result(0, 3) = -_tmp10*_tmp11 + _tmp10;
    _result(4, 3) = _tmp13 + x3;
    _result(11, 3) = -_tmp14;
    _result(0, 4) = -_tmp15/_tmp16;
    _result(5, 4) = _tmp5 + 6*x2 - 4;
    _result(12, 4) = 8*x0;
    _result(0, 5) = -x4*(-_tmp17 + x1) + 1;
    _result(6, 5) = -_tmp19;
    _result(13, 5) = _tmp20*(_tmp22 + 3);
    _result(0, 6) = -_tmp23*x0 + _tmp7;
    _result(7, 6) = 6 - _tmp24;
    _result(14, 6) = _tmp25*x2 + x0;
    _result(1, 7) = _tmp26;
    _result(2, 7) = -_tmp28 - 4;
    _result(15, 7) = -_tmp11 - 2;
    _result(1, 8) = _tmp5*x0 - 2;
    _result(3, 8) = _tmp29 + x1;
    _result(16, 8) = -_tmp23 - _tmp30;
    _result(1, 9) = x2*(_tmp6 + x2) + x4;
    _result(4, 9) = _tmp32;
    _result(17, 9) = 2;
    _result(1, 10) = _tmp0;
    _result(5, 10) = -_tmp33*x2;
    _result(18, 10) = _tmp10 + _tmp34 + _tmp5;
    _result(1, 11) = -_tmp35;
    _result(6, 11) = x0 - x1*(_tmp7 + Scalar(-1)/Scalar(2));
    _result(19, 11) = _tmp35*_tmp36;
    _result(1, 12) = _tmp30 + _tmp37;
    _result(7, 12) = -_tmp3*x1;
    _result(20, 12) = -_tmp13;
    _result(2, 13) = -x2*(_tmp21 + _tmp25 - 2);
    _result(3, 13) = x4;
    _result(21, 13) = -_tmp37*(_tmp38 + _tmp39);
    _result(2, 14) = -_tmp6 - 2;
    _result(4, 14) = -_tmp17*_tmp40;
    _result(22, 14) = -_tmp2 - Scalar(1)/Scalar(2)*_tmp41;
    _result(2, 15) = _tmp43;
    _result(5, 15) = _tmp30 + _tmp44*x3;
    _result(23, 15) = _tmp2 + _tmp21 + _tmp42;
    _result(2, 16) = _tmp11;
    _result(6, 16) = _tmp35*x1;
    _result(24, 16) = _tmp45;
    _result(2, 17) = -_tmp46*_tmp47 - 2;
    _result(7, 17) = -_tmp16*x3;
    _result(25, 17) = x1*(_tmp47 + x1);
    _result(3, 18) = -_tmp48*x4;
    _result(4, 18) = -_tmp49*_tmp9 + 1;
    _result(26, 18) = -_tmp6;
    _result(3, 19) = x2/(_tmp50 + 2);
    _result(5, 19) = _tmp51;
    _result(27, 19) = _tmp27*x3 + x2;
    _result(3, 20) = -_tmp0;
    _result(6, 20) = 1;
    _result(28, 20) = -_tmp41 - 1;
    _result(3, 21) = -_tmp53;
    _result(7, 21) = Scalar(2.0);
    _result(29, 21) = _tmp36 + _tmp54;
    _result(4, 22) = Scalar(1.0)*_tmp55*x0 + 2;
    _result(5, 22) = -_tmp11 - _tmp32;
    _result(30, 22) = -_tmp12*x4;
    _result(4, 23) = x3*(_tmp42 - 2);
    _result(6, 23) = -_tmp56*_tmp58;
    _result(31, 23) = _tmp59*x1 + x1;
    _result(4, 24) = _tmp37;
    _result(7, 24) = _tmp60 + _tmp8;
    _result(32, 24) = x0 - 3*x1 + 2;
    _result(5, 25) = x1*(_tmp10 + x0);
    _result(6, 25) = -_tmp22;
    _result(33, 25) = -_tmp5*_tmp60;
    _result(5, 26) = -_tmp45*_tmp61;
    _result(7, 26) = _tmp37*_tmp46;
    _result(34, 26) = -x2*(_tmp24 + x4);
    _result(6, 27) = _tmp62;
    _result(7, 27) = -_tmp38 - _tmp63;
    _result(35, 27) = (Scalar(1)/Scalar(2))*x0;
    _result(8, 28) = _tmp64*x3 + x1;
    _result(9, 28) = -_tmp65*x1 + x0;
    _result(8, 29) = _tmp2 + _tmp25 - 3;
    _result(10, 29) = _tmp66 + 1;
    _result(16, 29) = x4;
    _result(8, 30) = -_tmp20*_tmp67;
    _result(11, 30) = x1*(_tmp15 + x2);
    _result(17, 30) = _tmp68;
    _result(8, 31) = _tmp24 + _tmp5 - 3;
    _result(12, 31) = _tmp24 + _tmp70;
    _result(18, 31) = -_tmp21 - _tmp71;
    _result(8, 32) = _tmp44;
    _result(13, 32) = _tmp27;
    _result(19, 32) = -_tmp12 - x3;
    _result(8, 33) = -_tmp10*x0;
    _result(14, 33) = _tmp11 + x2 - 3;
    _result(20, 33) = -_tmp60;
    _result(9, 34) = _tmp40;
    _result(10, 34) = _tmp50 - _tmp72;
    _result(21, 34) = 4*_tmp36;
    _result(9, 35) = -_tmp30 - _tmp73 - 2;
    _result(11, 35) = _tmp47;
    _result(22, 35) = x2;
    _result(9, 36) = -_tmp20*_tmp72*_tmp74;
    _result(12, 36) = x3 - x4/_tmp49;
    _result(23, 36) = _tmp30 + _tmp5;
    _result(9, 37) = _tmp17*_tmp24*_tmp47;
    _result(13, 37) = x2/(x0 - 2*std::pow(x3, Scalar(2)));
    _result(24, 37) = _tmp66 + 2;
    _result(9, 38) = _tmp35 + x2;
    _result(14, 38) = -_tmp5*x4 - x0;
    _result(25, 38) = -_tmp50;
    _result(10, 39) = _tmp20*(_tmp0 + 2*_tmp20);
    _result(11, 39) = Scalar(1.0)/_tmp75;
    _result(26, 39) = _tmp75*x4;
    _result(10, 40) = _tmp31 - 1;
    _result(12, 40) = -_tmp12*(_tmp12 - 1);
    _result(27, 40) = _tmp53 + 2;
    _result(10, 41) = -_tmp52 - _tmp65;
    _result(13, 41) = _tmp67;
    _result(28, 41) = _tmp1 + _tmp11 + _tmp30;
    _result(10, 42) = _tmp64;
    _result(14, 42) = -_tmp69 - 2;
    _result(29, 42) = -_tmp76;
    _result(11, 43) = -_tmp49;
    _result(12, 43) = -_tmp47;
    _result(30, 43) = _tmp30;
    _result(11, 44) = _tmp57*x1;
    _result(13, 44) = -_tmp25 - 2;
    _result(31, 44) = _tmp50*x3 - _tmp54;
    _result(11, 45) = _tmp78;
    _result(14, 45) = -_tmp35 + _tmp36 - x1;
    _result(32, 45) = _tmp52*x1;
    _result(12, 46) = _tmp76*x4 + _tmp79;
    _result(13, 46) = _tmp26;
    _result(33, 46) = _tmp78;
    _result(12, 47) = _tmp47;
    _result(14, 47) = _tmp26 + x1;
    _result(34, 47) = -x3*(_tmp56 + x1);
    _result(13, 48) = -_tmp5;
    _result(14, 48) = _tmp20*_tmp47;
    _result(35, 48) = _tmp12*_tmp14 + 4;
    _result(15, 49) = _tmp52;
    _result(16, 49) = -x0/(_tmp12 - 4);
    _result(21, 49) = -_tmp69*_tmp81 - _tmp80;
    _result(15, 50) = x4*(_tmp10 + x3);
    _result(17, 50) = _tmp55;
    _result(22, 50) = -_tmp15*x4;
    _result(15, 51) = -_tmp82;
    _result(18, 51) = _tmp56 + _tmp8;
    _result(23, 51) = -_tmp5 - 6;
    _result(15, 52) = -_tmp26;
    _result(19, 52) = _tmp83;
    _result(24, 52) = -_tmp39*x3 + x2;
    _result(15, 53) = _tmp73 + _tmp84;
    _result(20, 53) = -_tmp49 - _tmp85;
    _result(25, 53) = -_tmp86;
    _result(16, 54) = -_tmp29*_tmp36*_tmp86 - 1;
    _result(17, 54) = _tmp60*_tmp84;
    _result(26, 54) = _tmp33*_tmp72;
    _result(16, 55) = 4;
    _result(18, 55) = _tmp1;
    _result(27, 55) = -2;
    _result(16, 56) = _tmp79*x4;
    _result(19, 56) = -_tmp67;
    _result(28, 56) = -_tmp29*_tmp5;
    _result(20, 57) = -_tmp24*_tmp64 + 1;
    _result(29, 57) = _tmp11 + _tmp80;
    _result(17, 58) = -_tmp33*_tmp46 + x2;
    _result(18, 58) = -_tmp39*(x3 + Scalar(-1.0));
    _result(30, 58) = _tmp25;
    _result(17, 59) = -_tmp29*_tmp57*x0;
    _result(19, 59) = _tmp63 + 1;
    _result(31, 59) = -x0/_tmp62;
    _result(17, 60) = _tmp19 + 1;
    _result(20, 60) = -_tmp70;
    _result(32, 60) = -_tmp59*x0*(x0 + x2);
    _result(18, 61) = -2;
    _result(19, 61) = _tmp12*_tmp72;
    _result(33, 61) = -3;
    _result(18, 62) = -_tmp39*x4;
    _result(20, 62) = -_tmp77 - _tmp87;
    _result(34, 62) = _tmp12*_tmp47;
    _result(19, 63) = _tmp88;
    _result(20, 63) = _tmp6 - 2;
    _result(35, 63) = _tmp81 - _tmp89 + x3;
    _result(21, 64) = -_tmp12 - x4;
    _result(22, 64) = 3 - _tmp63;
    _result(26, 64) = x1;
    _result(21, 65) = _tmp27*_tmp87;
    _result(23, 65) = x2*(_tmp2 + x1);
    _result(27, 65) = _tmp11*(x2 + x4);
    _result(21, 66) = _tmp89;
    _result(24, 66) = -x3/(_tmp69 + 1);
    _result(28, 66) = -_tmp81*x1;
    _result(21, 67) = _tmp24 - 1;
    _result(25, 67) = _tmp88 + x3;
    _result(29, 67) = -_tmp11;
    _result(22, 68) = _tmp80 + _tmp85 + x1 + 4;
    _result(23, 68) = _tmp74;
    _result(30, 68) = _tmp35;
    _result(22, 69) = -2*_tmp57 + x4;
    _result(24, 69) = -_tmp90;
    _result(31, 69) = x1 + 3;
    _result(22, 70) = 3*x2 + 4;
    _result(25, 70) = _tmp24 - 4;
    _result(32, 70) = _tmp2 + _tmp83;
    _result(23, 71) = -_tmp68*x3 - 1;
    _result(24, 71) = -x4*(_tmp76*x3 + 1);
    _result(33, 71) = _tmp34/_tmp64;
    _result(23, 72) = -_tmp18*_tmp4;
    _result(25, 72) = _tmp6 - _tmp63*x0;
    _result(34, 72) = _tmp43;
    _result(24, 73) = _tmp70;
    _result(25, 73) = -_tmp11 - _tmp8 - x4;
    _result(35, 73) = _tmp21 + _tmp91;
    _result(26, 74) = _tmp33 + x2;
    _result(27, 74) = _tmp38 + _tmp6;
    _result(30, 74) = Scalar(-0.5);
    _result(26, 75) = -6;
    _result(28, 75) = _tmp60*x2;
    _result(31, 75) = -_tmp20*_tmp26 - x3;
    _result(26, 76) = -_tmp10*_tmp46 - x1;
    _result(29, 76) = x2*(x0 - 12);
    _result(32, 76) = _tmp91;
    _result(27, 77) = -x4/(_tmp37*x1 + x2);
    _result(28, 77) = -_tmp47*_tmp82;
    _result(33, 77) = _tmp90 - 8;
    _result(27, 78) = -_tmp40 + x0;
    _result(29, 78) = Scalar(-1.5);
    _result(34, 78) = _tmp38;
    _result(28, 79) = -_tmp34*_tmp61;
    _result(29, 79) = _tmp11;
    _result(35, 79) = -_tmp21 - _tmp28;
    _result(30, 80) = -x2 - 1/(_tmp51 + 1);
    _result(31, 80) = _tmp52;
    _result(33, 80) = _tmp10;
    _result(30, 81) = _tmp58 - 1;
    _result(32, 81) = -_tmp0*x0 - _tmp2;
    _result(34, 81) = _tmp89 + x1 + x3;
    _result(31, 82) = -_tmp4*(_tmp16 + 2);
    _result(32, 82) = Scalar(1.0) / (_tmp33);
    _result(35, 82) = -_tmp74*x3;
    _result(33, 83) = _tmp18*_tmp71;
    _result(34, 83) = _tmp66;
    _result(35, 83) = _tmp17*_tmp73;

    return _result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
