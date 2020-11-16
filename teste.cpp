#include <iostream>
using namespace std;


template <typename Scalar, int rows, int cols>
class SMatrix {
	private:
		const int m_rows, m_cols; 
		Scalar m_data[rows*cols];

		SMatrix() : m_rows(rows), m_cols(cols) {}
};

template<int mdepth, int mcols>
SMatrix<Scalar, rows, mdepth> mul(const SMatrix<Scalar, ro> const SMatrix<Scalar, mdepth, mcols>& rhs)
{
        SMatrix<Scalar, rows, mdepth> res;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < mcols; j++)
            {
                for(int k = 0; k < mdepth; k++)
                {
                    res.m_data[StorageOrder == RowMajor ? i*mdepth + j : j*rows + i] += m_data[StorageOrder == RowMajor ? i*mdepth + k : k*rows + i]*rhs.m_data[StorageOrder == RowMajor ? k*mcols + j : j*mdepth + k];
                }
            }
        }
        return res;
    }



int main() {



	return 0;
}
