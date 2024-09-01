#include <Matrix.hpp>
#include <cassert>
#include <sstream>

template <typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>::Matrix(std::initializer_list<T> list) {
	assert(list.size() == Rows * Cols);
	int i = 0;
	for(auto element : list) {
		data[i++] = element;
	}
}

template <typename T, int Rows, int Cols>
std::string Matrix<T, Rows, Cols>::str() const {
	std::ostringstream oss;

	for(int row=0; row<Rows; row++) {
		for(int col=0; col<Cols; col++) {
			oss << data[static_cast<unsigned int>(row * Rows + col)] << " ";
		}
		oss << std::endl;
	}

	return oss.str();
}

// Explicit instantiations
template class Matrix<float, 4, 4>;
template class Matrix<float, 3, 3>;
