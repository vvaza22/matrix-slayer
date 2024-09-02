#pragma once

namespace matrixslayer {

template <typename T>
class Store {
 public:
  virtual ~Store() = default;
  virtual T get(unsigned int row, unsigned int col) const = 0;
  virtual void set(unsigned int row, unsigned int col, T value) = 0;
  virtual T* ptr() = 0;
  virtual unsigned int getRows() = 0;
  virtual unsigned int getCols() = 0;
};

}  // namespace matrixslayer
