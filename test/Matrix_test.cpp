#include <Matrix.hpp>
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace matrixslayer;

TEST(MatrixTest, TestToString3x3) {
	Matrix3f m{
		1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f,
	};

	std::ostringstream oss;
	oss << "1 2 3 " << std::endl;
	oss << "4 5 6 " << std::endl;
	oss << "7 8 9 " << std::endl;

	EXPECT_EQ(m.str(), oss.str());
}

TEST(MatrixTest, TestToString4x4) {
	Matrix4f m{
		1.0f,  2.0f,  3.0f,  4.0f,
		5.0f,  6.0f,  7.0f,  8.0f,
		9.0f,  10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f,
	};

	std::ostringstream oss;
	oss << "1 2 3 4 " << std::endl;
	oss << "5 6 7 8 " << std::endl;
	oss << "9 10 11 12 " << std::endl;
	oss << "13 14 15 16 " << std::endl;

	EXPECT_EQ(m.str(), oss.str());
}

TEST(MatrixTest, TestColumnMajorDataPtr) {
	Matrix3f m1{
		1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f,
	};

	const float* ptr1 = m1.ptr();

	EXPECT_EQ(ptr1[0], 1.0f);
	EXPECT_EQ(ptr1[1], 4.0f);
	EXPECT_EQ(ptr1[2], 7.0f);
	EXPECT_EQ(ptr1[3], 2.0f);
	EXPECT_EQ(ptr1[4], 5.0f);
	EXPECT_EQ(ptr1[5], 8.0f);
	EXPECT_EQ(ptr1[6], 3.0f);
	EXPECT_EQ(ptr1[7], 6.0f);
	EXPECT_EQ(ptr1[8], 9.0f);

	Matrix3x4f m2{
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
	};

	const float* ptr2 = m2.ptr();

	EXPECT_EQ(ptr2[0], 1.0f);
	EXPECT_EQ(ptr2[1], 5.0f);
	EXPECT_EQ(ptr2[2], 9.0f);
	EXPECT_EQ(ptr2[3], 2.0f);
	EXPECT_EQ(ptr2[4], 6.0f);
	EXPECT_EQ(ptr2[5], 10.0f);
	EXPECT_EQ(ptr2[6], 3.0f);
	EXPECT_EQ(ptr2[7], 7.0f);
	EXPECT_EQ(ptr2[8], 11.0f);
	EXPECT_EQ(ptr2[9], 4.0f);
	EXPECT_EQ(ptr2[10], 8.0f);
	EXPECT_EQ(ptr2[11], 12.0f);
}
