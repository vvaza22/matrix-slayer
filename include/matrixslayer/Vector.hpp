#pragma once

#include <initializer_list>
#include <vector>
#include <string>

namespace matrixslayer {

template <typename T>
class Vector {
public:
  Vector(std::initializer_list<T> list);

  unsigned long int size() const;
  std::string str() const;
  const T* ptr() const;

private:
  std::vector<T> data;
};

} // namespace matrixslayer
