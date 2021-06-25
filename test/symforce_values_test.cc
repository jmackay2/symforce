#include <iostream>
#include <stdint.h>
#include <sys/time.h>

#include <sym/rot3.h>

#include "../symforce/opt/values.h"
#include "catch.hpp"

TEMPLATE_TEST_CASE("Test values", "[values]", double, float) {
  using Scalar = TestType;

  std::cout << "*** Testing Values<" << typeid(Scalar).name() << "> ***" << std::endl;
  const Scalar epsilon = 1e-9;

  sym::Values<Scalar> v;
  CHECK(v.Keys().size() == 0);
  CHECK(v.NumEntries() == 0);
  CHECK(v.Items().size() == 0);
  CHECK(v.Data().size() == 0);
  CHECK(!v.Has(sym::Key()));
  CHECK(!v.Has(sym::Key('F', -1, 3)));

  // Add a key
  sym::Key R1_key('R', 1);
  sym::Rot3<Scalar> R1 = sym::Rot3<Scalar>::FromYawPitchRoll(0.5, -0.2, 0.1);
  const bool is_new = v.Set(R1_key, R1);
  CHECK(is_new);
  CHECK(v.NumEntries() == 1);
  CHECK(v.Keys().size() == 1);
  CHECK(v.Items().size() == 1);
  CHECK(v.Data().size() == R1.StorageDim());
  CHECK(v.Has(R1_key));
  sym::Rot3<Scalar> R1_fetch = v.template At<sym::Rot3<Scalar>>(R1_key);
  CHECK(R1 == R1_fetch);

  // Add a second
  sym::Key z1_key = sym::Key('z', 1);
  Scalar s = 2.0;
  v.Set(z1_key, s);
  CHECK(v.NumEntries() == 2);
  CHECK(v.Data().size() == R1.StorageDim() + 1);
  CHECK(v.Has(z1_key));
  CHECK(v.Has(R1_key));
  CHECK(s == v.template At<Scalar>(z1_key));

  // Modify a key
  const sym::Rot3<Scalar> R1_new = sym::Rot3<Scalar>::FromTangent({1.2, 0.2, 0.0});
  const bool is_new2 = v.Set(R1_key, R1_new);
  CHECK_FALSE(is_new2);
  CHECK(v.NumEntries() == 2);
  CHECK(v.Data().size() == R1.StorageDim() + 1);
  CHECK(R1_new == v.template At<sym::Rot3<Scalar>>(R1_key));

  // Remove nothing
  bool remove_nothing = v.Remove(sym::Key('f'));
  CHECK_FALSE(remove_nothing);

  // Remove z1
  bool remove_z1 = v.Remove(z1_key);
  CHECK(remove_z1);
  CHECK(v.NumEntries() == 1);
  CHECK(v.Data().size() == R1.StorageDim() + 1);
  CHECK_FALSE(v.Has(z1_key));

  // Add some more
  v.Set(sym::Key('f', 1), Scalar(4.2));
  v.Set(sym::Key('f', 2), Scalar(4.3));
  v.Set(sym::Key('d', 1), Scalar(4.3));
  v.Set(sym::Key('v', 1), Eigen::Matrix<Scalar, 1, 1>(0.0));
  v.Set(sym::Key('v', 3), Eigen::Matrix<Scalar, 3, 1>(1.0, 2.0, 3.0));
  v.template Set<Eigen::Matrix<Scalar, 9, 1>>(sym::Key('v', 9),
                                              Eigen::Matrix<Scalar, 9, 1>::Constant(1.2));

  // Right now since we removed a scalar the data array is one longer than the actual storage dim
  CHECK(v.NumEntries() == 7);
  const sym::index_t index_1 = v.CreateIndex(v.Keys());
  CHECK(v.Data().size() == index_1.storage_dim + 1);
  CHECK(index_1.tangent_dim == index_1.storage_dim - 1);

  // Cleanup to get rid of the empty space from the scalar
  size_t num_cleaned = v.Cleanup();
  CHECK(v.NumEntries() == 7);
  CHECK(v.Data().size() == index_1.storage_dim);
  const sym::index_t index_2 = v.CreateIndex(v.Keys());
  CHECK(R1_new == v.template At<sym::Rot3<Scalar>>(R1_key));
  CHECK(Scalar(4.2) == v.template At<Scalar>({'f', 1}));
  CHECK(index_2.storage_dim == index_1.storage_dim);
  CHECK(index_2.tangent_dim == index_1.tangent_dim);

  // Test lookups
  const sym::index_entry_t& f2_entry = index_1.entries[1];
  CHECK(v.template At<Scalar>(f2_entry) == v.template At<Scalar>(sym::Key('f', 2)));
  v.Set(f2_entry, Scalar(15.6));
  CHECK(v.template At<Scalar>(sym::Key('f', 2)) == Scalar(15.6));

  // Pack to LCM
  const typename sym::Values<Scalar>::LcmType msg = v.GetLcmType();
  CHECK(msg.index == index_2);
  CHECK(msg.data.size() == v.Data().size());

  // Recreate another
  sym::Values<Scalar> v2(msg);
  CHECK(v2.NumEntries() == v.NumEntries());
  CHECK(v2.Data() == v.Data());
  assert(v.CreateIndex(v.Keys()) == v2.CreateIndex(v2.Keys()));

  // Print
  std::cout << "v: " << v << std::endl;

  // Clear
  v.RemoveAll();
  CHECK(v.NumEntries() == 0);
  CHECK(v.Data().size() == 0);
}

TEST_CASE("Test implicit construction", "[values]") {
  std::cout << "*** Testing Values Implicit Construction ***" << std::endl;

  sym::Valuesd values;
  values.Set<double>('x', 1.0);
  values.Set<double>('y', 2.0);
  values.Set<double>('z', -3.0);
  values.Set<sym::Rot3d>({'R', 1}, sym::Rot3d::Identity());
  values.Set<sym::Rot3d>({'R', 2}, sym::Rot3d::FromYawPitchRoll(1.0, 0.0, 0.0));
  values.Set<sym::Pose3d>('P', sym::Pose3d::Identity());
  std::cout << values << std::endl;
}

TEST_CASE("Test initializer list construction", "[values]") {
  std::cout << "*** Testing Values Initializer List Construction ***" << std::endl;

  sym::Valuesd v1;
  v1.Set<double>('x', 1.0);
  v1.Set<double>('y', 2.0);
  v1.Set<double>('z', -3.0);

  sym::Valuesd v2;
  v2.Set<sym::Rot3d>('R', sym::Rot3d::Identity());

  // construct v3 by merging v1 and v2
  sym::Valuesd v3({v1, v2});

  // test data
  CHECK(v3.At<double>('x') == 1.0);
  CHECK(v3.At<double>('y') == 2.0);
  CHECK(v3.At<double>('z') == -3.0);
  CHECK(v3.At<sym::Rot3d>('R') == sym::Rot3d::Identity());

  // test preserving key ordering
  const auto v3_keys = v3.Keys();
  CHECK(v3_keys[0] == 'x');
  CHECK(v3_keys[1] == 'y');
  CHECK(v3_keys[2] == 'z');
  CHECK(v3_keys[3] == 'R');
}

TEST_CASE("Test indexed update", "[values]") {
  std::cout << "*** Testing Values Indexed Update ***" << std::endl;

  // Create some data
  sym::Valuesd values;
  values.Set<double>('x', 1.0);
  values.Set<double>('y', 2.0);
  values.Set<double>('z', -3.0);
  values.Set<sym::Rot3d>({'R', 1}, sym::Rot3d::Identity());
  values.Set<sym::Rot3d>({'R', 2}, sym::Rot3d::FromYawPitchRoll(1.0, 0.0, 0.0));
  values.Set<sym::Pose3d>('P', sym::Pose3d::Identity());

  // Create an index for a subset of keys
  const sym::index_t index = values.CreateIndex({'x', 'y', {'R', 1}});

  // Copy into another Values
  sym::Valuesd values2 = values;

  // Modify some keys in the original
  values.Set<double>('x', 7.7);
  values.Set<sym::Rot3d>({'R', 1}, values.At<sym::Rot3d>({'R', 2}));

  CHECK(values.At<double>('x') == 7.7);
  CHECK(values2.At<double>('x') == 1.0);

  // Efficiently update keys into the new values
  values2.Update(index, values);

  CHECK(values2.At<double>('x') == 7.7);
}

TEST_CASE("Test key update", "[values]") {
  std::cout << "*** Testing Values Key Update ***" << std::endl;

  // Create some data
  sym::Valuesd values;
  values.Set<double>('x', 1.0);
  values.Set<double>('y', 2.0);
  values.Set<double>('z', -3.0);
  values.Set<sym::Rot3d>({'R', 1}, sym::Rot3d::Identity());
  values.Set<sym::Rot3d>({'R', 2}, sym::Rot3d::FromYawPitchRoll(1.0, 0.0, 0.0));
  values.Set<sym::Pose3d>('P', sym::Pose3d::Identity());

  // Create an index for a subset of keys (random order should be supported)
  const std::vector<sym::Key> keys = {{'R', 1}, 'x', 'y'};
  const sym::index_t index = values.CreateIndex(keys);

  // Another different structured Values
  sym::Valuesd values2;
  values2.Set<double>('z', 10.0);

  // Update from a different structure
  values2.UpdateOrSet(index, values);

  // Test for update
  CHECK(values2.At<double>('x') == 1.0);
  CHECK(values2.At<double>('y') == 2.0);
  CHECK(values2.At<sym::Rot3d>({'R', 1}) == sym::Rot3d::Identity());

  // Test for not clobbering other field
  CHECK(values2.At<double>('z') == 10.0);

  // Test efficient update with cached index
  const sym::index_t index2 = values2.CreateIndex(keys);
  values.Set<double>('x', -10.0);
  values.Set<double>('y', 20.0);
  values2.Update(index2, index, values);
  CHECK(values2.At<double>('x') == -10.0);
  CHECK(values2.At<double>('y') == 20.0);
}

TEMPLATE_TEST_CASE("Test lie group ops", "[values]", double, float) {
  using Scalar = TestType;

  std::cout << "*** Testing Values<" << typeid(Scalar).name() << "> LieGroupOps ***" << std::endl;
  const Scalar epsilon = 1e-9;

  // Create a values object that stores an identity rotation, and an index for it
  sym::Values<Scalar> v1;
  const sym::Rot3<Scalar> rot = sym::Rot3<Scalar>::Identity();
  v1.Set('R', rot);
  const sym::index_t index = v1.CreateIndex({'R'});

  // Test a bunch of retractions and local coordinates
  std::mt19937 gen(42);
  for (int i = 0; i < 100; ++i) {
    v1.Set('R', rot);
    const sym::Values<Scalar> v2 = v1;

    const sym::Rot3<Scalar> random_rot = sym::Rot3<Scalar>::Random(gen);
    const Eigen::Matrix<Scalar, 3, 1> tangent_vec =
        sym::LieGroupOps<sym::Rot3<Scalar>>::ToTangent(random_rot, epsilon);

    // test retraction
    v1.Retract(index, tangent_vec.data(), epsilon);
    const sym::Rot3<Scalar> retracted_rot = v1.template At<sym::Rot3<Scalar>>('R');
    CHECK(random_rot.IsApprox(retracted_rot, 1e-6));

    // test local coordinates
    const sym::VectorX<Scalar> local_coords = v1.LocalCoordinates(v2, index, epsilon);
    CHECK(local_coords.isApprox(tangent_vec));
  }
}

TEST_CASE("Test move operator", "[values]") {
  static_assert(std::is_move_assignable<sym::Values<float>>::value, "");
  sym::Valuesf values;
  values.Set<float>('x', 1.0f);
  values.Set<float>('y', 2.0f);
  values.Set<sym::Rot3f>({'R', 1}, sym::Rot3f::Identity());
  sym::Valuesf values2 = std::move(values);
  CHECK(values2.At<float>('x') == 1.0f);
}

TEST_CASE("Test Set with Eigen expressions", "[values]") {
  sym::Valuesd values;
  values.Set('a', Eigen::Vector3d::Zero());
  values.Set('b', Eigen::Vector3f::Zero().cast<double>());
  values.Set('c', Eigen::Vector3d() + 2 * Eigen::Vector3d::Ones());
  values.Set('d', Eigen::Vector3d(Eigen::Vector3d::Zero()));
  values.Set('e', sym::Rot3d::FromAngleAxis(1, Eigen::Vector3d::Ones()).ToRotationMatrix());
  CHECK(values.At<Eigen::Vector3d>('a') == Eigen::Vector3d::Zero());
  CHECK(values.At<Eigen::Vector3d>('b') == Eigen::Vector3d::Zero());
  CHECK(values.At<Eigen::Vector3d>('c') == Eigen::Vector3d::Constant(2));
  CHECK(values.At<Eigen::Vector3d>('d') == Eigen::Vector3d::Zero());
  CHECK(values.At<Eigen::Matrix3d>('e') ==
        sym::Rot3d::FromAngleAxis(1, Eigen::Vector3d::Ones()).ToRotationMatrix());

  sym::index_t index = values.CreateIndex({'a', 'b', 'c', 'd', 'e'});
  values.Set(index.entries[4],
             sym::Rot3d::FromAngleAxis(0.3, Eigen::Vector3d::Ones()).ToRotationMatrix());
  values.Set(index.entries[3], Eigen::Vector3d::Zero());
  values.Set(index.entries[2], Eigen::Vector3f::Zero().cast<double>());
  values.Set(index.entries[1], Eigen::Vector3d::Zero() + 2 * Eigen::Vector3d::Ones());
  values.Set(index.entries[0], Eigen::Vector3d(Eigen::Vector3d::Zero()));
  CHECK(values.At<Eigen::Matrix3d>('e') ==
        sym::Rot3d::FromAngleAxis(0.3, Eigen::Vector3d::Ones()).ToRotationMatrix());
  CHECK(values.At<Eigen::Vector3d>('d') == Eigen::Vector3d::Zero());
  CHECK(values.At<Eigen::Vector3d>('c') == Eigen::Vector3d::Zero());
  CHECK(values.At<Eigen::Vector3d>('b') == Eigen::Vector3d::Constant(2));
  CHECK(values.At<Eigen::Vector3d>('a') == Eigen::Vector3d::Zero());
}
