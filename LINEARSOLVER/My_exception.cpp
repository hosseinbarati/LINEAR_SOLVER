
#include "My_exception.h"

My_exception::My_exception(string errorMessage) : msg(errorMessage) {}

My_exception::~My_exception() {

}


const char* My_exception::what() const throw() {
	return msg.c_str();
}