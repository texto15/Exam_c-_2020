#include "ArrayStack.h"
#include "ExceptionStack.h"
#include <vector>



template <class T> ArrayStack<T>::ArrayStack(T x)
{
	tab[0]=x; // Le tableau est initialisé avec un élément
	top=0; // on met le repère en haut de la pile qui se trouve à tab[0], donc top=0
}

/********************************************************************/

template <class T> ArrayStack<T>::ArrayStack()
{
	top=-1; // l'objet est crée avec un tableau vide, on place le répère à -1 pour savoir que la pile est vide
}

/********************************************************************/

template <class T> bool ArrayStack<T>::isEmpty()
{
	if ((top+1)==0) //La pile est vide si top==-1, c-a-d top+1=0
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

/********************************************************************/

template <class T> void ArrayStack<T>::push(T x)
{
	
	if ((top+1)==200) //On vérifie que la limite du tableau n'est pas atteinte
	{
		throw ExceptionStack("Taille maximale atteinte : empilement impossible");
	}
	top++; //On déplace le repère d'un cran 
	tab[top]=x;//On place l'élément en haut de la pile
}

/********************************************************************/

template <class T> T ArrayStack<T>::pop()
{
	
	if ((top+1)==0) //On verifie si la pile est vide
	{
		throw ExceptionStack("Pile vide : dépilement impossible");
	}
	
	T x=tab[top];//On stocke la valeur de top pour pouvoir la retourner
	top--;//La pile perd un élément, donc le répère descend de 1
	
	return(x);
}

/*******************************************************************/

template <class T> T ArrayStack<T>::getTop()
{
	
	if ((top+1)==0) //On verifie si la pile est vide
	{
		throw ExceptionStack("Pile vide : rien à retourner");
	}
	
	T x=tab[top]; //On renvoie l'élément au top
	return(x);
}

/*********************************************************************/

template <class T> bool ArrayStack<T>::operator==(ArrayStack<T> p)
{
	bool b=true;
	int i=0;
	
	if (this->top != p.top) //Si les deux pile ne font pas la meme taille
	{
		b=false;//elle ne sont pas égales
	}
	
	else
	{
		while(i<=top and b==true)//tant qu'on a pas parcouru toute la pile et qu'elle sont égales
		{
			if (this->tab[i] != p.tab[i]) //Si l'éléments i des deux piles est différent
			{
				b=false;//les piles sont différentes
			}
			
			i++;
		}
	}
	
	return b;
}

/*********************************************************************/

template <class T> ostream& operator<<(ostream& flot, ArrayStack<T>& p)
{
	int i=0;
	
	flot << "bas de la pile -> " ;
	
	for (i=0;i<=p.top;i++)
	{
		flot << " | " << p.tab[i] ;
	}
	
	flot << " -> haut de la pile";
	return flot;
}

/************************************************************************/

template <class T> ArrayStack<T>::~ArrayStack()
{
	delete tab;
}

template class ArrayStack<char>;




