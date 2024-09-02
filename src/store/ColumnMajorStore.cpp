#include <store/ColumnMajorStore.hpp>
#include <vector>
#include <stdexcept>

namespace matrixslayer {

  template <typename T>
  ColumnMajorStore<T>::ColumnMajorStore(unsigned int r, unsigned int c) : rows(r), cols(c), data(r * c) {}

  // Copy constructor
  template <typename T>
  ColumnMajorStore<T>::ColumnMajorStore(const ColumnMajorStore<T>& other) : rows(other.rows), cols(other.cols), data(other.data) {}

  template <typename T>
  T ColumnMajorStore<T>::get(unsigned int row, unsigned int col) const {
    if (row >= rows || col >= cols) {
      throw std::out_of_range("Index out of range");
    }
    return data[col * rows + row];
  }

  template <typename T>
  void ColumnMajorStore<T>::set(unsigned int row, unsigned int col, T value) {
    if (row >= rows || col >= cols) {
      throw std::out_of_range("Index out of range");
    }
    data[col * rows + row] = value;
  }

  template <typename T>
  T* ColumnMajorStore<T>::ptr() {
    return data.data();
  }

  // Explicit instantiations
  template class ColumnMajorStore<float>;
  template class ColumnMajorStore<double>;
}
