#include <iostream>
#include "AbstractStack.h"

#ifndef LISTSTACK_H
#define LISTSTACK_H

template <class T> class Noeud //Noeud ou maillon de la liste chaînée
{
	template <class U> friend class ListStack;
	
	private :
	T data; //information contenu dans le noeud
	Noeud<T>* next;//pointeur vers le noeud suivant
	
	public :
	Noeud(T, Noeud<T>*);
	
	template <class U> friend void Pass(Noeud<U>**);//Permet a un noeud de passer au noeud suivant
	template <class U> friend ostream& operator<<(ostream&, Noeud<U>*);
};

/**************************************************************/

template <class T> class ListStack : public AbstractStack<T>
{

	private :
	Noeud<T>* top; //pointeur vers le noeud situé en haut de la pile
	int size;//taille de le pile
	
	public :
	ListStack(T);
	ListStack();
	
	bool isEmpty();
	void push(T);
	T pop();
	T getTop();
	~ListStack();
	
	bool operator==(ListStack<T>);
	template <class U> friend ostream& operator<<(ostream&, ListStack<U>&);

};


#endif
