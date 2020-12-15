#include "SMatrix.h"
#include <gtest/gtest.h>

TEST(mul, oneTwo) {
	SMatrix<double, 4, 4> m1(1), m2(2);

	SMatrix<double, 4, 4> mref;
	for(int i = 0; i < m1.m_rows; i++)
	{
		for(int j = 0; j < m2.m_cols; j++)
		{
			for(int k = 0; k < m1.m_cols; k++)
		    {
		        mref.m_data[mref.storage_order == RowMajor ? i*m2.m_cols + j : j*m1.m_rows + i] += m1.m_data[m1.storage_order == RowMajor ? i*m1.m_cols + k : k*m1.m_rows + i]*rhs.m_data[rhs.storage_order == RowMajor ? k*m2.m_cols + j : j*m1.m_cols + k];
			}
		}
	}

	SMatrix<double, 4, 4> mres = m1.mul<4>(m2);

	for (int i = 0; i < 16; i++)
		EXPECT_EQ(mref.m_data[i], mres.m_data[i]);

}

/*
TEST(SquareRootTest, NegativeNos) {
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}
*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
