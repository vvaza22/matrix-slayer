#pragma once

#include <Matrix.hpp>
#include <initializer_list>
#include <store/ColumnMajorStore.hpp>

namespace matrixslayer {

Mat Matrix3f(std::initializer_list<float> list);
Mat Matrix4f(std::initializer_list<float> list);
Mad Matrix3d(std::initializer_list<double> list);
Mad Matrix4d(std::initializer_list<double> list);

}  // namespace matrixslayer
