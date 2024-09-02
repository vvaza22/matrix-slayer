// clang-format off
#include <Matrix.hpp>
#include <store/ColumnMajorStore.hpp>

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

using namespace matrixslayer;

TEST(MatrixTest, TestToString3x3) {
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

TEST(MatrixTest, TestToString4x4) {
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
