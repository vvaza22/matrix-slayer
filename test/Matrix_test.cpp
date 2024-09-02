// clang-format off
#include <Matrix.hpp>
#include <store/ColumnMajorStore.hpp>

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

using namespace matrixslayer;

TEST(MatrixTest, Constructor) {
  Store<float>* store = new ColumnMajorStore<float>(1, 2);

  Matrix m(store, {});

  EXPECT_EQ(m.getRows(), 1);
  EXPECT_EQ(m.getCols(), 2);
}

TEST(MatrixTest, CopyConstructor) {
  Store<float>* store1 = new ColumnMajorStore<float>(2, 2);

  Matrix<float> m1(store1, {
    1.0f, 2.0f,
    3.0f, 4.0f
  });

  Matrix<float> m2(m1);

  EXPECT_EQ(m2.getRows(), 2);
  EXPECT_EQ(m2.getCols(), 2);

  std::ostringstream oss;
  oss << "1 2 " << std::endl;
  oss << "3 4 " << std::endl;

  EXPECT_EQ(m2.str(), oss.str());
  EXPECT_EQ(m2.str(), m1.str());
}

TEST(MatrixTest, ToString3x3) {
  Store<float>* store = new ColumnMajorStore<float>(3, 3);

  Matrix m(store,{
    1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f,
  });

  std::ostringstream oss;
  oss << "1 2 3 " << std::endl;
  oss << "4 5 6 " << std::endl;
  oss << "7 8 9 " << std::endl;

  EXPECT_EQ(m.str(), oss.str());
}

TEST(MatrixTest, ToString4x4) {
  Store<float>* store = new ColumnMajorStore<float>(4, 4);

  Matrix m(store, {
    1.0f,  2.0f,  3.0f,  4.0f,
		5.0f,  6.0f,  7.0f,  8.0f,
		9.0f,  10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f,
  });

  std::ostringstream oss;
  oss << "1 2 3 4 " << std::endl;
  oss << "5 6 7 8 " << std::endl;
  oss << "9 10 11 12 " << std::endl;
  oss << "13 14 15 16 " << std::endl;

  EXPECT_EQ(m.str(), oss.str());
}
