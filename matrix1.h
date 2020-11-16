#include <iostream>
#include <altivec.h>


enum EStorageOrder : int { RowMajor, ColMajor };

/* Small matrix */
/**** FIXME operator() const problem *****/
template<typename Scalar, int rows, int cols, int StorageOrder = RowMajor>
class SMatrix
{
public:
    const int m_rows, m_cols;
    Scalar m_data[rows*cols];

	    SMatrix() : m_rows(rows), m_cols(cols) {}

	    SMatrix(const Scalar& x0) : m_rows(rows), m_cols(cols)
	    {
		setVal<rows, cols>(x0);
	    }

	    template<int r, int c>
	    void setVal(const Scalar& v)
	    {
		for(int i = 0; i < r; i++)
		{
		    for(int j = 0; j < c; j++)
            {
                m_data[StorageOrder == RowMajor ? i*cols + j : j*rows + i] = v;
            }
        }
    }

    inline Scalar& operator()(int i, int j) const
    {
        return m_data[StorageOrder == RowMajor ? i*cols + j : j*rows + i];
    }

    friend std::ostream& operator<<(std::ostream& out, const SMatrix& m)
    {
        for(int i = 0; i < rows;i++)
        {
            for(int j = 0; j < cols; j++)
            {
                out << m.m_data[StorageOrder == RowMajor ? i*cols + j : j*rows + i] << " ";
            }
            out << std::endl;
        }
        return out;
    }
};

template<int mdepth, int mcols>
SMatrix<Scalar, rows, mdepth> mul(SMatrix<Scalar, ro> const SMatrix<Scalar, mdepth, mcols>& rhs)
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

    template<>
    SMatrix<Scalar, 4, 4> mul<4, 4>(const SMatrix<Scalar, 4, 4>& rhs)
    {
      SMatrix<Scalar, 4, 4> res;

      __vector double mLHScol11, mLHScol21, mLHScol31, mLHScol41,
                      mLHScol12, mLHScol22, mLHScol32, mLHScol42,
                      mRHSrow11, mRHSrow21, mRHSrow31, mRHSrow41,
                      mRHSrow12, mRHSrow22, mRHSrow32, mRHSrow42;

      // primeiro lemos a matrix da esquerda pegando suas colunas
      if (StorageOrder == RowMajor)
      {
              //{ [a11 a12 a13 a14], [a21 a22 a23 a24], [a31 a32 a33 a34], [a41 a42 a43 a44]}

              const static __vector unsigned char GETCOL1 = { 0, 1, 2, 3, 4, 5, 6, 7,
                                                               16, 17, 18, 19, 20, 21, 22, 23};

              const static __vector unsigned char GETCOL2 = { 8, 9, 10, 11, 12, 13, 14, 15,
                                                               24, 25, 26, 27, 28, 29, 30, 31};

              __vector double mLHSaux1 = vec_xl(0, m_data);
              __vector double mLHSaux2 = vec_xl(0, m_data + 4);
              mLHScol11 = vec_perm(mLHSaux1, mLHSaux2, GETCOL1); // dois primeiros elementos da primeira coluna?
              mLHScol21 = vec_perm(mLHSaux1, mLHSaux2, GETCOL2); // 				segunda	

              __vector double mLHSaux3 = vec_xl(0, m_data + 2);
              __vector double mLHSaux4 = vec_xl(0, m_data + 6);
              mLHScol31 = vec_perm(mLHSaux3, mLHSaux4, GETCOL1);
              mLHScol41 = vec_perm(mLHSaux3, mLHSaux4, GETCOL2);

              __vector double mLHSaux5 = vec_xl(0, m_data + 8);
              __vector double mLHSaux6 = vec_xl(0, m_data + 12);
              mLHScol12 = vec_perm(mLHSaux5, mLHSaux6, GETCOL1); // dois últimos elementos da primeira coluna?
              mLHScol22 = vec_perm(mLHSaux5, mLHSaux6, GETCOL2); //			      segunda

              __vector double mLHSaux7 = vec_xl(0, m_data + 10);
              __vector double mLHSaux8 = vec_xl(0, m_data + 14);
              mLHScol32 = vec_perm(mLHSaux7, mLHSaux8, GETCOL1);
              mLHScol42 = vec_perm(mLHSaux7, mLHSaux8, GETCOL2);
      }
      else{
              mLHScol11 = vec_xl(0, m_data);	 // dois primeiros elementos da primeira coluna?
              mLHScol12 = vec_xl(0, m_data + 2); //	 últimos 

              mLHScol21 = vec_xl(0, m_data + 4); // dois primeiros elementos da segunda coluna?
              mLHScol22 = vec_xl(0, m_data + 6); // 	 últimos

              mLHScol31 = vec_xl(0, m_data + 8);
              mLHScol32 = vec_xl(0, m_data + 10);

              mLHScol41 = vec_xl(0, m_data + 12);
              mLHScol42 = vec_xl(0, m_data + 14);
      }

      // agora lemos as linhas da matrix da direita
      // mRHSrowi1 = [bi1 bi2]
      // mRHSrowi2 = [bi3 bi4]
      mRHSrow11 = vec_xl(0, rhs.m_data);	// dois primeiros elementos da primeira linha
      mRHSrow12 = vec_xl(0, rhs.m_data + 2);	// 	últimos

      mRHSrow21 = vec_xl(0, rhs.m_data + 4);	// dois primeiros elementos da segunda linha
      mRHSrow22 = vec_xl(0, rhs.m_data + 6);	// 	últimos

      mRHSrow31 = vec_xl(0, rhs.m_data + 8);
      mRHSrow32 = vec_xl(0, rhs.m_data + 10);

      mRHSrow41 = vec_xl(0, rhs.m_data + 12);
      mRHSrow42 = vec_xl(0, rhs.m_data + 14);

      // com a matrix da esquerda fazemos vetores com elementos repetidos
      // vAuxLHSij = [aij aij]
      __vector double vAuxLHS11 = {mLHScol11[0], mLHScol11[0]}; // [a11 a11]
      __vector double vAuxLHS12 = {mLHScol11[1], mLHScol11[1]}; // [a21 a21]
      __vector double vAuxLHS13 = {mLHScol12[0], mLHScol12[0]}; // [a31 a31]
      __vector double vAuxLHS14 = {mLHScol12[1], mLHScol12[1]}; // [a41 a41]

      __vector double vAuxLHS21 = {mLHScol21[0], mLHScol21[0]}; // [a12 a12]
      __vector double vAuxLHS22 = {mLHScol21[1], mLHScol21[1]}; // [a22 a22]
      __vector double vAuxLHS23 = {mLHScol22[0], mLHScol22[0]};
      __vector double vAuxLHS24 = {mLHScol22[1], mLHScol22[1]};

      __vector double vAuxLHS31 = {mLHScol31[0], mLHScol31[0]};
      __vector double vAuxLHS32 = {mLHScol31[1], mLHScol31[1]};
      __vector double vAuxLHS33 = {mLHScol32[0], mLHScol32[0]};
      __vector double vAuxLHS34 = {mLHScol32[1], mLHScol32[1]};

      __vector double vAuxLHS41 = {mLHScol41[0], mLHScol41[0]};
      __vector double vAuxLHS42 = {mLHScol41[1], mLHScol41[1]};
      __vector double vAuxLHS43 = {mLHScol42[0], mLHScol42[0]};
      __vector double vAuxLHS44 = {mLHScol42[1], mLHScol42[1]};

      //building the first row of mResult
      // vAuxLHSij = [aij aij]
      // mRHSrowi1 = [bi1 bi2]
      // mRHSrowi2 = [bi3 bi4]
      // tá certo isso em cima?
      vec_xst(vec_add(
                      vec_madd(mRHSrow21, vAuxLHS21, vec_mul(mRHSrow11, vAuxLHS11)),
                      vec_madd(mRHSrow41, vAuxLHS41, vec_mul(mRHSrow31, vAuxLHS31)) ),
              0, res.m_data);
/*
      a linha de cima é o mesmo que a linha de baixo?
      vec_xst(vec_madd(mRHSrow21, vAuxLHS21, vec_madd(mRHSrow11, vAuxLHS11,
                      vec_madd(mRHSrow41, vAuxLHS41, vec_mul(mRHSrow31, vAuxLHS31)))),
              0, res.m_data);
*/
      vec_xst(vec_add(
                      vec_madd(mRHSrow22, vAuxLHS21, vec_mul(mRHSrow12, vAuxLHS11)),
                      vec_madd(mRHSrow42, vAuxLHS41, vec_mul(mRHSrow32, vAuxLHS31)) ),
              0, res.m_data + 2);

      //building the second row of mResult
      vec_xst(vec_add(
                      vec_madd(mRHSrow21, vAuxLHS22, vec_mul(mRHSrow11, vAuxLHS12)),
                      vec_madd(mRHSrow41, vAuxLHS42, vec_mul(mRHSrow31, vAuxLHS32)) ),
              0, res.m_data + 4);
      vec_xst(vec_add(
                      vec_madd(mRHSrow22, vAuxLHS22, vec_mul(mRHSrow12, vAuxLHS12)),
                      vec_madd(mRHSrow42, vAuxLHS42, vec_mul(mRHSrow32, vAuxLHS32)) ),
              0, res.m_data + 6);

      //building the third row of mResult
      vec_xst(vec_add(
                      vec_madd(mRHSrow21, vAuxLHS23, vec_mul(mRHSrow11, vAuxLHS13)),
                      vec_madd(mRHSrow41, vAuxLHS43, vec_mul(mRHSrow31, vAuxLHS33)) ),
              0, res.m_data + 8);
      vec_xst(vec_add(
                      vec_madd(mRHSrow22, vAuxLHS23, vec_mul(mRHSrow12, vAuxLHS13)),
                      vec_madd(mRHSrow42, vAuxLHS43, vec_mul(mRHSrow32, vAuxLHS33)) ),
              0, res.m_data + 10);

      //building the fourth row of mResult
      vec_xst(vec_add(
                      vec_madd(mRHSrow21, vAuxLHS24, vec_mul(mRHSrow11, vAuxLHS14)),
                      vec_madd(mRHSrow41, vAuxLHS44, vec_mul(mRHSrow31, vAuxLHS34)) ),
              0, res.m_data + 12);
      vec_xst(vec_add(
                      vec_madd(mRHSrow22, vAuxLHS24, vec_mul(mRHSrow12, vAuxLHS14)),
                      vec_madd(mRHSrow42, vAuxLHS44, vec_mul(mRHSrow32, vAuxLHS34)) ),
              0, res.m_data + 14);

      return res;
    }

