#pragma once
#include<exception>
#include<iostream>
//#include"error_code.h"
using namespace std;




class My_exception : public exception
{
public:
	My_exception(string);
	~My_exception();

	const char* what() const throw();

private:
	string msg;
};

