#include "AbstractStack.h"

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

template<class T> class ArrayStack : public AbstractStack<T>
{
	private :
	T* tab=new T[200];
	int top;//Indice dans le tableau indiquant où est le haut de la pile
	
	public :
	ArrayStack(T);
	ArrayStack();
	
	bool isEmpty();
	void push(T);
	T pop();
	T getTop();
	~ArrayStack();
	
	bool operator==(ArrayStack<T>);
	template<class U> friend ostream& operator<<(ostream&, ArrayStack<U>&);
};


#endif
