#include <Matrix.hpp>
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

TEST(MatrixTest, TestToString) {
	Matrix m{
		1 , 2 , 3 , 4 ,
		5 , 6 , 7 , 8 ,
		9 , 10, 11, 12,
		13, 14, 15, 16,
	};

	std::ostringstream oss;
	oss << "1 2 3 4 " << std::endl;
	oss << "5 6 7 8 " << std::endl;
	oss << "9 10 11 12 " << std::endl;
	oss << "13 14 15 16 " << std::endl;

	EXPECT_EQ(m.str(), oss.str());
}
