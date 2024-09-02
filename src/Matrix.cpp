#include <Matrix.hpp>
#include <cassert>
#include <sstream>

namespace matrixslayer {

template <typename T>
Matrix<T>::Matrix(Store<T>* s, std::initializer_list<T> list) : store(s) {
  unsigned int index = 0;
  for (auto element : list) {
    store->set(index / store->getCols(), index % store->getCols(), element);
    index++;
  }
}

template <typename T>
Matrix<T>::~Matrix() {
  delete store;
}

template <typename T>
std::string Matrix<T>::str() const {
  std::ostringstream oss;

  for (unsigned int row = 0; row < store->getRows(); row++) {
    for (unsigned int col = 0; col < store->getCols(); col++) {
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
