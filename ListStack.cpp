#include <iostream>
#include "ListStack.h"
#include "ExceptionStack.h"
using namespace std;

template <class T> Noeud<T>::Noeud(T data, Noeud* next)
{
	this->data = data;//On initialise le noeud à partir des paramètres
	this->next = next;
}

/****************************************************************/

template <class T> void Pass(Noeud<T>** tmp)
{
	*tmp=(*tmp)->next;//on passe au noeud suivant
}

/****************************************************************/

template <class T> ListStack<T>::ListStack()//Crée une liste vide
{
	top = NULL;
	size = 0;
}

/****************************************************************/

template <class T> ListStack<T>::ListStack(T x)//Crée une liste dont le top est x;
{
	top = NULL;
	size = 0;
	
	this->push(x);
}

/******************************************************************/

template <class T> void ListStack<T>::push(T x)
{
	Noeud<T>* nouveau = new Noeud<T>(x, top);//On crée le nouveau noeud à ajouter à la chaîne, placer en haut de la pile
	
	if (nouveau == NULL or size==200) //on fixe arbitrairement la taille maximale à 200 pour pouvoir génerer une exception
	{
		throw ExceptionStack("Impossible de créer un nouveau maillon\nTaille maximale atteinte");
	}
	
	top = nouveau;//Le haut de la pile est nouveau, donc top pointe sur le nouveau noeud
	size++;//la taille de la pile augmente de 1
}

/*******************************************************************/

template <class T> T ListStack<T>::pop()
{
	
	if (size==0)//On verifie si la pile est vide
	{
		throw ExceptionStack("Pile vide : dépilement impossible");
	}
	
	T x = top->data;//On sauvegarde l'information à retourner
	Noeud<T>* tmp = top;//On garde en mémoire l'ancien top pour pouvoir suprimer son noeud
	top = top->next;//L'élément du dessus de la pile est maitenant l'élément suivant 
	delete tmp;//on suprime l'ancien top
	size--;//la taille de la pile diminue 
	return x;
}

/*******************************************************************/

template <class T> T ListStack<T>::getTop()
{
	if (size==0)//On verifie si la pile est vide
	{
		throw ExceptionStack("Pile vide : rien à retourner");
	}
	
	return top->data;
}

/********************************************************************/

template <class T> bool ListStack<T>::isEmpty()
{
	if (size==0)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

/***********************************************************************/


template <class T> bool ListStack<T>::operator==(ListStack<T> p)
{
	bool b=true;
	int i=0;
	Noeud<T> *tmp1=this->top, *tmp2=p.top;
	
	
	if (this->size != p.size)//On verifie si les taille des deux piles sont égales
	{
		b=false;
	}
	
	else
	{
		while(i<size and b==true)//tant qu'on a pas verifier toute la pile et qu'elles sont encore égales
		{
			if (tmp1->data != tmp2->data)//Si l'information contenu dans deux noeud de même indice dans les piles sont différents
			{
				b=false;
			}
			
			tmp1=tmp1->next;//On passe au noeud suivant
			tmp2=tmp2->next;//On passe au noeud suivant
			i++;
		}
	}
	
	return b;
}

/*********************************************************************/

template <class T> ostream& operator<<(ostream& flot, ListStack<T>& p)
{
	int i=0;
	Noeud<T>* tmp;
	tmp=p.top;
	
	flot << "haut de la pile <- " ;
	
	for (i=0;i<p.size;i++)
	{
		flot << tmp << " | ";
		Pass(&tmp);
	}
	
	flot << " <- bas de la pile";
	return flot;
}

/************************************************************************/

template <class T> ostream& operator<<(ostream& flot, Noeud<T>* n)
{
	flot << n->data;
	return flot;
}

/***********************************************************************/

template <class T> ListStack<T>::~ListStack()
{
	while(size!=0)
	{
		this->pop();
	}
	
}

	template class ListStack<char>;






