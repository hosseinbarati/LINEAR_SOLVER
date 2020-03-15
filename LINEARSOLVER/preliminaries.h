#pragma once

#include<cmath>

class preliminaries
{
public:
	preliminaries();
	~preliminaries();
	//// assign vector a to b
	void assign_Vec_a_to_Vec_b(double* a, double* b, int m);
	void assign_Vec_a_to_Vec_b(float* a, float* b, int m);
	void assign_Vec_a_to_Vec_b(int* a, int* b, int m);

	//// assign matrxi A to B
	void assign_Mat_A_to_Mat_B(double **A, double **B, int m, int n);
	void assign_Mat_A_to_Mat_B(float **A, float **B, int m, int n);
	void assign_Mat_A_to_Mat_B(int **A, int **B, int m, int n);

	///// Matrix zero initialization
	void MatZero(double **A, int m, int n);
	void MatZero(float **A, int m, int n);
	void MatZero(int **A, int m, int n);

	///// Vector zero initialization
	void VecZero(double *a, int n);
	void VecZero(float *a, int n);
	void VecZero(int *a, int n);

	///////// inner product////////////////
	void innerProduct(double *a, double *b, int n, double &ans);
	void innerProduct(float *a, float *b, float n, float &ans);
	void innerProduct(int *a, int *b, int N, int &ans);

	///////////// The product of an n vector b by a scalar a is the vector
	void scalerVecMul(double a, double *b, int n, double *ans);
	void scalerVecMul(float a, float *b, int n, float *ans);
	void scalerVecMul(int a, int *b, int n, int *ans);

	//////// The product of an m × n matrix A by a scalar α is the matrix
	void ScalMatMul(double **A, double a, int m, int n, double **ans);
	void ScalMatMul(float **A, float a, int m, int n, float **ans);
	void ScalMatMul(int **A, int a, int m, int n, int **ans);

	/////// The sum of two m × n matrices A and B is the m × n matrix C 
	void MatSum(double **A, double** B, int m, int n, double **ans);
	void MatSum(float **A, float** B, int m, int n, float **ans);
	void MatSum(int **A, int** B, int m, int n, int **ans);

	///// The product Ax of an m × n matrix A by a column x of length n
	void MatVecMul(double **A, double* x, int m, int n, double *ans);
	void MatVecMul(float **A, float* x, int m, int n, float *ans);
	void MatVecMul(int **A, int* x, int m, int n, int *ans);

	///// The product of a row x of length m by an m × n matrix A
	void VecMatMul(double **A, double* x, int m, int n, double *ans);
	void VecMatMul(float **A, float* x, int m, int n, float *ans);
	void VecMatMul(int **A, int* x, int m, int n, int *ans);


	//// Suppose that A is an m × n matrix and B is an n × p matrix. Then the product of the matrices A and B is:
	void MatMul(double **A, int m, int n, double **B, int P, double **ans);
	void MatMul(float **A, int m, int n, float **B, int P, float **ans);
	void MatMul(int **A, int m, int n, int **B, int P, int **ans);

	//// Suppose that A and B are an m × m matrices. Then the product of the matrices A and B is:
	void SqMatMul(double **A, double **B, int m, double **ans);
	void SqMatMul(float **A, float **B, int m, float **ans);
	void SqMatMul(int **A, int **B, int m, int **ans);

	//// matrix transposition
	void MatTranspose(double** A, int m, int n, double **ans);
	void MatTranspose(float** A, int m, int n, float **ans);
	void MatTranspose(int** A, int m, int n, int **ans);

	//// LU, Gaussian Elimination
	void SOLVE_LU(double **A, double* b, double *x, int m, double **L, double **U, double &det);
	

};

