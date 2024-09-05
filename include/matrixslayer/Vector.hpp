#pragma once

#include <initializer_list>
#include <vector>
#include <string>

namespace matrixslayer {

template <typename T>
class Vector {
public:
  Vector() = default;
  Vector(std::initializer_list<T> list);
  Vector(const Vector<T>& other);

  Vector<T>& operator=(const Vector<T>& other);
  Vector<T> operator+(const Vector<T>& other) const;
  Vector<T> operator-(const Vector<T>& other) const;
  Vector<T>& operator+=(const Vector<T>& other);
  Vector<T>& operator-=(const Vector<T>& other);
  Vector<T> operator-() const;
  Vector<T> operator*(const T scalar) const;
  Vector<T> operator/(const T scalar) const;
  // Dot product
  T operator*(const Vector<T>& other) const;
  // Cross product
  Vector<T> operator^(const Vector<T>& other) const;
  T operator[](unsigned int index) const;
  T length() const;

  unsigned long int size() const;
  std::string str() const;
  const T* ptr() const;

private:
  std::vector<T> data;
};

using Vec = Vector<float>;
using Ved = Vector<double>;

} // namespace matrixslayer
