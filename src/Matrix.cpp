#include <Matrix.hpp>
#include <cassert>
#include <sstream>

namespace matrixslayer {

template <typename T>
Matrix<T>::Matrix(Store<T>* s, std::initializer_list<T> list) : store(s) {
  assert(list.size() <= store->getRows() * store->getCols());

  unsigned int index = 0;
  for (auto element : list) {
    store->set(index / store->getCols(), index % store->getCols(), element);
    index++;
  }
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) : store(other.store->clone()) {}

template <typename T>
Matrix<T>::~Matrix() {
  delete store;
}

/*
  When adding two matrices the resulting matrix has the same store type as the
  first matrix
 */
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m) const {
  assert(getRows() == m.getRows());
  assert(getCols() == m.getCols());

  Store<T>* result = store->clone();
  for (unsigned int row = 0; row < getRows(); row++) {
    for (unsigned int col = 0; col < getCols(); col++) {
      result->set(row, col, store->get(row, col) + m.store->get(row, col));
    }
  }

  return Matrix<T>(result, {});
}

/*
  When subtracting two matrices the resulting matrix has the same store type as
  the first matrix
 */
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m) const {
  assert(getRows() == m.getRows());
  assert(getCols() == m.getCols());

  Store<T>* result = store->clone();
  for (unsigned int row = 0; row < getRows(); row++) {
    for (unsigned int col = 0; col < getCols(); col++) {
      result->set(row, col, store->get(row, col) - m.store->get(row, col));
    }
  }

  return Matrix<T>(result, {});
}

template <typename T>
std::string Matrix<T>::str() const {
  std::ostringstream oss;

  for (unsigned int row = 0; row < getRows(); row++) {
    for (unsigned int col = 0; col < getCols(); col++) {
      oss << store->get(row, col) << " ";
    }
    oss << std::endl;
  }

  return oss.str();
}

// Explicit instantiations
template class Matrix<float>;
template class Matrix<double>;

}  // namespace matrixslayer
