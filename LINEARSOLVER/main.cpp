


int main() {
	return 0;
}


std::string GetCurrentWorkingDir1()
{
	std::string cwd("\0", FILENAME_MAX);
	return _getcwd(&cwd[0], cwd.capacity());
}
