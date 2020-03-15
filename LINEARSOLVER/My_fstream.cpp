
#include "My_fstream.h"


My_fstream::My_fstream()
{
}


My_fstream::~My_fstream()
{
}


int My_fstream::FileSearch(char *rSeek) {
	register int i;
	char str[MAX_STRING_LENGTH];

	clear();                 // clear fail and eof bits
	seekg(0, std::ios::beg); // back to the start!
	*str = '\0';
	do {
		i = ReadWord(str);
		if (!strcmp(str, rSeek)) return -1;
	} while (i);

	return 0;		//Nothing found
}

int My_fstream::ReadWord(char *rWord) {
	char ch;
	register int i = 0;

	*rWord = '\0';
	do {
		get(ch);
		if (eof()) {
			return 0;		//Nothing has been read
		}
	} while ((ch < 33) || (ch > 126));

	while ((ch > 32) && (ch < 127)) {
		*(rWord + i) = ch;
		i++;
		get(ch);
		if (eof()) {
			*(rWord + i) = '\0';
			return 1;		//Read, but end of file also encountered
		}
	}

	*(rWord + i) = '\0';
	return -1;		//Correct execution
}

int My_fstream::readMatrix(int &row, int &col, double **A, string File_ADDRESS){
	char str[MAX_STRING_LENGTH];
	My_fstream pvtFile;
	pvtFile.open(File_ADDRESS, ios::in);
	if (pvtFile.is_open()) {
		if (A == nullptr) {
			{char keyword[] = "SIZE";
			if (!pvtFile.FileSearch(keyword)) My_exception(R0002);
			}
			{char keyword[] = "row";
			if (!pvtFile.FileSearch(keyword)) My_exception(R0003);
			if (!pvtFile.ReadWord(str)) My_exception(R0004);
			row = atoi(str);
			}

			{char keyword[] = "col";
			if (!pvtFile.FileSearch(keyword)) My_exception(R0005);
			if (!pvtFile.ReadWord(str)) My_exception(R0006);
			col = atoi(str);
			}
		}
		else {
			{char keyword[] = "matrix";
			if (!pvtFile.FileSearch(keyword)) My_exception(R0007);
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (!pvtFile.ReadWord(str)) My_exception(R0008);
					A[i][j] = atof(str);
				}
			}
			}
		}
	}

	else {
		My_exception(R0001);
	}
	return 0;
}

int My_fstream::readVector(int &size, double *a, string File_ADDRESS) {
	char str[MAX_STRING_LENGTH];
	My_fstream pvtFile;
	pvtFile.open(File_ADDRESS, ios::in);
	if (pvtFile.is_open()) {
		if (a == nullptr) {
			{char keyword[] = "SIZE";
			if (!pvtFile.FileSearch(keyword)) My_exception(R0002);
			if (!pvtFile.ReadWord(str)) My_exception(R0004);
			 size = atoi(str);
			}
		}
		else {
			{char keyword[] = "vector";
			if (!pvtFile.FileSearch(keyword)) My_exception(R0007);
			for (int i = 0; i < size; i++) {
				if (!pvtFile.ReadWord(str)) My_exception(R0008);
				a[i] = atof(str);
			}
			}
		}
	}

	else {
		My_exception(R0001);
	}
	return 0;
}
