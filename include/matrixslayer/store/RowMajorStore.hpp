#pragma once

#include <matrixslayer/store/Store.hpp>
#include <stdexcept>
#include <vector>

namespace matrixslayer {

template <typename T>
class RowMajorStore : public Store<T> {
 public:
  RowMajorStore(unsigned int r, unsigned int c)
      : rows(r), cols(c), data(r * c){};

  RowMajorStore(const RowMajorStore<T>& other)
      : rows(other.rows), cols(other.cols), data(other.data){};

  T get(unsigned int row, unsigned int col) const override {
    if (row >= rows || col >= cols) {
      throw std::out_of_range("Index out of range");
    }
    return data[row * cols + col];
  }

  void set(unsigned int row, unsigned int col, T value) override {
    if (row >= rows || col >= cols) {
      throw std::out_of_range("Index out of range");
    }
    data[row * cols + col] = value;
  }

  T* ptr() override { return data.data(); }

  unsigned int getRows() override { return rows; }

  unsigned int getCols() override { return cols; }

  Store<T>* clone() override { return new RowMajorStore<T>(*this); }

  Store<T>* initialize(unsigned int r, unsigned int c) override {
    return new RowMajorStore<T>(r, c);
  }

 private:
  unsigned int rows;
  unsigned int cols;
  std::vector<T> data;
};

}  // namespace matrixslayer
