#pragma once

#include <string>
#include <initializer_list>

template <typename T, int Rows, int Cols>
class Matrix {
public:
	Matrix(std::initializer_list<T> list);
	std::string str() const;
private:
	T data[static_cast<unsigned int>(Rows * Cols)];
};

using Matrix4f = Matrix<float, 4, 4>;
using Matrix3f = Matrix<float, 3, 3>;
