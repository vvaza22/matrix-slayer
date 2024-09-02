#pragma once

#include <store/Store.hpp>
#include <vector>

namespace matrixslayer {

  template <typename T>
  class ColumnMajorStore : public Store<T> {
  public:
    ColumnMajorStore(unsigned int r, unsigned int c);
    ColumnMajorStore(const ColumnMajorStore<T>& other);
    virtual T get(unsigned int row, unsigned int col) const override;
    virtual void set(unsigned int row, unsigned int col, T value) override;
    virtual T* ptr() override;
  private:
    unsigned int rows;
    unsigned int cols;
    std::vector<T> data;
  };

}
