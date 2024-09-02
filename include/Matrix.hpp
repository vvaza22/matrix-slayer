#pragma once

#include <initializer_list>
#include <store/Store.hpp>
#include <string>

namespace matrixslayer {

template <typename T>
class Matrix {
 public:
  Matrix(Store<T>* s, std::initializer_list<T> list);
  ~Matrix();

  std::string str() const;
  const T* ptr() const { return store->ptr(); };
  unsigned int getRows() const { return store->getRows(); };
  unsigned int getCols() const { return store->getCols(); };

 private:
  Store<T>* store;
};

}  // namespace matrixslayer
