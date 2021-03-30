#include "ExceptionStack.h"

using namespace std;

ExceptionStack::ExceptionStack(string message)
{
	this->data=message;
}

/**********************************************************/

string ExceptionStack::message()
{
	return (this->data);
}
