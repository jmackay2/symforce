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
*     result: Matrix15_15
*/
template <typename Scalar>
__attribute__((noinline))
Eigen::Matrix<Scalar, 15, 15> ComputeAtBN3C4B2(const Scalar x0, const Scalar x1, const Scalar x2, const Scalar x3, const Scalar x4) {

    // Total ops: 497

    // Input arrays

    // Intermediate terms (151)
    const Scalar _tmp0 = Scalar(1.0) / (x3);
    const Scalar _tmp1 = x2*x4;
    const Scalar _tmp2 = x4 + 6;
    const Scalar _tmp3 = _tmp0*_tmp2;
    const Scalar _tmp4 = Scalar(1.0) / (x4);
    const Scalar _tmp5 = _tmp4*x0;
    const Scalar _tmp6 = std::pow(x1, Scalar(2));
    const Scalar _tmp7 = x0 + x3;
    const Scalar _tmp8 = _tmp6*_tmp7;
    const Scalar _tmp9 = x1 + 2;
    const Scalar _tmp10 = _tmp9*x4;
    const Scalar _tmp11 = x3 - 1;
    const Scalar _tmp12 = _tmp11*x3;
    const Scalar _tmp13 = _tmp12 - 1;
    const Scalar _tmp14 = std::pow(x2, Scalar(2));
    const Scalar _tmp15 = x4 - 2;
    const Scalar _tmp16 = _tmp14*(x2 - x3/_tmp15);
    const Scalar _tmp17 = Scalar(1.0) / (x1);
    const Scalar _tmp18 = 2*_tmp17;
    const Scalar _tmp19 = -x4;
    const Scalar _tmp20 = _tmp19 + x0;
    const Scalar _tmp21 = 2*x0;
    const Scalar _tmp22 = _tmp21*x3;
    const Scalar _tmp23 = _tmp22 - 1;
    const Scalar _tmp24 = x1 - 2;
    const Scalar _tmp25 = -x3;
    const Scalar _tmp26 = _tmp24*(_tmp25 + x1);
    const Scalar _tmp27 = 4*x1;
    const Scalar _tmp28 = 4*x4;
    const Scalar _tmp29 = _tmp27 + _tmp28;
    const Scalar _tmp30 = _tmp0*_tmp5;
    const Scalar _tmp31 = _tmp24 + x3;
    const Scalar _tmp32 = x1 + x2 - 3;
    const Scalar _tmp33 = _tmp0*x4;
    const Scalar _tmp34 = x4 - 3;
    const Scalar _tmp35 = -x1;
    const Scalar _tmp36 = _tmp35 + x4;
    const Scalar _tmp37 = _tmp36 + 2;
    const Scalar _tmp38 = 2*x4;
    const Scalar _tmp39 = -_tmp38;
    const Scalar _tmp40 = x1 + 1;
    const Scalar _tmp41 = x3*(_tmp39 + _tmp40);
    const Scalar _tmp42 = std::pow(x3, Scalar(2));
    const Scalar _tmp43 = x0 - 2;
    const Scalar _tmp44 = x2 + 3;
    const Scalar _tmp45 = (Scalar(1)/Scalar(2))*x0;
    const Scalar _tmp46 = _tmp45*x2;
    const Scalar _tmp47 = _tmp4*_tmp46;
    const Scalar _tmp48 = x0*x3;
    const Scalar _tmp49 = _tmp48 + _tmp7;
    const Scalar _tmp50 = x3 + x4;
    const Scalar _tmp51 = x0*(_tmp50 + 2) - 2;
    const Scalar _tmp52 = Scalar(1.0) / (_tmp21 - 2);
    const Scalar _tmp53 = 4*_tmp52;
    const Scalar _tmp54 = _tmp38 + x0;
    const Scalar _tmp55 = _tmp54 + 4;
    const Scalar _tmp56 = x1*x3;
    const Scalar _tmp57 = _tmp38*_tmp56;
    const Scalar _tmp58 = _tmp38 + 2;
    const Scalar _tmp59 = _tmp58*x4;
    const Scalar _tmp60 = x2 - 2;
    const Scalar _tmp61 = 2*_tmp42 + 4;
    const Scalar _tmp62 = _tmp61*x0;
    const Scalar _tmp63 = Scalar(1.0) / (x2);
    const Scalar _tmp64 = _tmp63*x1;
    const Scalar _tmp65 = _tmp19 + _tmp64;
    const Scalar _tmp66 = _tmp63*(4*x0 + x3);
    const Scalar _tmp67 = x0 + 7;
    const Scalar _tmp68 = _tmp27 + x4;
    const Scalar _tmp69 = _tmp25 + x2 + 2;
    const Scalar _tmp70 = _tmp40*x1;
    const Scalar _tmp71 = _tmp54 + 1;
    const Scalar _tmp72 = 2*x2;
    const Scalar _tmp73 = _tmp35 + _tmp72 + 4;
    const Scalar _tmp74 = _tmp43*x0;
    const Scalar _tmp75 = _tmp42*_tmp74;
    const Scalar _tmp76 = x1 - 4;
    const Scalar _tmp77 = x1 + 4;
    const Scalar _tmp78 = x0 + x1;
    const Scalar _tmp79 = std::pow(x4, Scalar(2));
    const Scalar _tmp80 = _tmp78*_tmp79;
    const Scalar _tmp81 = 2*_tmp14;
    const Scalar _tmp82 = 2*x1;
    const Scalar _tmp83 = _tmp45 - _tmp82;
    const Scalar _tmp84 = x3*(_tmp35 + x2 + 1);
    const Scalar _tmp85 = _tmp72 + 2;
    const Scalar _tmp86 = _tmp39 + _tmp85;
    const Scalar _tmp87 = _tmp78*x4;
    const Scalar _tmp88 = _tmp21 + x2;
    const Scalar _tmp89 = x0*(x0 + 2);
    const Scalar _tmp90 = -_tmp1 + _tmp7;
    const Scalar _tmp91 = _tmp67*x3;
    const Scalar _tmp92 = _tmp82*x3 + 2;
    const Scalar _tmp93 = _tmp72*x1;
    const Scalar _tmp94 = _tmp25 + _tmp88;
    const Scalar _tmp95 = _tmp48*x4;
    const Scalar _tmp96 = x2 - 1;
    const Scalar _tmp97 = _tmp96 + x4;
    const Scalar _tmp98 = x1*x4;
    const Scalar _tmp99 = _tmp11 + _tmp78;
    const Scalar _tmp100 = _tmp25 + _tmp72 + x4;
    const Scalar _tmp101 = _tmp21 + 1;
    const Scalar _tmp102 = x1 - 1;
    const Scalar _tmp103 = _tmp102*x3 + x0;
    const Scalar _tmp104 = _tmp40*x3;
    const Scalar _tmp105 = _tmp74 + x4;
    const Scalar _tmp106 = _tmp21 + _tmp79;
    const Scalar _tmp107 = _tmp20*x3 + 2;
    const Scalar _tmp108 = Scalar(1.0) / (x0);
    const Scalar _tmp109 = -_tmp108*x2 + 1;
    const Scalar _tmp110 = x3*x4;
    const Scalar _tmp111 = _tmp109*_tmp110;
    const Scalar _tmp112 = _tmp21*(x0 + x2) + 2;
    const Scalar _tmp113 = _tmp39 + x1;
    const Scalar _tmp114 = (Scalar(1)/Scalar(4))*x1 + x3;
    const Scalar _tmp115 = _tmp0*_tmp18;
    const Scalar _tmp116 = _tmp110/_tmp96 - 2;
    const Scalar _tmp117 = x2 + x4;
    const Scalar _tmp118 = x0*x1;
    const Scalar _tmp119 = _tmp82 - 2;
    const Scalar _tmp120 = _tmp119*x1;
    const Scalar _tmp121 = _tmp117*x0;
    const Scalar _tmp122 = x1*x2;
    const Scalar _tmp123 = _tmp122*x0 + _tmp21;
    const Scalar _tmp124 = _tmp108 + x2;
    const Scalar _tmp125 = _tmp124*x3;
    const Scalar _tmp126 = x2*(_tmp122 + _tmp25) - 2;
    const Scalar _tmp127 = -_tmp38*x2 + x1;
    const Scalar _tmp128 = _tmp127*x3;
    const Scalar _tmp129 = _tmp14*(x3 - 2);
    const Scalar _tmp130 = _tmp25 + x0 + 3;
    const Scalar _tmp131 = _tmp24*(x2 + x3);
    const Scalar _tmp132 = _tmp20 + x1;
    const Scalar _tmp133 = _tmp19 + x1;
    const Scalar _tmp134 = _tmp79*x0;
    const Scalar _tmp135 = _tmp60*_tmp98;
    const Scalar _tmp136 = _tmp133*_tmp95;
    const Scalar _tmp137 = Scalar(2.0)*x3 + Scalar(-4.0);
    const Scalar _tmp138 = _tmp38 + _tmp72;
    const Scalar _tmp139 = _tmp138 - _tmp21;
    const Scalar _tmp140 = x4 - 1;
    const Scalar _tmp141 = _tmp38 + 8;
    const Scalar _tmp142 = 2*_tmp6*(x4 + 1);
    const Scalar _tmp143 = _tmp15 + x2;
    const Scalar _tmp144 = _tmp1*x3 + _tmp36;
    const Scalar _tmp145 = _tmp82 + 1;
    const Scalar _tmp146 = -x0 + 4*x2 + 4;
    const Scalar _tmp147 = x1 - 5;
    const Scalar _tmp148 = _tmp48 + 2;
    const Scalar _tmp149 = _tmp60 + x0*x2 + x3;
    const Scalar _tmp150 = _tmp98*[&]() { const Scalar base = x3; return base * base * base; }();

    // Output terms (1)
    Eigen::Matrix<Scalar, 15, 15> _result;


    _result(0, 0) = (Scalar(1)/Scalar(2))*_tmp0*_tmp1*x1 - _tmp10*_tmp8 - _tmp13*_tmp16 + _tmp3*_tmp5;
    _result(1, 0) = _tmp16*_tmp18;
    _result(2, 0) = _tmp16*_tmp20;
    _result(3, 0) = -_tmp23*_tmp8;
    _result(4, 0) = -_tmp26*_tmp8;
    _result(5, 0) = 0;
    _result(6, 0) = _tmp29*_tmp30;
    _result(7, 0) = _tmp30*_tmp31;
    _result(8, 0) = 0;
    _result(9, 0) = 0;
    _result(10, 0) = -Scalar(1)/Scalar(2)*_tmp32*_tmp33;
    _result(11, 0) = -Scalar(3)/Scalar(2)*_tmp33;
    _result(12, 0) = 0;
    _result(13, 0) = 0;
    _result(14, 0) = 0;
    _result(0, 1) = -_tmp13*_tmp34;
    _result(1, 1) = _tmp18*_tmp34 + _tmp21 + _tmp28 - _tmp37*_tmp41 - Scalar(1)/Scalar(2)*_tmp4*_tmp42*_tmp43*std::pow(x0, Scalar(2))*x2 + 8;
    _result(2, 1) = _tmp20*_tmp34;
    _result(3, 1) = -_tmp44*_tmp47;
    _result(4, 1) = 0;
    _result(5, 1) = _tmp47*_tmp49;
    _result(6, 1) = -_tmp41*_tmp51;
    _result(7, 1) = 0;
    _result(8, 1) = -_tmp41*_tmp53;
    _result(9, 1) = 0;
    _result(10, 1) = -_tmp50*_tmp55;
    _result(11, 1) = 0;
    _result(12, 1) = -_tmp55*_tmp57;
    _result(13, 1) = 0;
    _result(14, 1) = 0;
    _result(0, 2) = -_tmp13*_tmp59;
    _result(1, 2) = _tmp17*_tmp38*_tmp58;
    _result(2, 2) = 16*_tmp1 + _tmp20*_tmp59 - _tmp60*_tmp62 - _tmp65*_tmp66;
    _result(3, 2) = 0;
    _result(4, 2) = -_tmp48*_tmp61*_tmp67;
    _result(5, 2) = -_tmp62*_tmp68;
    _result(6, 2) = 0;
    _result(7, 2) = _tmp66*x0;
    _result(8, 2) = -_tmp66*_tmp69;
    _result(9, 2) = 0;
    _result(10, 2) = 0;
    _result(11, 2) = -8*_tmp14*_tmp70;
    _result(12, 2) = _tmp27*x2*x3;
    _result(13, 2) = 0;
    _result(14, 2) = 0;
    _result(0, 3) = -_tmp10*_tmp71;
    _result(1, 3) = _tmp73*_tmp75;
    _result(2, 3) = 0;
    _result(3, 3) = -_tmp23*_tmp71 + _tmp44*_tmp73 + _tmp76*_tmp77 - _tmp80*_tmp81;
    _result(4, 3) = -_tmp26*_tmp71;
    _result(5, 3) = -_tmp49*_tmp73;
    _result(6, 3) = _tmp77*_tmp83;
    _result(7, 3) = 0;
    _result(8, 3) = 0;
    _result(9, 3) = -_tmp77*_tmp84;
    _result(10, 3) = _tmp86*_tmp87;
    _result(11, 3) = 0;
    _result(12, 3) = 0;
    _result(13, 3) = -_tmp87*_tmp88;
    _result(14, 3) = 0;
    _result(0, 4) = _tmp10*_tmp89;
    _result(1, 4) = 0;
    _result(2, 4) = _tmp60*_tmp90;
    _result(3, 4) = _tmp23*_tmp89;
    _result(4, 4) = _tmp26*_tmp89 + _tmp27*[&]() { const Scalar base = x2; return base * base * base; }() - _tmp56*_tmp80 + _tmp90*_tmp91;
    _result(5, 4) = _tmp68*_tmp90;
    _result(6, 4) = 0;
    _result(7, 4) = -_tmp92*_tmp93;
    _result(8, 4) = 0;
    _result(9, 4) = _tmp93*_tmp94;
    _result(10, 4) = 0;
    _result(11, 4) = -_tmp6*_tmp95;
    _result(12, 4) = 0;
    _result(13, 4) = -_tmp97*_tmp98;
    _result(14, 4) = 0;
    _result(0, 5) = 0;
    _result(1, 5) = _tmp75*_tmp99;
    _result(2, 5) = -_tmp100*_tmp60;
    _result(3, 5) = _tmp44*_tmp99;
    _result(4, 5) = -_tmp100*_tmp91;
    _result(5, 5) = -_tmp100*_tmp68 + _tmp101*_tmp15 - _tmp49*_tmp99;
    _result(6, 5) = 0;
    _result(7, 5) = 0;
    _result(8, 5) = _tmp103*_tmp15;
    _result(9, 5) = -_tmp15*_tmp45;
    _result(10, 5) = 0;
    _result(11, 5) = 0;
    _result(12, 5) = 0;
    _result(13, 5) = 0;
    _result(14, 5) = 0;
    _result(0, 6) = _tmp104*_tmp2;
    _result(1, 6) = _tmp105*_tmp37;
    _result(2, 6) = 0;
    _result(3, 6) = _tmp106*_tmp76;
    _result(4, 6) = 0;
    _result(5, 6) = 0;
    _result(6, 6) = _tmp104*_tmp29 + _tmp105*_tmp51 + _tmp106*_tmp83 - _tmp107*_tmp111;
    _result(7, 6) = _tmp104*_tmp31;
    _result(8, 6) = _tmp105*_tmp53;
    _result(9, 6) = -_tmp106*_tmp84;
    _result(10, 6) = _tmp107*_tmp112;
    _result(11, 6) = 0;
    _result(12, 6) = 0;
    _result(13, 6) = 0;
    _result(14, 6) = _tmp107*_tmp113;
    _result(0, 7) = -_tmp18*_tmp3;
    _result(1, 7) = 0;
    _result(2, 7) = -_tmp114*_tmp65;
    _result(3, 7) = 0;
    _result(4, 7) = 0;
    _result(5, 7) = 0;
    _result(6, 7) = -_tmp115*_tmp29;
    _result(7, 7) = _tmp114*x0 - _tmp115*_tmp31 + _tmp116*_tmp117*_tmp118;
    _result(8, 7) = -_tmp114*_tmp69;
    _result(9, 7) = 0;
    _result(10, 7) = 0;
    _result(11, 7) = _tmp120*_tmp121;
    _result(12, 7) = 0;
    _result(13, 7) = 0;
    _result(14, 7) = -_tmp121*_tmp123*x1;
    _result(0, 8) = 0;
    _result(1, 8) = _tmp125*_tmp37;
    _result(2, 8) = -Scalar(2.0)*_tmp64 + Scalar(2.0)*x4;
    _result(3, 8) = 0;
    _result(4, 8) = 0;
    _result(5, 8) = _tmp101*_tmp85;
    _result(6, 8) = _tmp125*_tmp51;
    _result(7, 8) = Scalar(2.0)*x0;
    _result(8, 8) = _tmp103*_tmp85 + 4*_tmp124*_tmp52*x3 - _tmp126*_tmp128 - Scalar(2.0)*x2 + Scalar(2.0)*x3 + Scalar(-4.0);
    _result(9, 8) = -_tmp45*_tmp85;
    _result(10, 8) = 0;
    _result(11, 8) = 0;
    _result(12, 8) = _tmp126*_tmp129;
    _result(13, 8) = 0;
    _result(14, 8) = -_tmp102*_tmp126;
    _result(0, 9) = 0;
    _result(1, 9) = 0;
    _result(2, 9) = 0;
    _result(3, 9) = -_tmp130*_tmp76;
    _result(4, 9) = _tmp131*_tmp81;
    _result(5, 9) = _tmp101*x2;
    _result(6, 9) = -_tmp130*_tmp83;
    _result(7, 9) = -_tmp131*_tmp92;
    _result(8, 9) = _tmp103*x2;
    _result(9, 9) = _tmp130*_tmp84 + _tmp131*_tmp94 - _tmp46;
    _result(10, 9) = 0;
    _result(11, 9) = 0;
    _result(12, 9) = 0;
    _result(13, 9) = 0;
    _result(14, 9) = 0;
    _result(0, 10) = -_tmp122*_tmp132;
    _result(1, 10) = 0;
    _result(2, 10) = 0;
    _result(3, 10) = -_tmp14*_tmp60*_tmp79*_tmp82;
    _result(4, 10) = 0;
    _result(5, 10) = 0;
    _result(6, 10) = -_tmp109*_tmp133*_tmp134*_tmp42;
    _result(7, 10) = 0;
    _result(8, 10) = 0;
    _result(9, 10) = 0;
    _result(10, 10) = _tmp112*_tmp136 + _tmp132*_tmp32 + _tmp135*_tmp86;
    _result(11, 10) = 3*x0 + 3*x1 - 3*x4;
    _result(12, 10) = 0;
    _result(13, 10) = -_tmp135*_tmp88;
    _result(14, 10) = _tmp113*_tmp136;
    _result(0, 11) = -_tmp122*_tmp137;
    _result(1, 11) = 0;
    _result(2, 11) = -8*_tmp134;
    _result(3, 11) = 0;
    _result(4, 11) = _tmp139*_tmp87;
    _result(5, 11) = 0;
    _result(6, 11) = 0;
    _result(7, 11) = _tmp116*_tmp140;
    _result(8, 11) = 0;
    _result(9, 11) = 0;
    _result(10, 11) = _tmp137*_tmp32;
    _result(11, 11) = _tmp1*_tmp27*_tmp40*x0 + _tmp118*_tmp139 + _tmp119*_tmp140 + Scalar(6.0)*x3 + Scalar(-12.0);
    _result(12, 11) = -_tmp22*_tmp98;
    _result(13, 11) = _tmp0*_tmp139*_tmp97;
    _result(14, 11) = -_tmp123*_tmp140;
    _result(0, 12) = 0;
    _result(1, 12) = _tmp138 - 4;
    _result(2, 12) = _tmp141*_tmp28;
    _result(3, 12) = 0;
    _result(4, 12) = 0;
    _result(5, 12) = _tmp38*_tmp9;
    _result(6, 12) = 0;
    _result(7, 12) = 0;
    _result(8, 12) = _tmp128*_tmp142;
    _result(9, 12) = 0;
    _result(10, 12) = -_tmp143*_tmp50;
    _result(11, 12) = -_tmp141*_tmp70*_tmp72;
    _result(12, 12) = 2*_tmp102*x4 - _tmp129*_tmp142 + _tmp141*x1*x3 - _tmp143*_tmp57;
    _result(13, 12) = _tmp144*_tmp38;
    _result(14, 12) = _tmp102*_tmp142;
    _result(0, 13) = 0;
    _result(1, 13) = 0;
    _result(2, 13) = 0;
    _result(3, 13) = -_tmp14*_tmp145*_tmp38;
    _result(4, 13) = _tmp57*_tmp78;
    _result(5, 13) = -_tmp146*_tmp9;
    _result(6, 13) = 0;
    _result(7, 13) = 0;
    _result(8, 13) = 0;
    _result(9, 13) = _tmp147*_tmp148;
    _result(10, 13) = _tmp145*_tmp86;
    _result(11, 13) = _tmp22*_tmp6;
    _result(12, 13) = -_tmp102*_tmp146;
    _result(13, 13) = _tmp140*_tmp147 - _tmp144*_tmp146 - _tmp145*_tmp88 + _tmp82*_tmp97;
    _result(14, 13) = _tmp147*_tmp56;
    _result(0, 14) = 0;
    _result(1, 14) = 0;
    _result(2, 14) = 0;
    _result(3, 14) = 0;
    _result(4, 14) = 0;
    _result(5, 14) = 0;
    _result(6, 14) = _tmp111*_tmp149;
    _result(7, 14) = -_tmp116*x1;
    _result(8, 14) = -_tmp127*_tmp98*std::pow(x3, Scalar(4));
    _result(9, 14) = -_tmp11*_tmp148;
    _result(10, 14) = -_tmp112*_tmp149;
    _result(11, 14) = -_tmp120;
    _result(12, 14) = _tmp129*_tmp150;
    _result(13, 14) = -_tmp11*_tmp140;
    _result(14, 14) = -_tmp102*_tmp150 - _tmp113*_tmp149 - _tmp12*x1 + _tmp123*x1;

    return _result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
