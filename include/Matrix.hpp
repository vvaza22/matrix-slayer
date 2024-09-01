#pragma once

#include <string>
#include <initializer_list>

class Matrix {
public:
	Matrix(std::initializer_list<float> list);
	std::string str() const;
private:
	float data[16];
};
