#include <Matrix.hpp>
#include <sstream>

Matrix::Matrix(std::initializer_list<float> list) {
	int i = 0;
	for(auto element : list) {
		data[i++] = element;
	}
}

std::string Matrix::str() const {
	std::ostringstream oss;

	for(int row=0; row<4; row++) {
		for(int col=0; col<4; col++) {
			oss << data[row * 4 + col] << " ";
		}
		oss << std::endl;
	}

	return oss.str();
}
