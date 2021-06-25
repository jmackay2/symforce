//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <sym/pose2.h>

#include <lcmtypes/symforce/type_t.hpp>

namespace sym {
namespace pose2 {

/**
 * C++ StorageOps implementation for <class 'symforce.geo.pose2.Pose2'>.
 */
template <typename ScalarType>
struct StorageOps {
  using Scalar = typename sym::Pose2<ScalarType>::Scalar;

  static constexpr int32_t StorageDim() {
    return 4;
  }

  static void ToStorage(const sym::Pose2<ScalarType>& a, ScalarType* out);
  static sym::Pose2<ScalarType> FromStorage(const ScalarType* data);

  static symforce::type_t TypeEnum() {
    return symforce::type_t::POSE2;
  }
};

}  // namespace pose2

// Wrapper to specialize the public concept
template <>
struct StorageOps<Pose2<double>> : public pose2::StorageOps<double> {};
template <>
struct StorageOps<Pose2<float>> : public pose2::StorageOps<float> {};

}  // namespace sym
