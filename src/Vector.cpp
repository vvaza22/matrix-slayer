#include <matrixslayer/Vector.hpp>

#include <sstream>
#include <cassert>

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
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
  data = other.data;
  return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
  assert(size() == other.size());

  Vector<T> result(*this);
  for (unsigned int i = 0; i < data.size(); i++) {
    result.data[i] += other.data[i];
  }
  return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const {
  assert(size() == other.size());

  Vector<T> result(*this);
  for (unsigned int i = 0; i < data.size(); i++) {
    result.data[i] -= other.data[i];
  }
  return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(const T scalar) const {
  Vector<T> result(*this);
  for (unsigned int i = 0; i < data.size(); i++) {
    result.data[i] *= scalar;
  }
  return result;
}

template <typename T>
Vector<T> Vector<T>::operator/(const T scalar) const {
  Vector<T> result(*this);
  for (unsigned int i = 0; i < data.size(); i++) {
    result.data[i] /= scalar;
  }
  return result;
}

template <typename T>
T Vector<T>::operator*(const Vector<T>& other) const {
  assert(size() == other.size());

  T result = 0;
  for (unsigned int i = 0; i < data.size(); i++) {
    result += data[i] * other.data[i];
  }
  return result;
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
