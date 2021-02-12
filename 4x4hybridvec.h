#ifndef hybrid
#define hybrid
#include <iostream>
using namespace std;

void hhybrid(const double* mLHS, const double* mRHS, double* const mResult) {

	__vector double a11, a21, a31, a41,
                    a12, a22, a32, a42,
					b11, b21, b31, b41,
					b12, b22, b32, b42,
                    mRHSrow11, mRHSrow21, mRHSrow31, mRHSrow41,
                    mRHSrow12, mRHSrow22, mRHSrow32, mRHSrow42;

    // row 1
    a11 = vec_xl(0, mLHS);
    a12 = vec_xl(0, mLHS + 2);
    // row 2
    a21 = vec_xl(0, mLHS + 4);
    a22 = vec_xl(0, mLHS + 6);
    // row 3
    a31 = vec_xl(0, mLHS + 8);
    a32 = vec_xl(0, mLHS + 10);
    // row 4
    a41 = vec_xl(0, mLHS + 12);
    a42 = vec_xl(0, mLHS + 14);

	const static __vector unsigned char GETCOL1 = { 0, 1, 2, 3, 4, 5, 6, 7,
                                                     16, 17, 18, 19, 20, 21, 22, 23};

    const static __vector unsigned char GETCOL2 = { 8, 9, 10, 11, 12, 13, 14, 15,
                                                     24, 25, 26, 27, 28, 29, 30, 31};

	// row 1
	__vector double mRHSaux1 = vec_xl(0, mRHS);
    __vector double mRHSaux2 = vec_xl(0, mRHS + 4);
    b11 = vec_perm(mRHSaux1, mRHSaux2, GETCOL1);
    b21 = vec_perm(mRHSaux1, mRHSaux2, GETCOL2);

    mRHSaux1 = vec_xl(0, mRHS + 2);
    mRHSaux2 = vec_xl(0, mRHS + 6);
    b31 = vec_perm(mRHSaux1, mRHSaux2, GETCOL1);
    b41 = vec_perm(mRHSaux1, mRHSaux2, GETCOL2);

    mRHSaux1 = vec_xl(0, mRHS + 8);
    mRHSaux2 = vec_xl(0, mRHS + 12);
    b12 = vec_perm(mRHSaux1, mRHSaux2, GETCOL1);
    b22 = vec_perm(mRHSaux1, mRHSaux2, GETCOL2);

    mRHSaux1 = vec_xl(0, mRHS + 10);
    mRHSaux2 = vec_xl(0, mRHS + 14);
    b32 = vec_perm(mRHSaux1, mRHSaux2, GETCOL1);
    b42 = vec_perm(mRHSaux1, mRHSaux2, GETCOL2);

//	double m[58];

	__vector double m12, m34, m56, m78, m910, m1112, m1314, m1516, m1718, m1920, m2122, m2324, m2526, m2728, m2930, m3132, m3334, m3536, m3738, m3940, m4142, m4344, m4546, m4748, m4950, m5152, m5354, m5556;

/*
	m[1]=  A(0,0)*B(0,0);
	m[2]=  A(0,1)*B(1,0);
	m[3]=  A(0,0)*B(0,1);
	m[4]=  A(0,1)*B(1,1);
	m[5]=  A(1,0)*B(0,0);
	m[6]=  A(1,1)*B(1,0);
	m[7]=  A(1,0)*B(0,1);
	m[8]=  A(1,1)*B(1,1);
*/
	m12 = vec_mul(a11, b11);
	vec_xst(vec_mul(a11, b21), 0, m34);
	vec_xst(vec_mul(a21, b11), 0, m56);
	vec_xst(vec_mul(a21, b21), 0, m78);
/*
	m[9]=  A(0,2)*B(2,0);
	m[10]=  A(0,3)*B(3,0);
	m[11]=  A(0,2)*B(2,1);
	m[12]=  A(0,3)*B(3,1);
	m[13]=  A(1,2)*B(2,0);
	m[14]=  A(1,3)*B(3,0);
	m[15]=  A(1,2)*B(2,1);
	m[16]=  A(1,3)*B(3,1);
*/
	vec_xst(vec_mul(a12, b12), 0, m910);
	vec_xst(vec_mul(a12, b22), 0, m1112);
	vec_xst(vec_mul(a22, b12), 0, m1314);
	vec_xst(vec_mul(a22, b22), 0, m1516);
/*
	m[17]= ( A(2,0)+ A(2,2))*(B(0,2)-B(0,0));
	m[18]= ( A(2,1)+ A(2,3))*(B(1,2)-B(1,0));
	m[19]= ( A(2,0)+ A(2,2))*(B(0,3)-B(0,1));
	m[20]= ( A(2,1)+ A(2,3))*(B(1,3)-B(1,1));
	m[21]= ( A(3,0)+ A(3,2))*(B(0,2)-B(0,0));
	m[22]= ( A(3,1)+ A(3,3))*(B(1,2)-B(1,0));
	m[23]= ( A(3,0)+ A(3,2))*(B(0,3)-B(0,1));
	m[24]= ( A(3,1)+ A(3,3))*(B(1,3)-B(1,1));
*/
	vec_xst(vec_mul(vec_add(a31, a32), vec_sub(b31, b11)), 0, m1718);
	vec_xst(vec_mul(vec_add(a31, a32), vec_sub(b41, b21)), 0, m1920);
	vec_xst(vec_mul(vec_add(a41, a42), vec_sub(b31, b11)), 0, m2122);
	vec_xst(vec_mul(vec_add(a41, a42), vec_sub(b41, b21)), 0, m2324);
/*
	m[25]= ( A(2,0)+ A(2,2)- A(0,0))*(B(2,2)-B(0,2)+B(0,0));
	m[26]= ( A(2,1)+ A(2,3)- A(0,1))*(B(3,2)-B(1,2)+B(1,0));
	m[27]= ( A(2,0)+ A(2,2)- A(0,0))*(B(2,3)-B(0,3)+B(0,1));
	m[28]= ( A(2,1)+ A(2,3)- A(0,1))*(B(3,3)-B(1,3)+B(1,1));
	m[29]= ( A(3,0)+ A(3,2)- A(1,0))*(B(2,2)-B(0,2)+B(0,0));
	m[30]= ( A(3,1)+ A(3,3)- A(1,1))*(B(3,2)-B(1,2)+B(1,0));
	m[31]= ( A(3,0)+ A(3,2)- A(1,0))*(B(2,3)-B(0,3)+B(0,1));
	m[32]= ( A(3,1)+ A(3,3)- A(1,1))*(B(3,3)-B(1,3)+B(1,1));
*/
	vec_xst(vec_mul(vec_add(a31, vec_sub(a32, a11)), vec_add(vec_sub(b32, b31), b11)), 0, m2526);
	vec_xst(vec_mul(vec_add(a31, vec_sub(a32, a11)), vec_add(vec_sub(b42, b41), b21)), 0, m2728);
	vec_xst(vec_mul(vec_add(a41, vec_sub(a42, a21)), vec_add(vec_sub(b32, b31), b11)), 0, m2930);
	vec_xst(vec_mul(vec_add(a41, vec_sub(a42, a21)), vec_add(vec_sub(b42, b41), b21)), 0, m3132);
/*
	m[33]= ( A(0,0)- A(2,0))*(B(2,2)-B(0,2));
	m[34]= ( A(0,1)- A(2,1))*(B(3,2)-B(1,2));
	m[35]= ( A(0,0)- A(2,0))*(B(2,3)-B(0,3));
	m[36]= ( A(0,1)- A(2,1))*(B(3,3)-B(1,3));
	m[37]= ( A(1,0)- A(3,0))*(B(2,2)-B(0,2));
	m[38]= ( A(1,1)- A(3,1))*(B(3,2)-B(1,2));
	m[39]= ( A(1,0)- A(3,0))*(B(2,3)-B(0,3));
	m[40]= ( A(1,1)- A(3,1))*(B(3,3)-B(1,3));
*/
	vec_xst(vec_mul(vec_sub(a11, a31), vec_sub(b32, b31)), 0, m3334);
	vec_xst(vec_mul(vec_sub(a11, a31), vec_sub(b42, b41)), 0, m3536);
	vec_xst(vec_mul(vec_sub(a21, a41), vec_sub(b32, b31)), 0, m3738);
	vec_xst(vec_mul(vec_sub(a21, a41), vec_sub(b42, b41)), 0, m3940);
/*
	m[41]= ( A(0,2)- A(2,0)- A(2,2)+ A(0,0))*B(2,2);
	m[42]= ( A(0,3)- A(2,1)- A(2,3)+ A(0,1))*B(3,2);
	m[43]= ( A(0,2)- A(2,0)- A(2,2)+ A(0,0))*B(2,3);
	m[44]= ( A(0,3)- A(2,1)- A(2,3)+ A(0,1))*B(3,3);
	m[45]= ( A(1,2)- A(3,0)- A(3,2)+ A(1,0))*B(2,2);
	m[46]= ( A(1,3)- A(3,1)- A(3,3)+ A(1,1))*B(3,2);
	m[47]= ( A(1,2)- A(3,0)- A(3,2)+ A(1,0))*B(2,3);
	m[48]= ( A(1,3)- A(3,1)- A(3,3)+ A(1,1))*B(3,3);
*/
	vec_xst(vec_mul(vec_add(vec_sub(vec_sub(a12, a31), a32), a11), b32), 0, m4142);
	vec_xst(vec_mul(vec_add(vec_sub(vec_sub(a12, a31), a32), a11), b42), 0, m4344);
	vec_xst(vec_mul(vec_add(vec_sub(vec_sub(a22, a41), a42), a21), b32), 0, m4546);
	vec_xst(vec_mul(vec_add(vec_sub(vec_sub(a22, a41), a42), a21), b42), 0, m4748);
/*
	m[49]=  A(2,2)*(B(2,0)-B(2,2)+B(0,2)-B(0,0));
	m[50]=  A(2,3)*(B(3,0)-B(3,2)+B(1,2)-B(1,0));
	m[51]=  A(2,2)*(B(2,1)-B(2,3)+B(0,3)-B(0,1));
	m[52]=  A(2,3)*(B(3,1)-B(3,3)+B(1,3)-B(1,1));
	m[53]=  A(3,2)*(B(2,0)-B(2,2)+B(0,2)-B(0,0));
	m[54]=  A(3,3)*(B(3,0)-B(3,2)+B(1,2)-B(1,0));
	m[55]=  A(3,2)*(B(2,1)-B(2,3)+B(0,3)-B(0,1));
	m[56]=  A(3,3)*(B(3,1)-B(3,3)+B(1,3)-B(1,1));
*/
	vec_xst(vec_mul(a32, vec_sub(vec_add(vec_sub(b12, b32), b31), b11)), 0, m4950);
	vec_xst(vec_mul(a32, vec_sub(vec_add(vec_sub(b22, b42), b41), b21)), 0, m5152);
	vec_xst(vec_mul(a42, vec_sub(vec_add(vec_sub(b12, b32), b31), b11)), 0, m5354);
	vec_xst(vec_mul(a42, vec_sub(vec_add(vec_sub(b22, b42), b41), b21)), 0, m5556);

	__vector double mm0103, mm0204, mm0507, mm0608, mm0911,
					mm1012, mm1315, mm1416, mm1719, mm1820,
					mm2123, mm2224, mm2527, mm2628, mm2931,
					mm3032, mm3335, mm3436, mm3739, mm3840,
					mm4143, mm4244, mm4547, mm4648, mm4951,
					mm5052, mm5355, mm5456;

	mm0103 = vec_perm(m12, m34, GETCOL1);
    mm0204 = vec_perm(m12, m34, GETCOL2);
	mm0507 = vec_perm(m56, m78, GETCOL1);
	mm0608 = vec_perm(m56, m78, GETCOL2);
	mm0911 = vec_perm(m910, m1112, GETCOL1);
	mm1012 = vec_perm(m910, m1112, GETCOL2);
	mm1315 = vec_perm(m1314, m1516, GETCOL1);
	mm1416 = vec_perm(m1314, m1516, GETCOL2);
	mm1719 = vec_perm(m1718, m1920, GETCOL1);
	mm1820 = vec_perm(m1718, m1920, GETCOL2);
	mm2123 = vec_perm(m2122, m2324, GETCOL1);
	mm2224 = vec_perm(m2122, m2324, GETCOL2);
	mm2527 = vec_perm(m2526, m2728, GETCOL1);
	mm2628 = vec_perm(m2526, m2728, GETCOL2);
	mm2931 = vec_perm(m2930, m3132, GETCOL1);
	mm3032 = vec_perm(m2930, m3132, GETCOL2);
	mm3335 = vec_perm(m3334, m3536, GETCOL1);
	mm3436 = vec_perm(m3334, m3536, GETCOL2);
	mm3739 = vec_perm(m3738, m3940, GETCOL1);
	mm3840 = vec_perm(m3738, m3940, GETCOL2);
	mm4143 = vec_perm(m4142, m4344, GETCOL1);
	mm4244 = vec_perm(m4142, m4344, GETCOL2);
	mm4547 = vec_perm(m4546, m4748, GETCOL1);
	mm4648 = vec_perm(m4546, m4748, GETCOL2);
	mm4951 = vec_perm(m4950, m5152, GETCOL1);
	mm5052 = vec_perm(m4950, m5152, GETCOL2);
	mm5355 = vec_perm(m5354, m5556, GETCOL1);
	mm5456 = vec_perm(m5354, m5556, GETCOL2);
/*
	C(0,0) = m[1] + m[2] + m[9] + m[10];
	C(0,1) = m[3] + m[4] + m[11] + m[12];
	C(1,0) = m[5] + m[6] + m[13] + m[14];
	C(1,1) = m[7] + m[8] + m[15] + m[16];
*/
	vec_xst(vec_add(vec_add(vec_add(mm0103, mm0204), mm0911), mm1012), 0, mResult);
	vec_xst(vec_add(vec_add(vec_add(mm0507, mm0608), mm1315), mm1416), 0, mResult + 4);
/*
	C(2,0) = m[1] + m[2] + m[25] + m[26] + m[33] + m[34] + m[49] + m[50];
	C(2,1) = m[3] + m[4] + m[27] + m[28] + m[35] + m[36] + m[51] + m[52];
	C(3,0) = m[5] + m[6] + m[29] + m[30] + m[37] + m[38] + m[53] + m[54];
	C(3,1) = m[7] + m[8] + m[31] + m[32] + m[39] + m[40] + m[55] + m[56];
*/
	vec_xst(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(mm0103, mm0204), mm2527), mm2628), mm3335), mm3436), mm4951), mm5052), 0, mResult + 8);
	vec_xst(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(mm0507, mm0608), mm2931), mm3032), mm3739), mm3840), mm5355), mm5456), 0, mResult + 12);
/*
	C(0,2) = m[1] + m[2] + m[25] + m[26] + m[17] + m[18] + m[41] + m[42];
	C(0,3) = m[3] + m[4] + m[27] + m[28] + m[19] + m[20] + m[43] + m[44];
	C(1,2) = m[5] + m[6] + m[29] + m[30] + m[21] + m[22] + m[45] + m[46];
	C(1,3) = m[7] + m[8] + m[31] + m[32] + m[23] + m[24] + m[47] + m[48];
*/
	vec_xst(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(mm0103, mm0204), mm2527), mm2628), mm1719), mm1820), mm4143), mm4244), 0, mResult + 2);
	vec_xst(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(mm0507, mm0608), mm2931), mm3032), mm2123), mm2224), mm4547), mm4648), 0, mResult + 6);
/*
	C(2,2) = m[1] + m[2] + m[25] + m[26] + m[33] + m[34] + m[17] + m[18];
	C(2,3) = m[3] + m[4] + m[27] + m[28] + m[35] + m[36] + m[19] + m[20];
	C(3,2) = m[5] + m[6] + m[29] + m[30] + m[37] + m[38] + m[21] + m[22];
	C(3,3) = m[7] + m[8] + m[31] + m[32] + m[39] + m[40] + m[23] + m[24];
*/
	vec_xst(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(mm0103, mm0204), mm2527), mm2628), mm3335), mm3436), mm1719), mm1820), 0, mResult + 10);
	vec_xst(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(vec_add(mm0507, mm0608), mm2931), mm3032), mm3739), mm3840), mm2123), mm2224), 0, mResult + 14);
}
#endif //IBM_SMUL_H
