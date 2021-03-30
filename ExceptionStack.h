#include <exception>
#include <iostream>

using namespace std;

#ifndef EXCEPTION_H
#define EXCEPTION_H

class ExceptionStack : public exception
{
	private :
	string data;
	public :
	ExceptionStack(string);
	string message();
};

#endif
