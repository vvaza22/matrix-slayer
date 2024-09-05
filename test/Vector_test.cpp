#include <gtest/gtest.h>
#include <matrixslayer/Vector.hpp>

TEST(VectorTest, Initialization) {
  matrixslayer::Vector<int> v1({1, 2, 3});
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1.str(), "[1, 2, 3]");
  // EXPECT_EQ(v1.ptr(), &v1[0]);

  matrixslayer::Vector<float> v2({4.5, 6.7, 8.9});
  EXPECT_EQ(v2.size(), 3);
  EXPECT_EQ(v2.str(), "[4.5, 6.7, 8.9]");
  // EXPECT_EQ(v2.ptr(), &v2[0]);
}
