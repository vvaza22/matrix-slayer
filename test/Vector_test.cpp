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
