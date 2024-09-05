#include <matrixslayer/Vector.hpp>

#include <sstream>

namespace matrixslayer {

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) : data(list) {}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) : data(other.data) {}

template <typename T>
unsigned long int Vector<T>::size() const {
  return data.size();
}

template <typename T>
std::string Vector<T>::str() const {
  std::ostringstream oss;
  oss << "[";
  for (unsigned int i = 0; i < data.size(); i++) {
    oss << data[i];
    if (i < data.size() - 1) {
      oss << ", ";
    }
  }
  oss << "]";
  return oss.str();
}

template <typename T>
const T* Vector<T>::ptr() const {
  return data.data();
}

// Explicit instantiation
template class Vector<int>;
template class Vector<float>;
template class Vector<double>;

}  // namespace matrixslayer
