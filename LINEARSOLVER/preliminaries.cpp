#include "preliminaries.h"



preliminaries::preliminaries()
{
}


preliminaries::~preliminaries()
{
}


//// assign vector a to b
void preliminaries::assign_Vec_a_to_Vec_b(double* a, double* b, int m) {
	register int i;
	for (i = 0; i < m; i++) {
		b[i] = a[i];
	}
}
void preliminaries::assign_Vec_a_to_Vec_b(float* a, float* b, int m) {
	register int i;
	for (i = 0; i < m; i++) {
		b[i] = a[i];
	}
}
void preliminaries::assign_Vec_a_to_Vec_b(int* a, int* b, int m) {
	register int i;
	for (i = 0; i < m; i++) {
		b[i] = a[i];
	}
}

//// assign matrxi A to B
void preliminaries::assign_Mat_A_to_Mat_B(double **A, double **B, int m, int n) {
	register int i, j;
	for (i = 1; i < m; i++) {
		for (j = 0; j < n; j++) {
			B[i][j] = A[i][j];
		}
	}
}
void preliminaries::assign_Mat_A_to_Mat_B(float **A, float **B, int m, int n) {
	register int i, j;
	for (i = 1; i < m; i++) {
		for (j = 0; j < n; j++) {
			B[i][j] = A[i][j];
		}
	}
}
void preliminaries::assign_Mat_A_to_Mat_B(int **A, int **B, int m, int n) {
	register int i, j;
	for (i = 1; i < m; i++) {
		for (j = 0; j < n; j++) {
			B[i][j] = A[i][j];
		}
	}
}



///// Matrix zero initialization
void preliminaries::MatZero(double **A, int m, int n) {
	register int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
}
void preliminaries::MatZero(float **A, int m, int n) {
	register int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
}
void preliminaries::MatZero(int **A, int m, int n) {
	register int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
}

///// Vector zero initialization
void preliminaries::VecZero(double *a, int n) {
	register int i;
	for (i = 0; i < n; i++) {
		a[i] = 0;
	}
}
void preliminaries::VecZero(float *a, int n) {
	register int i;
	for (i = 0; i < n; i++) {
		a[i] = 0;
	}
}
void preliminaries::VecZero(int *a, int n) {
	register int i;
	for (i = 0; i < n; i++) {
		a[i] = 0;
	}
}


///////// inner product////////////////
void preliminaries::innerProduct(double *a, double *b, int n, double &ans) {
	register int i;
	ans = 0;
	for (i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}
}

void preliminaries::innerProduct(float *a, float *b, float n, float &ans) {
	register int i;
	ans = 0;
	for (i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}
}

void preliminaries::innerProduct(int *a, int *b, int n, int &ans) {
	register int i;
	ans = 0;
	for (i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}
}
/////////////////////////////////////////////

///////////// The product of an n vector b by a scalar a is the vector

void preliminaries::scalerVecMul(double a, double *b, int n, double *ans) {
	register int i;
	for (i = 0; i < n; i++) {
		ans[i] = a * b[i];
	}
}

void preliminaries::scalerVecMul(float a, float *b, int n, float *ans) {
	register int i;
	for (i = 0; i < n; i++) {
		ans[i] = a * b[i];
	}
}

void preliminaries::scalerVecMul(int a, int *b, int n, int *ans) {
	register int i;
	for (i = 0; i < n; i++) {
		ans[i] = a * b[i];
	}
}

//////// The product of an m × n matrix A by a scalar α is the matrix

void preliminaries::ScalMatMul(double **A, double a, int m, int n, double **ans) {
	register int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[i][j] = a * A[i][j];
		}
	}
}

void preliminaries::ScalMatMul(float **A, float a, int m, int n, float **ans) {
	register int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[i][j] = a * A[i][j];
		}
	}
}

void preliminaries::ScalMatMul(int **A, int a, int m, int n, int **ans) {
	register int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[i][j] = a * A[i][j];
		}
	}
}


/////// The sum of two m × n matrices A and B is the m × n matrix C 
void preliminaries::MatSum(double **A, double** B, int m, int n, double **ans) {
	register int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[i][j] = A[i][j] + B[i][j];
		}
	}
}
void preliminaries::MatSum(float **A, float** B, int m, int n, float **ans) {
	register int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[i][j] = A[i][j] + B[i][j];
		}
	}
}
void preliminaries::MatSum(int **A, int** B, int m, int n, int **ans) {
	register int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[i][j] = A[i][j] + B[i][j];
		}
	}
}


///// The product Ax of an m × n matrix A by a column x of length n
void preliminaries::MatVecMul(double **A, double* x, int m, int n, double *ans) {
	register int i, j;
	VecZero(ans, n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[i] += A[i][j] * x[j];
		}
	}
}
void preliminaries::MatVecMul(float **A, float* x, int m, int n, float *ans) {
	register int i, j;
	VecZero(ans, n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[i] += A[i][j] * x[j];
		}
	}
}
void preliminaries::MatVecMul(int **A, int* x, int m, int n, int *ans) {
	register int i, j;
	VecZero(ans, n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[i] += A[i][j] * x[j];
		}
	}

}

///// The product of a row x of length m by an m × n matrix A
void preliminaries::VecMatMul(double **A, double* x, int m, int n, double *ans) {
	register int i, j;
	VecZero(ans, n);
	for (j = 0; j < n; j++) {
		for (i = 0; i < m; i++) {
			ans[j] += x[i] * A[i][j];
		}
	}
}
void preliminaries::VecMatMul(float **A, float* x, int m, int n, float *ans) {
	register int i, j;
	VecZero(ans, n);
	for (j = 0; j < n; j++) {
		for (i = 0; i < m; i++) {
			ans[j] += x[i] * A[i][j];
		}
	}
}
void preliminaries::VecMatMul(int **A, int* x, int m, int n, int *ans) {
	register int i, j;
	VecZero(ans, n);
	for (j = 0; j < n; j++) {
		for (i = 0; i < m; i++) {
			ans[j] += x[i] * A[i][j];
		}
	}

}

//// Suppose that A is an m × n matrix and B is an n × p matrix. Then the product of the matrices A and B is:
void preliminaries::MatMul(double **A, int m, int n, double **B, int p, double **ans) {
	register int i, j, q;
	MatZero(ans, m, p);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			for (q = 0; q < p; q++) {
				ans[i][q] += A[i][j] * B[j][q];
			}
		}
	}
}
void preliminaries::MatMul(float **A, int m, int n, float **B, int p, float **ans) {
	register int i, j, q;
	MatZero(ans, m, p);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			for (q = 0; q < p; q++) {
				ans[i][q] += A[i][j] * B[j][q];
			}
		}
	}
}
void preliminaries::MatMul(int **A, int m, int n, int **B, int p, int **ans) {
	register int i, j, q;
	MatZero(ans, m, p);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			for (q = 0; q < p; q++) {
				ans[i][q] += A[i][j] * B[j][q];
			}
		}
	}
}

//// Suppose that A and B are an m × m matrices. Then the product of the matrices A and B is:
void preliminaries::SqMatMul(double **A, double **B, int m, double **ans) {
	register int i, j;
	MatZero(ans, m, m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			ans[i][j] += A[i][j] * B[j][i];
		}
	}
}
void preliminaries::SqMatMul(float **A, float **B, int m, float **ans) {
	register int i, j;
	MatZero(ans, m, m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			ans[i][j] += A[i][j] * B[j][i];
		}
	}
}
void preliminaries::SqMatMul(int **A, int **B, int m, int **ans) {
	register int i, j;
	MatZero(ans, m, m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			ans[i][j] += A[i][j] * B[j][i];
		}
	}
}


//// matrix transposition
void preliminaries::MatTranspose(double** A, int m, int n, double **ans) {
	register int i, j;
	MatZero(ans, n, m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[j][i] = A[i][j];
		}
	}
}
void preliminaries::MatTranspose(float** A, int m, int n, float **ans) {
	register int i, j;
	MatZero(ans, n, m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[j][i] = A[i][j];
		}
	}
}
void preliminaries::MatTranspose(int** A, int m, int n, int **ans) {
	register int i, j;
	MatZero(ans, n, m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			ans[j][i] = A[i][j];
		}
	}
}

//// LU, Gaussian Elimination
void preliminaries::SOLVE_LU(double **A, double* b, double *x, int m, double **L, double **U, double &det) {
	register int i, j, k, q;
	if (L != nullptr) {
		MatZero(L, m, m);
	}
	if (L != nullptr) {
		MatZero(U, m, m);
	}
	VecZero(x, m);
	int Per = 0;
	det = 1.0;
	
	double max, temp, c;
	for (i = 0; i < m - 1; i++) {
		max = abs(A[i][i]);
		for (k = i + 1; k < m; k++) {
			if (abs(A[k][i]) > max) {
				max = abs(A[k][i]);
				for (q = i; q < m; q++) {
					temp = A[k][q];
					A[k][q] = A[i][q];
					A[i][q] = temp;
				}
				temp = b[i];
				b[i] = b[k];
				b[k] = temp;
				if (L != nullptr) {
					for (q = 0; q < i; q++) {
						temp = L[k][q];
						L[k][q] = L[i][q];
						L[i][q] = temp;
					}
				}
			}
		}
		if (max == 0) {
			break;
		}
		for (k = i + 1; k < m; k++) {	
			c = -A[k][i] / A[i][i];
			A[k][i] = 0.0;
			if (L != nullptr) {
				L[i][i] = 1.0;
				L[k][i] = -c;
			}
			for (j = i + 1; j < m; j++) {
				A[k][j] += c * A[i][j];
			}
			b[k] += c * b[i];
		}
		det *= A[i][i];
	}
	if (U != nullptr) {
		for (int i = 0; i < m; i++) {
			for (int j = i; j < m; j++) {
				U[i][j] = A[i][j];
			}
		}
	}
	det *= A[m - 1][m - 1];

	x[m - 1] = b[m - 1] / A[m - 1][m - 1];
	for (int i = m - 2; i > -1; i--) {
		x[i] = b[i];
		for (int j = m - 1; j > i; j--) {
			x[i] -= x[j] * A[i][j];
		}
		x[i] /= A[i][i];
	}

	//MatZero(A, m, m);
	//MatMul(L, m, m, U, m, A);
}
