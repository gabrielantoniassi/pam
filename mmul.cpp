#include <iostream>
using namespace std;

class Matrix {
public:
  int nrows, ncols;
  double** mat;

  Matrix(int nRows, int nCols) {
    nrows = nRows;
    ncols = nCols;
    mat = new double*[nrows];
    for (int i = 0; i < nrows; i++) {
      mat[i] = new double[ncols];
    }
  }

  void readMat() {
    for (int i = 0; i < nrows; i ++) {
      for (int j = 0; j < ncols; j++) {
        cin >> mat[i][j];
      }
    }
  }

  void printMat() {
    for (int i = 0; i < nrows; i ++) {
      for (int j = 0; j < ncols; j++) {
        cout << mat[i][j] << " ";
      }
      cout << '\n';
    }
  }
};

Matrix matMul(Matrix m1, Matrix m2) {
  Matrix out(m1.nrows, m2.ncols);
  double aux;

  for (int i = 0; i < m1.nrows; i++) {
    for (int j = 0; j < m2.ncols; j++) {
      aux = 0;
      for (int k = 0; k < m1.ncols; k++) {
        aux += m1.mat[i][k]*m2.mat[k][j];
      }
      out.mat[i][j] = aux;
    }
  }

  return out;
}

void teste() {
  cout << "hello\n";
}


int main() {

  int tam = 2;
  Matrix m1(tam, tam), m2(tam, tam), mr(tam, tam);

  m1.readMat();
  m2.readMat();

  mr = matMul(m1, m2);

  printMat(mr);

  return 0;
}
