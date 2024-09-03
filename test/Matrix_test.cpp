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

TEST(MatrixTest, Addition) {
  Store<float>* store1 = new ColumnMajorStore<float>(2, 2);
  Store<float>* store2 = new ColumnMajorStore<float>(2, 2);

  Matrix<float> m1(store1, {
    1.0f, 2.0f,
    3.0f, 4.0f
  });

  Matrix<float> m2(store2, {
    5.0f, 6.0f,
    7.0f, 8.0f
  });

  Matrix<float> result = m1 + m2;

  std::ostringstream oss;
  oss << "6 8 " << std::endl;
  oss << "10 12 " << std::endl;

  EXPECT_EQ(result.getRows(), 2);
  EXPECT_EQ(result.getCols(), 2);
  EXPECT_EQ(result.str(), oss.str());
}

TEST(MatrixTest, Subtraction) {
  Store<float>* store1 = new ColumnMajorStore<float>(3, 2);
  Store<float>* store2 = new ColumnMajorStore<float>(3, 2);

  Matrix<float> m1(store1, {
    1.0f, 2.0f,
    3.0f, 4.0f,
    5.0f, 6.0f
  });

  Matrix<float> m2(store2, {
    7.0f, 8.0f,
    9.0f, 10.0f,
    11.0f, 12.0f
  });

  Matrix<float> result = m1 - m2;

  std::ostringstream oss;
  oss << "-6 -6 " << std::endl;
  oss << "-6 -6 " << std::endl;
  oss << "-6 -6 " << std::endl;

  EXPECT_EQ(result.getRows(), 3);
  EXPECT_EQ(result.getCols(), 2);
  EXPECT_EQ(result.str(), oss.str());
}

TEST(MatrixTest, ScalarMultiplication) {
  Store<float>* store = new ColumnMajorStore<float>(3, 2);

  Matrix<float> m(store, {
    1.0f, 2.0f,
    3.0f, 4.0f,
    5.0f, 6.0f
  });

  float scalar = 3.0f;

  Matrix<float> result = m * scalar;

  std::ostringstream oss;
  oss << "3 6 " << std::endl;
  oss << "9 12 " << std::endl;
  oss << "15 18 " << std::endl;

  EXPECT_EQ(result.getRows(), 3);
  EXPECT_EQ(result.getCols(), 2);
  EXPECT_EQ(result.str(), oss.str());
}

TEST(MatrixTest, ScalarDivision) {
  Store<float>* store = new ColumnMajorStore<float>(2, 4);

  Matrix<float> m(store, {
    1.0f, 2.0f, 3.0f, 4.0f,
    5.0f, 6.0f, 7.0f, 8.0f
  });

  float scalar = 2.0f;

  Matrix<float> result = m / scalar;

  std::ostringstream oss;
  oss << "0.5 1 1.5 2 " << std::endl;
  oss << "2.5 3 3.5 4 " << std::endl;

  EXPECT_EQ(result.getRows(), 2);
  EXPECT_EQ(result.getCols(), 4);
  EXPECT_EQ(result.str(), oss.str());
}

TEST(MatrixTest, MatrixMultiplication1) {
  Store<float>* store1 = new ColumnMajorStore<float>(2, 3);
  Store<float>* store2 = new ColumnMajorStore<float>(3, 4);

  Matrix<float> m1(store1, {
    1.0f, 2.0f, 3.0f,
    4.0f, 5.0f, 6.0f
  });

  Matrix<float> m2(store2, {
    7.0f, 8.0f, 9.0f, 10.0f,
    11.0f, 12.0f, 13.0f, 14.0f,
    15.0f, 16.0f, 17.0f, 18.0f
  });

  Matrix<float> result = m1 * m2;

  std::ostringstream oss;
  oss << "74 80 86 92 " << std::endl;
  oss << "173 188 203 218 " << std::endl;

  EXPECT_EQ(result.getRows(), 2);
  EXPECT_EQ(result.getCols(), 4);
  EXPECT_EQ(result.str(), oss.str());
}

TEST(MatrixTest, MatrixMultiplication2) {
  Store<float>* store1 = new ColumnMajorStore<float>(4, 4);
  Store<float>* store2 = new ColumnMajorStore<float>(4, 4);

  Matrix<float> m1(store1, {
    1.0f, 2.0f, 3.0f, 4.0f,
    5.0f, 6.0f, 7.0f, 8.0f,
    9.0f, 10.0f, 11.0f, 12.0f,
    13.0f, 14.0f, 15.0f, 16.0f
  });

  Matrix<float> m2(store2, {
    17.0f, 18.0f, 19.0f, 20.0f,
    21.0f, 22.0f, 23.0f, 24.0f,
    25.0f, 26.0f, 27.0f, 28.0f,
    29.0f, 30.0f, 31.0f, 32.0f
  });

  Matrix<float> result = m1 * m2;

  std::ostringstream oss;
  oss << "250 260 270 280 " << std::endl;
  oss << "618 644 670 696 " << std::endl;
  oss << "986 1028 1070 1112 " << std::endl;
  oss << "1354 1412 1470 1528 " << std::endl;

  EXPECT_EQ(result.getRows(), 4);
  EXPECT_EQ(result.getCols(), 4);
  EXPECT_EQ(result.str(), oss.str());
}
