#include <gtest/gtest.h>
#include <matrixslayer/Vector.hpp>

TEST(VectorTest, Initialization) {
  matrixslayer::Vector<int> v1({1, 2, 3});
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1.str(), "[1, 2, 3]");

  const int* ptr1 = v1.ptr();
  EXPECT_EQ(ptr1[0], 1);
  EXPECT_EQ(ptr1[1], 2);
  EXPECT_EQ(ptr1[2], 3);

  matrixslayer::Vector<float> v2({4.5, 6.7, 8.9, 10.3});
  EXPECT_EQ(v2.size(), 4);
  EXPECT_EQ(v2.str(), "[4.5, 6.7, 8.9, 10.3]");

  const float* ptr2 = v2.ptr();
  EXPECT_EQ(ptr2[0], 4.5f);
  EXPECT_EQ(ptr2[1], 6.7f);
  EXPECT_EQ(ptr2[2], 8.9f);
  EXPECT_EQ(ptr2[3], 10.3f);
}

TEST(VectorTest, CopyConstructor) {
  matrixslayer::Vector<int> v1({1, 2, 3});
  matrixslayer::Vector<int> v2(v1);

  EXPECT_EQ(v2.size(), v1.size());
  EXPECT_EQ(v2.str(), v1.str());
  EXPECT_NE(v2.ptr(), v1.ptr());
}

TEST(VectorTest, CopyConstructor_Float) {
  matrixslayer::Vector<float> v1({4.5, 6.7, 8.9});
  matrixslayer::Vector<float> v2(v1);

  EXPECT_EQ(v2.size(), v1.size());
  EXPECT_EQ(v2.str(), v1.str());
  EXPECT_NE(v2.ptr(), v1.ptr());
}

TEST(VectorTest, Addition) {
  matrixslayer::Vector<int> v1({1, 2, 3});
  matrixslayer::Vector<int> v2({4, 5, 6});

  matrixslayer::Vector<int> sum = v1 + v2;
  EXPECT_EQ(sum.size(), v1.size());
  EXPECT_EQ(sum.str(), "[5, 7, 9]");
}

TEST(VectorTest, Subtraction) {
  matrixslayer::Vector<int> v1({1, 2, 3});
  matrixslayer::Vector<int> v2({4, 10, 0});

  matrixslayer::Vector<int> diff = v2 - v1;
  EXPECT_EQ(diff.size(), v2.size());
  EXPECT_EQ(diff.str(), "[3, 8, -3]");
}

TEST(VectorTest, MultiplicationByScalar) {
  matrixslayer::Vector<int> v1({1, 2, 3});
  int scalar = 2;

  matrixslayer::Vector<int> result = v1 * scalar;
  EXPECT_EQ(result.size(), v1.size());
  EXPECT_EQ(result.str(), "[2, 4, 6]");
}

TEST(VectorTest, DivisionByScalar) {
  matrixslayer::Vector<int> v1({4, 6, 8});
  int scalar = 2;

  matrixslayer::Vector<int> result = v1 / scalar;
  EXPECT_EQ(result.size(), v1.size());
  EXPECT_EQ(result.str(), "[2, 3, 4]");
}

TEST(VectorTest, DivisionByScalar_Float) {
  matrixslayer::Vector<float> v1({4.5, 6.7, 8.9});
  float scalar = 2.5;

  matrixslayer::Vector<float> result = v1 / scalar;
  EXPECT_EQ(result.size(), v1.size());
  EXPECT_EQ(result.str(), "[1.8, 2.68, 3.56]");
}

TEST(VectorTest, DotProduct) {
  matrixslayer::Vector<int> v1({1, 2, 3});
  matrixslayer::Vector<int> v2({4, 5, 6});

  int dotProduct = v1 * v2;
  EXPECT_EQ(dotProduct, 32);
}

TEST(VectorTest, DotProduct_Float) {
  matrixslayer::Vector<float> v1({1.5, 2.5, 3.5});
  matrixslayer::Vector<float> v2({4.5, 5.5, 6.5});

  float dotProduct = v1 * v2;
  EXPECT_FLOAT_EQ(dotProduct, 43.25);
}

TEST(VectorTest, DotProduct_Zero) {
  matrixslayer::Vector<int> v1({1, 2, 3});
  matrixslayer::Vector<int> v2({0, 0, 0});

  int dotProduct = v1 * v2;
  EXPECT_EQ(dotProduct, 0);
}

TEST(VectorTest, AssignmentOperator) {
  matrixslayer::Vector<int> v1({1, 2, 3});
  matrixslayer::Vector<int> v2({4, 5, 6});

  v2 = v1;

  EXPECT_EQ(v2.size(), v1.size());
  EXPECT_EQ(v2.str(), v1.str());
  EXPECT_NE(v2.ptr(), v1.ptr());
}

TEST(VectorTest, AssignmentOperator_Float) {
  matrixslayer::Vector<float> v1({4.5, 6.7, 8.9});
  matrixslayer::Vector<float> v2({1.2, 3.4, 5.6});

  v2 = v1;

  EXPECT_EQ(v2.size(), v1.size());
  EXPECT_EQ(v2.str(), v1.str());
  EXPECT_NE(v2.ptr(), v1.ptr());
}
