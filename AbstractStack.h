#include <iostream>

#ifndef PILEABSTRAITE_H
#define PILEABSTRAITE_H

using namespace std;

template<class T> class AbstractStack
{
	public :
	virtual bool isEmpty()=0;
	virtual void push(T)=0;
	virtual T pop()=0;
	virtual T getTop()=0;
};

#endif
