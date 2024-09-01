#include <Matrix.hpp>
#include <cassert>
#include <sstream>

template <typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>::Matrix(std::initializer_list<T> list) {
	assert(list.size() == Rows * Cols);

	int index = 0;
	for(auto element : list) {
		set(index / Cols, index % Cols, element);
		index++;
	}
}

template <typename T, int Rows, int Cols>
std::string Matrix<T, Rows, Cols>::str() const {
	std::ostringstream oss;

	for(int row=0; row<Rows; row++) {
		for(int col=0; col<Cols; col++) {
			oss << get(row, col) << " ";
		}
		oss << std::endl;
	}

	return oss.str();
}

template <typename T, int Rows, int Cols>
const T* Matrix<T, Rows, Cols>::ptr() const {
	return data;
}

template <typename T, int Rows, int Cols>
void Matrix<T, Rows, Cols>::set(int row, int col, T value) {
	assert(row >= 0 && col >= 0 && row < Rows && col < Cols);

	// Store the data in column-major order
	data[static_cast<unsigned int>(col * Rows + row)] = value;
}

template <typename T, int Rows, int Cols>
T Matrix<T, Rows, Cols>::get(int row, int col) const {
	assert(row >= 0 && col >= 0 && row < Rows && col < Cols);

	// Data is stored in column-major order
	return data[static_cast<unsigned int>(col * Rows + row)];
}

// Explicit instantiations
template class Matrix<float, 4, 4>;
template class Matrix<float, 3, 3>;
