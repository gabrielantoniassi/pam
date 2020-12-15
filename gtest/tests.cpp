#include "SMatrix.h"
#include <gtest/gtest.h>
using namespace std;

TEST(mul, oneTwo) {
	const int tam = 2;
	SMatrix<double, tam, tam> m1(1), m2(2), mref;

	for(int i = 0; i < m1.m_rows; i++)
	{
		for(int j = 0; j < m2.m_cols; j++)
		{
			for(int k = 0; k < m1.m_cols; k++)
		    {
		        mref.m_data[mref.storage_order == RowMajor ? i*m2.m_cols + j : j*m1.m_rows + i] += m1.m_data[m1.storage_order == RowMajor ? i*m1.m_cols + k : k*m1.m_rows + i]*m2.m_data[m2.storage_order == RowMajor ? k*m2.m_cols + j : j*m1.m_cols + k];
			}
		}
	}

	SMatrix<double, tam, tam> mres = m1.mul<tam>(m2);

	cout << m1 << endl;
	cout << m2 << endl;
	cout << mref << endl;
	cout << mres << endl;

	for (int i = 0; i < tam*tam; i++)
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
