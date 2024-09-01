#pragma once

#include <string>
#include <initializer_list>

namespace matrixslayer {
	template <typename T, int Rows, int Cols>
	class Matrix {
	public:
		Matrix(std::initializer_list<T> list);
		std::string str() const;
		const T* ptr() const;
	private:
		T data[static_cast<unsigned int>(Rows * Cols)];

		void set(int row, int col, T value);
		T get(int row, int col) const;
	};

	using Matrix4f = Matrix<float, 4, 4>;
	using Matrix3f = Matrix<float, 3, 3>;
	using Matrix3x4f = Matrix<float, 3, 4>;
}
