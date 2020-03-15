#pragma once
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include"My_exception.h"
#include"error_code.h"

#define MAX_STRING_LENGTH 256
using namespace std;

class My_fstream : public fstream
{
public:
	My_fstream();
	~My_fstream();
	int FileSearch(char*);
	int ReadWord(char*);

	//// reading compositional data
	int readMatrix(int &row, int &col, double **A, string File_ADDRESS);
	int readVector(int &size, double *a, string File_ADDRESS);

};

