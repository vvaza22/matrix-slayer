// clang-format off
#include <matrixslayer/MatrixFactory.hpp>

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

using namespace matrixslayer;

TEST(MatrixFactoryTest, Mat3) {
  Mat m = Matrix3f({
    1.0f, 2.0f, 3.0f,
    4.0f, 5.0f, 6.0f,
    7.0f, 8.0f, 9.0f,
  });

  EXPECT_EQ(m.getRows(), 3);
  EXPECT_EQ(m.getCols(), 3);

  std::ostringstream oss;
  oss << "1 2 3 " << std::endl;
  oss << "4 5 6 " << std::endl;
  oss << "7 8 9 " << std::endl;

  EXPECT_EQ(m.str(), oss.str());
}

TEST(MatrixFactoryTest, Mat4) {
  Mat m = Matrix4f({
    1.0f,  2.0f,  3.0f,  4.0f,
    5.0f,  6.0f,  7.0f,  8.0f,
    9.0f,  10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f,
  });

  EXPECT_EQ(m.getRows(), 4);
  EXPECT_EQ(m.getCols(), 4);

  std::ostringstream oss;
  oss << "1 2 3 4 " << std::endl;
  oss << "5 6 7 8 " << std::endl;
  oss << "9 10 11 12 " << std::endl;
  oss << "13 14 15 16 " << std::endl;

  EXPECT_EQ(m.str(), oss.str());
}

TEST(MatrixFactoryTest, Mad3) {
  Mad m = Matrix3d({
    1.0, 2.0, 3.0,
    4.0, 5.0, 6.0,
    7.0, 8.0, 9.0,
  });

  EXPECT_EQ(m.getRows(), 3);
  EXPECT_EQ(m.getCols(), 3);

  std::ostringstream oss;
  oss << "1 2 3 " << std::endl;
  oss << "4 5 6 " << std::endl;
  oss << "7 8 9 " << std::endl;

  EXPECT_EQ(m.str(), oss.str());
}

TEST(MatrixFactoryTest, Mad4) {
  Mad m = Matrix4d({
    1.0,  2.0,  3.0,  4.0,
    5.0,  6.0,  7.0,  8.0,
    9.0,  10.0, 11.0, 12.0,
    13.0, 14.0, 15.0, 16.0,
  });

  EXPECT_EQ(m.getRows(), 4);
  EXPECT_EQ(m.getCols(), 4);

  std::ostringstream oss;
  oss << "1 2 3 4 " << std::endl;
  oss << "5 6 7 8 " << std::endl;
  oss << "9 10 11 12 " << std::endl;
  oss << "13 14 15 16 " << std::endl;

  EXPECT_EQ(m.str(), oss.str());
}
