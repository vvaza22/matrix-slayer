#include <cassert>
#include <matrixslayer/MatrixFactory.hpp>

namespace matrixslayer {

Mat Matrix3f(std::initializer_list<float> list) {
  assert(list.size() == 9);

  Store<float>* store = new ColumnMajorStore<float>(3, 3);
  return Matrix<float>(store, list);
}

Mat Matrix4f(std::initializer_list<float> list) {
  assert(list.size() == 16);

  Store<float>* store = new ColumnMajorStore<float>(4, 4);
  return Matrix<float>(store, list);
}

Mad Matrix3d(std::initializer_list<double> list) {
  assert(list.size() == 9);

  Store<double>* store = new ColumnMajorStore<double>(3, 3);
  return Matrix<double>(store, list);
}

Mad Matrix4d(std::initializer_list<double> list) {
  assert(list.size() == 16);

  Store<double>* store = new ColumnMajorStore<double>(4, 4);
  return Matrix<double>(store, list);
}

}  // namespace matrixslayer
