#include <gtest/gtest.h>
#include <stdexcept>
#include <store/RowMajorStore.hpp>

using namespace matrixslayer;

TEST(RowMajorStoreTest, Constructor) {
  RowMajorStore<float> store(2, 3);

  EXPECT_EQ(store.getRows(), 2);
  EXPECT_EQ(store.getCols(), 3);
}

TEST(RowMajorStoreTest, SetAndGet) {
  int rows = 3;
  int cols = 3;
  RowMajorStore<float> store(rows, cols);

  // Default value should be 0.0f
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      EXPECT_EQ(store.get(row, col), 0.0f);
    }
  }

  // Set values
  store.set(0, 0, 1.0f);
  store.set(0, 1, 2.0f);
  store.set(0, 2, 3.0f);
  store.set(1, 0, 4.0f);
  store.set(1, 1, 5.0f);
  store.set(1, 2, 6.0f);
  store.set(2, 0, 7.0f);
  store.set(2, 1, 8.0f);
  store.set(2, 2, 9.0f);

  // Get values
  EXPECT_EQ(store.get(0, 0), 1.0f);
  EXPECT_EQ(store.get(0, 1), 2.0f);
  EXPECT_EQ(store.get(0, 2), 3.0f);
  EXPECT_EQ(store.get(1, 0), 4.0f);
  EXPECT_EQ(store.get(1, 1), 5.0f);
  EXPECT_EQ(store.get(1, 2), 6.0f);
  EXPECT_EQ(store.get(2, 0), 7.0f);
  EXPECT_EQ(store.get(2, 1), 8.0f);
  EXPECT_EQ(store.get(2, 2), 9.0f);
}

TEST(RowMajorStoreTest, OutOfRange) {
  RowMajorStore<float> store(3, 3);

  EXPECT_THROW(store.get(3, 0), std::out_of_range);
  EXPECT_THROW(store.get(0, 3), std::out_of_range);
  EXPECT_THROW(store.set(3, 0, 0.0f), std::out_of_range);
  EXPECT_THROW(store.set(0, 3, 0.0f), std::out_of_range);
}

TEST(RowMajorStoreTest, CopyConstructor) {
  RowMajorStore<double> store1(2, 2);

  // Set values
  store1.set(0, 0, 1.0);
  store1.set(0, 1, 2.0);
  store1.set(1, 0, 3.0);
  store1.set(1, 1, 4.0);

  RowMajorStore<double> store2(store1);

  // Get values
  EXPECT_EQ(store2.get(0, 0), 1.0);
  EXPECT_EQ(store2.get(0, 1), 2.0);
  EXPECT_EQ(store2.get(1, 0), 3.0);
  EXPECT_EQ(store2.get(1, 1), 4.0);
}

TEST(RowMajorStoreTest, RowMajorOrder1) {
  RowMajorStore<float> store(3, 3);

  // Set values
  store.set(0, 0, 1.0f);
  store.set(0, 1, 2.0f);
  store.set(0, 2, 3.0f);
  store.set(1, 0, 4.0f);
  store.set(1, 1, 5.0f);
  store.set(1, 2, 6.0f);
  store.set(2, 0, 7.0f);
  store.set(2, 1, 8.0f);
  store.set(2, 2, 9.0f);

  const float *ptr = store.ptr();

  EXPECT_EQ(ptr[0], 1.0f);
  EXPECT_EQ(ptr[1], 2.0f);
  EXPECT_EQ(ptr[2], 3.0f);
  EXPECT_EQ(ptr[3], 4.0f);
  EXPECT_EQ(ptr[4], 5.0f);
  EXPECT_EQ(ptr[5], 6.0f);
  EXPECT_EQ(ptr[6], 7.0f);
  EXPECT_EQ(ptr[7], 8.0f);
  EXPECT_EQ(ptr[8], 9.0f);
}

TEST(RowMajorStoreTest, ColumnMajorOrder2) {
  RowMajorStore<float> store(3, 4);

  store.set(0, 0, 1.0f);
  store.set(0, 1, 2.0f);
  store.set(0, 2, 3.0f);
  store.set(0, 3, 4.0f);
  store.set(1, 0, 5.0f);
  store.set(1, 1, 6.0f);
  store.set(1, 2, 7.0f);
  store.set(1, 3, 8.0f);
  store.set(2, 0, 9.0f);
  store.set(2, 1, 10.0f);
  store.set(2, 2, 11.0f);
  store.set(2, 3, 12.0f);

  const float *ptr = store.ptr();

  EXPECT_EQ(ptr[0], 1.0f);
  EXPECT_EQ(ptr[1], 2.0f);
  EXPECT_EQ(ptr[2], 3.0f);
  EXPECT_EQ(ptr[3], 4.0f);
  EXPECT_EQ(ptr[4], 5.0f);
  EXPECT_EQ(ptr[5], 6.0f);
  EXPECT_EQ(ptr[6], 7.0f);
  EXPECT_EQ(ptr[7], 8.0f);
  EXPECT_EQ(ptr[8], 9.0f);
  EXPECT_EQ(ptr[9], 10.0f);
  EXPECT_EQ(ptr[10], 11.0f);
  EXPECT_EQ(ptr[11], 12.0f);
}
