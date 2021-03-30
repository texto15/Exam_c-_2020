#include "ArrayStack.h"
#include "ListStack.h"
#include "ExceptionStack.h"
#include <iostream>

bool PbArrayStack(string& , int);
bool PbListStack(string& , int);

/*************************************************************************/

bool PbArrayStack(string& s, int taille /*de char* s*/ ) //Resolution du problème posé à la question 2 par ArrayStack
{
	int i=0;
	ArrayStack<char> p1;
	for (i=0;i<taille;i++)
	{
		if(p1.isEmpty()) //Si la pile est vide on met la première parenthèse rencontrée dans la pile
		{
			if (s[i]=='[' or s[i]=='(' or s[i]=='{')
			{
				p1.push(s[i]);
			}
		}
		
		else
		{
		
			if(s[i]==']' and p1.getTop()=='[') //On vérifie si la parenthèse de s[i] est complémentaire de la dernière parenthèse (stockée dans top)
			{
				p1.pop(); //Si c'est le cas, la paire est correcte, on dépile
			}
			
			else if(s[i]=='}' and p1.getTop()=='{') //On vérifie si la parenthèse de s[i] est complémentaire de la dernière parenthèse (stockée dans top)
			{
				p1.pop(); //Si c'est le cas, la paire est correcte, on dépile
			}
			
			else if(s[i]==')' and p1.getTop()=='(') //On vérifie si la parenthèse de s[i] est complémentaire de la dernière parenthèse (stockée dans top)
			{
				p1.pop(); //Si c'est le cas, la paire est correcte, on dépile
			}
			
			else if (s[i]=='[' or s[i]=='(' or s[i]=='{' or s[i]==']' or s[i]==')' or s[i]=='}') //Si elles ne sont pas complémentaires, on l'ajoute à la pile
			{
				p1.push(s[i]);
			}
		}
		
	}
	
	//Une fois qu'on a parcouru toute la chaîne de caractère, si la pile est vide, alors on a reconstitué toutes les paires de parenthèses, donc celle-ci était équilibrée. Si la pile n'est pas vide, les parenthèses ne sont pas équilibrée
	
	if (p1.isEmpty())
	{
		return true;
	}
	
	else 
	{
		return false;
	}
}

/*****************************************************************/

bool PbListStack(string& s, int taille /*de char* s*/ ) //Resolution du problème posé à la question 2 par ArrayStack
{
	int i=0;
	ListStack<char> p1;
	for (i=0;i<taille;i++)
	{
		if(p1.isEmpty()) //Si la pile est vide on met la première parenthèse rencontrée dans la pile
		{
			if (s[i]=='[' or s[i]=='(' or s[i]=='{')
			{
				p1.push(s[i]);
			}
		}
		
		else
		{
		
			if(s[i]==']' and p1.getTop()=='[') //On vérifie si la parenthèse de s[i] est complémentaire de la dernière parenthèse (stockée dans top)
			{
				p1.pop(); //Si c'est le cas, la paire est correcte, on dépile
			}
			
			else if(s[i]=='}' and p1.getTop()=='{') //On vérifie si la parenthèse de s[i] est complémentaire de la dernière parenthèse (stockée dans top)
			{
				p1.pop(); //Si c'est le cas, la paire est correcte, on dépile
			}
			
			else if(s[i]==')' and p1.getTop()=='(') //On vérifie si la parenthèse de s[i] est complémentaire de la dernière parenthèse (stockée dans top)
			{
				p1.pop(); //Si c'est le cas, la paire est correcte, on dépile
			}
			
			else if (s[i]=='[' or s[i]=='(' or s[i]=='{' or s[i]==']' or s[i]==')' or s[i]=='}') //Si elles ne sont pas complémentaires, on l'ajoute à la pile
			{
				p1.push(s[i]);
			}
		}
		
	}
	
	//Une fois qu'on a parcouru toute la chaîne de caractère, si la pile est vide, alors on a reconstitué toutes les paires de parenthèses, donc celle-ci était équilibrée. Si la pile n'est pas vide, les parenthèses ne sont pas équilibrée
	
	
	if (p1.isEmpty())
	{
		return true;
	}
	
	else 
	{
		return false;
	}
}

/*****************************************************************/

int main()
{
	string testa="[(a+b)]c/d[(x*y)*(c+y)]", testb="[(a+b])";
	
	/*******************************/
	
	cout << "Test avec ArrayStack" << endl;
	
	cout << testa << " a des parenthèses équilibrées : ";
	
	if (PbArrayStack(testa, testa.size()) == true)
	{
		cout << "vrai" << endl;
	}
	
	else
	{
		cout << "faux" << endl;
	}
	
	
	cout << testb << " a des parenthèses équilibrées : ";
	
	if (PbArrayStack(testb, testb.size()) == true)
	{
		cout << "vrai" << endl;
	}
	
	else
	{
		cout << "faux" << endl;
	}
	
	cout << endl;
	/**********************************/
	
	cout << "Test avec ListStack" << endl;
	
	cout << testa << " a des parenthèses équilibrées : ";
	
	if (PbListStack(testa, testa.size()) == true)
	{
		cout << "vrai" << endl;
	}
	
	else
	{
		cout << "faux" << endl;
	}
	
	
	cout << testb << " a des parenthèses équilibrées : ";
	
	if (PbListStack(testb, testb.size()) == true)
	{
		cout << "vrai" << endl;
	}
	
	else
	{
		cout << "faux" << endl;
	}
	
	
	
	/* Test d'une exception*/
	/*
	ListStack<char> p;
	int i;
	try
	{
		for (i=0;i<300;i++)
		{
			p.push('a');
		}
	}
	
	catch (ExceptionStack& e)
	{
		cout << e.message() << endl;
	}
	*/
	
	
	return 0;
}
























