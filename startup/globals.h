#pragma once
#include<string>
#//include<iomanip>
#include <direct.h>
#define GetCurrentDir _getcwd
#include <stdio.h>  // defines FILENAME_MAX

static std::string GetCurrentWorkingDir()
{
	std::string cwd("\0", FILENAME_MAX);
	return _getcwd(&cwd[0], cwd.capacity());
}

static bool AlmostEqual(double Expected, double Actual, double tol) {
	if (abs(Expected - Actual) < tol)
	{
		return true;
	}
	else {
		return false;
	}
}
