#include "stdafx.h"
#include "CppUnitTest.h"
#include "preliminaries.h"
#include "My_fstream.h"
#include "globals.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace preliminaries_benchmark
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(reading_matrix01)
		{
			std::string FILE_ADDRESS = GetCurrentWorkingDir();
			FILE_ADDRESS.erase(FILE_ADDRESS.end() - 9, FILE_ADDRESS.end());
			FILE_ADDRESS = FILE_ADDRESS + "preliminaries_benchmark\\LINEARSOLVER\\reading_matrix.txt";
			int row, col;
			double **A;
			My_fstream fstreamObj;
			fstreamObj.readMatrix(row, col, nullptr, FILE_ADDRESS);
			A = new double*[row];
			for (int i = 0; i < row; i++) {
				A[i] = new double[col];
			}
			fstreamObj.readMatrix(row, col, A, FILE_ADDRESS);

			bool check;
			if ((A[0][0] == 1.5) && (A[0][1] == 5.6) && (A[0][2] == -6.1) && (A[0][3] == -63.74) && (A[0][4] == 98.1257)
				&& (A[1][0] == 2.612) && (A[1][1] == -6.0) && (A[1][2] == 9.686) && (A[1][3] == 0.0) && (A[1][4] == -0.000001)
				&& (A[2][0] == -0.35) && (A[2][1] == 8.6) && (A[2][2] == 96) && (A[2][3] == 696) && (A[2][4] == 6.211111)
				&& (A[3][0] == 6.982) && (A[3][1] == -9.34) && (A[3][2] == 9.68) && (A[3][3] == 7.86) && (A[3][4] == -6.365)
				&& (A[4][0] == -0.7896) && (A[4][1] == 0) && (A[4][2] == 9) && (A[4][3] == 6.6) && (A[4][4] == 4.01)) {
				check = true;
			}
			else {
				check = false;
			}

			Assert::IsTrue(check);
		}
		
		TEST_METHOD(matrix_summation01) {
			std::string FILE_ADDRESS = GetCurrentWorkingDir();
			FILE_ADDRESS.erase(FILE_ADDRESS.end() - 9, FILE_ADDRESS.end());
			FILE_ADDRESS = FILE_ADDRESS + "preliminaries_benchmark\\LINEARSOLVER\\reading_matrix.txt";
			int row, col;
			double **A, **B, ** ans;
			My_fstream fstreamObj;
			fstreamObj.readMatrix(row, col, nullptr, FILE_ADDRESS);
			A = new double*[row];
			B = new double*[row];
			ans = new double*[row];
			for (int i = 0; i < row; i++) {
				A[i] = new double[col];
				B[i] = new double[col];
				ans[i] = new double[col];
			}
			fstreamObj.readMatrix(row, col, A, FILE_ADDRESS);
			fstreamObj.readMatrix(row, col, B, FILE_ADDRESS);

			preliminaries preliminariesObj;
			preliminariesObj.MatSum(A, B, row, col, ans);

			bool check;
			if ((ans[0][0] == 1.5 * 2) && (ans[0][1] == 5.6 * 2) && (ans[0][2] == -6.1 * 2) && (ans[0][3] == -63.74 * 2) && (ans[0][4] == 98.1257 * 2)
				&& (ans[1][0] == 2.612 * 2) && (ans[1][1] == -6.0 * 2) && (ans[1][2] == 9.686 * 2) && (ans[1][3] == 0.0 * 2) && (ans[1][4] == -0.000001 * 2)
				&& (ans[2][0] == -0.35 * 2) && (ans[2][1] == 8.6 * 2) && (ans[2][2] == 96 * 2) && (ans[2][3] == 696 * 2) && (ans[2][4] == 6.211111 * 2)
				&& (ans[3][0] == 6.982 * 2) && (ans[3][1] == -9.34 * 2) && (ans[3][2] == 9.68 * 2) && (ans[3][3] == 7.86 * 2) && (ans[3][4] == -6.365 * 2)
				&& (ans[4][0] == -0.7896 * 2) && (ans[4][1] == 0 * 2) && (ans[4][2] == 9 * 2) && (ans[4][3] == 6.6 * 2) && (ans[4][4] == 4.01 * 2)) {
				check = true;
			}
			else {
				check = false;
			}

			Assert::IsTrue(check);

		}
		
		TEST_METHOD(matrix_summation02) {
			int rowA, colA, rowB, colB, rowC, colC;
			double **A, **B, **C, **ans;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixA.txt";
			fstreamObj.readMatrix(rowA, colA, nullptr, FILE_ADDRESS);
			A = new double*[rowA];
			for (int i = 0; i < rowA; i++) {
				A[i] = new double[colA];
			}
			fstreamObj.readMatrix(rowA, colA, A, FILE_ADDRESS);

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixB.txt";
			fstreamObj.readMatrix(rowB, colB, nullptr, FILE_ADDRESS);
			B = new double*[rowB];
			for (int i = 0; i < rowB; i++) {
				B[i] = new double[colB];
			}
			fstreamObj.readMatrix(rowB, colB, B, FILE_ADDRESS);


			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixC_SUM.txt";
			fstreamObj.readMatrix(rowC, colC, nullptr, FILE_ADDRESS);
			C = new double*[rowC];
			for (int i = 0; i < rowC; i++) {
				C[i] = new double[colC];
			}
			fstreamObj.readMatrix(rowC, colC, C, FILE_ADDRESS);

			ans = new double*[rowA];
			for (int i = 0; i < rowA; i++) {
				ans[i] = new double[colA];
			}

			preliminaries preliminariesObj;
			preliminariesObj.MatSum(A, B, rowA, colA, ans);

			bool check = true;
			for (int i = 0; i < rowA; i++) {
				for (int j = 0; j < colB; j++) {
					if (!AlmostEqual(ans[i][j], C[i][j], 1e-6)) {
						check = false;
						break;
					}
				}
			}

			Assert::IsTrue(check);
		}

		TEST_METHOD(matrix_summation03) {
			int rowA, colA, rowB, colB, rowC, colC;
			double **A, **B, **C, **ans;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixA_rec0.txt";
			fstreamObj.readMatrix(rowA, colA, nullptr, FILE_ADDRESS);
			A = new double*[rowA];
			for (int i = 0; i < rowA; i++) {
				A[i] = new double[colA];
			}
			fstreamObj.readMatrix(rowA, colA, A, FILE_ADDRESS);

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixB_rec0.txt";
			fstreamObj.readMatrix(rowB, colB, nullptr, FILE_ADDRESS);
			B = new double*[rowB];
			for (int i = 0; i < rowB; i++) {
				B[i] = new double[colB];
			}
			fstreamObj.readMatrix(rowB, colB, B, FILE_ADDRESS);


			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixC_SUM_rec0.txt";
			fstreamObj.readMatrix(rowC, colC, nullptr, FILE_ADDRESS);
			C = new double*[rowC];
			for (int i = 0; i < rowC; i++) {
				C[i] = new double[colC];
			}
			fstreamObj.readMatrix(rowC, colC, C, FILE_ADDRESS);

			ans = new double*[rowA];
			for (int i = 0; i < rowA; i++) {
				ans[i] = new double[colA];
			}

			preliminaries preliminariesObj;
			preliminariesObj.MatSum(A, B, rowA, colA, ans);
			
			bool check = true;
			for (int i = 0; i < rowA; i++) {
				for (int j = 0; j < colA; j++) {
					if (!AlmostEqual(ans[i][j], C[i][j], 1e-6)) {
						check = false;
						break;
					}
				}
			}

			Assert::IsTrue(check);
		}

		TEST_METHOD(matrix_AB_equlas_C01) {
			int rowA, colA, rowB, colB, rowC, colC;
			double **A, **B, **C, **ans;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixA.txt";
			fstreamObj.readMatrix(rowA, colA, nullptr, FILE_ADDRESS);
			A = new double*[rowA];
			for (int i = 0; i < rowA; i++) {
				A[i] = new double[colA];
			}
			fstreamObj.readMatrix(rowA, colA, A, FILE_ADDRESS);

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixB.txt";
			fstreamObj.readMatrix(rowB, colB, nullptr, FILE_ADDRESS);
			B = new double*[rowB];
			for (int i = 0; i < rowB; i++) {
				B[i] = new double[colB];
			}
			fstreamObj.readMatrix(rowB, colB, B, FILE_ADDRESS);


			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixC.txt";
			fstreamObj.readMatrix(rowC, colC, nullptr, FILE_ADDRESS);
			C = new double*[rowC];
			for (int i = 0; i < rowC; i++) {
				C[i] = new double[colC];
			}
			fstreamObj.readMatrix(rowC, colC, C, FILE_ADDRESS);
			
			ans = new double*[rowA];
			for (int i = 0; i < rowA; i++) {
				ans[i] = new double[colB];
			}

			preliminaries preliminariesObj;
			preliminariesObj.MatMul(A, rowA, colA, B, colB, ans);

			bool check = true;
			for (int i = 0; i < rowA; i++) {
				for (int j = 0; j < colB; j++) {
					if (!AlmostEqual(ans[i][j], C[i][j], 1e-6)){
						check = false;
						break;
					}
				}
			}

			Assert::IsTrue(check);
		}

		TEST_METHOD(matrix_AB_equlas_C02) {
			int rowA, colA, rowB, colB, rowC, colC;
			double **A, **B, **C, **ans;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixA_rec.txt";
			fstreamObj.readMatrix(rowA, colA, nullptr, FILE_ADDRESS);
			A = new double*[rowA];
			for (int i = 0; i < rowA; i++) {
				A[i] = new double[colA];
			}
			fstreamObj.readMatrix(rowA, colA, A, FILE_ADDRESS);

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixB_rec.txt";
			fstreamObj.readMatrix(rowB, colB, nullptr, FILE_ADDRESS);
			B = new double*[rowB];
			for (int i = 0; i < rowB; i++) {
				B[i] = new double[colB];
			}
			fstreamObj.readMatrix(rowB, colB, B, FILE_ADDRESS);


			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixC_MUL_rec.txt";
			fstreamObj.readMatrix(rowC, colC, nullptr, FILE_ADDRESS);
			C = new double*[rowC];
			for (int i = 0; i < rowC; i++) {
				C[i] = new double[colC];
			}
			fstreamObj.readMatrix(rowC, colC, C, FILE_ADDRESS);

			ans = new double*[rowA];
			for (int i = 0; i < rowA; i++) {
				ans[i] = new double[colB];
			}

			preliminaries preliminariesObj;
			preliminariesObj.MatMul(A, rowA, colA, B, colB, ans);

			bool check = true;
			for (int i = 0; i < rowA; i++) {
				for (int j = 0; j < colB; j++) {
					if (!AlmostEqual(ans[i][j], C[i][j], 1e-6)) {
						check = false;
						break;
					}
				}
			}

			Assert::IsTrue(check);
		}

		TEST_METHOD(vector_dot_ab_equlas_c) {
			int size_a, size_b;
			double *a, *b, ans;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\vector_a.txt";
			fstreamObj.readVector(size_a, nullptr, FILE_ADDRESS);
			a = new double[size_a];
			fstreamObj.readVector(size_a, a, FILE_ADDRESS);

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\vector_b.txt";
			fstreamObj.readVector(size_b, nullptr, FILE_ADDRESS);
			b = new double[size_b];
			fstreamObj.readVector(size_b, b, FILE_ADDRESS);

			double expected = 2.111505541029950e+03;
		
			preliminaries preliminariesObj;
			preliminariesObj.innerProduct(a, b, size_a, ans);
			Assert::IsTrue(AlmostEqual(expected, ans, 1e-6));
		}

		TEST_METHOD(matrix_transpose) {
			int rowA, colA, row_AT, col_AT;
			double **A, **AT,**ans;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixA_rec0.txt";
			fstreamObj.readMatrix(rowA, colA, nullptr, FILE_ADDRESS);
			A = new double*[rowA];
			for (int i = 0; i < rowA; i++) {
				A[i] = new double[colA];
			}
			fstreamObj.readMatrix(rowA, colA, A, FILE_ADDRESS);

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixA_rec0_T.txt";
			fstreamObj.readMatrix(row_AT, col_AT, nullptr, FILE_ADDRESS);
			AT = new double*[row_AT];
			for (int i = 0; i < row_AT; i++) {
				AT[i] = new double[col_AT];
			}
			fstreamObj.readMatrix(row_AT, col_AT, AT, FILE_ADDRESS);

			ans = new double*[colA];
			for (int i = 0; i < colA; i++) {
				ans[i] = new double[rowA];
			}

			preliminaries preliminariesObj;
			preliminariesObj.MatTranspose(A, rowA, colA, ans);
			
			bool check = true;
			for (int i = 0; i < row_AT; i++) {
				for (int j = 0; j < col_AT; j++) {
					if (!AlmostEqual(ans[i][j], AT[i][j], 1e-6)) {
						check = false;
						break;
					}
				}
			}

			Assert::IsTrue(check);
		}

		TEST_METHOD(vecMat_MUL01) {

			int row, col, size;
			double **A, *a, *c, *ans;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixA_rec0.txt";
			fstreamObj.readMatrix(row, col, nullptr, FILE_ADDRESS);
			A = new double*[row];
			for (int i = 0; i < row; i++) {
				A[i] = new double[col];
			}
			fstreamObj.readMatrix(row, col, A, FILE_ADDRESS);

			ans = new double[col];

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\vectora_0.txt";
			fstreamObj.readVector(size, nullptr, FILE_ADDRESS);
			a = new double[size];
			fstreamObj.readVector(size, a, FILE_ADDRESS);


			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\vectorc_0.txt";
			fstreamObj.readVector(size, nullptr, FILE_ADDRESS);
			c = new double[size];
			fstreamObj.readVector(size, c, FILE_ADDRESS);

			preliminaries preliminariesObj;
			preliminariesObj.VecMatMul(A, a, row, col, ans);

			bool check = true;

			for (int i = 0; i < col; i++) {
				if (!AlmostEqual(ans[i], c[i], 1e-6)) {
					check = false;
					break;
				}
			}

			Assert::IsTrue(check);
		}

		TEST_METHOD(MatVec_MUL01) {

			int row, col, size;
			double **A, *a, *c, *ans;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixA_rec0.txt";
			fstreamObj.readMatrix(row, col, nullptr, FILE_ADDRESS);
			A = new double*[row];
			for (int i = 0; i < row; i++) {
				A[i] = new double[col];
			}
			fstreamObj.readMatrix(row, col, A, FILE_ADDRESS);

			ans = new double[col];

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\vectora_matvec_01.txt";
			fstreamObj.readVector(size, nullptr, FILE_ADDRESS);
			a = new double[size];
			fstreamObj.readVector(size, a, FILE_ADDRESS);


			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\vectorC_matVec01.txt";
			fstreamObj.readVector(size, nullptr, FILE_ADDRESS);
			c = new double[size];
			fstreamObj.readVector(size, c, FILE_ADDRESS);

			preliminaries preliminariesObj;
			preliminariesObj.MatVecMul(A, a, row, col, ans);
			
			bool check = true;

			for (int i = 0; i < col; i++) {
				if (!AlmostEqual(ans[i], c[i], 1e-6)) {
					check = false;
					break;
				}
			}

			Assert::IsTrue(check);
		}

		TEST_METHOD(scalMatrix01)
		{
			
			int rowA, colA, rowB, colB;
			double **A, **B, **ans;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixA_rec0.txt";
			fstreamObj.readMatrix(rowA, colA, nullptr, FILE_ADDRESS);
			A = new double*[rowA];
			ans = new double*[rowA];
			for (int i = 0; i < rowA; i++) {
				A[i] = new double[colA];
				ans[i] = new double[colA];
			}
			fstreamObj.readMatrix(rowA, colA, A, FILE_ADDRESS);

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixBscalMat1.txt";
			fstreamObj.readMatrix(rowB, colB, nullptr, FILE_ADDRESS);
			B = new double*[rowB];
			for (int i = 0; i < rowB; i++) {
				B[i] = new double[colB];
			}
			fstreamObj.readMatrix(rowB, colB, B, FILE_ADDRESS);

			preliminaries preliminariesObj;
			preliminariesObj.ScalMatMul(A, -2.63, rowA, colA, ans);

			bool check = true;
			for (int i = 0; i < rowA; i++) {
				for (int j = 0; j < colA; j++) {
					if (!AlmostEqual(ans[i][j], B[i][j], 1e-6)) {
						check = false;
						break;
					}
				}
			}

			Assert::IsTrue(check);
		}

		TEST_METHOD(scalVec01)
		{

			int size_a, size_b;
			double *a, *b, *ans;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\vector_a.txt";
			fstreamObj.readVector(size_a, nullptr, FILE_ADDRESS);
			a = new double[size_a];
			ans = new double[size_a];
			fstreamObj.readVector(size_a, a, FILE_ADDRESS);

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\vectorb_scal_vec_a.txt";
			fstreamObj.readVector(size_b, nullptr, FILE_ADDRESS);
			b = new double[size_a];
			fstreamObj.readVector(size_b, b, FILE_ADDRESS);

			preliminaries preliminariesObj;
			preliminariesObj.scalerVecMul(-2.964, a, size_a, ans);
			bool check = true;
			for (int i = 0; i < size_a; i++) {
				if (!AlmostEqual(ans[i], b[i], 1e-6)) {
					check = false;
					break;
				}
			}

			Assert::IsTrue(check);
		}

		TEST_METHOD(LU01) {

			int row, col;
			double **A, **L, **U, *b, *x, *ans, det;
			My_fstream fstreamObj;
			std::string BENCHMARK_FOLDER = GetCurrentWorkingDir();
			BENCHMARK_FOLDER.erase(BENCHMARK_FOLDER.end() - 9, BENCHMARK_FOLDER.end());
			string FILE_ADDRESS;
			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\matrixA.txt";
			fstreamObj.readMatrix(row, col, nullptr, FILE_ADDRESS);
			A = new double*[row];
			L = new double*[row];
			U = new double*[row];
			for (int i = 0; i < row; i++) {
				A[i] = new double[col];
				L[i] = new double[col];
				U[i] = new double[col];
			}
			fstreamObj.readMatrix(row, col, A, FILE_ADDRESS);

			ans = new double[col];

			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\vector_b_Axb.txt";
			fstreamObj.readVector(col, nullptr, FILE_ADDRESS);
			b = new double[col];
			fstreamObj.readVector(col, b, FILE_ADDRESS);


			FILE_ADDRESS = BENCHMARK_FOLDER + "preliminaries_benchmark\\LINEARSOLVER\\Axb.txt";
			fstreamObj.readVector(col, nullptr, FILE_ADDRESS);
			x = new double[col];
			fstreamObj.readVector(col, x, FILE_ADDRESS);

			preliminaries preliminariesObj;


			//preliminariesObj.SOLVE_LU(A, b, ans, row, nullptr, nullptr, det);	// if there is no need for L or U
			preliminariesObj.SOLVE_LU(A, b, ans, row, L, U, det);
			

			bool check = true;

			for (int i = 0; i < col; i++) {
				if (!AlmostEqual(ans[i], x[i], 1e-6)) {
					check = false;
					break;
				}
			}

			Assert::IsTrue(check);
		}


	};
}