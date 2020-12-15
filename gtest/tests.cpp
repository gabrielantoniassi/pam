#include "SMatrix.h"
#include <gtest/gtest.h>

TEST(mul, oneTwo) {
	SMatrix<double, 4, 4> m1(1), m2(2);

	SMatrix<double, 4, 4> res;    //if RowMajor: lhs(this): #rows = rows, #columns = cols
	for(int i = 0; i < rows; i++)            //             rhs:       #rows = cols, #columns = mRHS_cols
	{                                        //             res:       #rows = rows, #columns = mRHS_cols
        	for(int j = 0; j < mRHS_cols; j++)
	        {
        		for(int k = 0; k < cols; k++)
		        {
		            res.m_data[order == RowMajor ? i*mRHS_cols + j : j*rows + i] += m_data[StorageOrder == RowMajor ? i*cols + k : k*rows + i]*rhs.m_data[rhs.storage_order == RowMajor ? k*mRHS_cols + j : j*cols + k];
	        	}
		}
	}

	SMatrix<double, 4, 4> mref = m1.mult<4>(m2);
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
