//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
#include <vcl.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#endif
class Tree
{
	int key;
	String line;
	unsigned char heighttr;
	Tree* Left, *Right;

	public:
	Tree(int info, String newline)
	{
		key = info;
		line = newline;
		Left = NULL;
		Right = NULL;
    }
	bool IsNull(Tree *Root); 	
	void FindInfo(Tree* Root, int findkey);

	void PrintTree(Tree *Root, int ind);
	void PrintInOrder (Tree *Root); 
	void PrintDirect (Tree *Root);
	void PrintReverse (Tree *Root);

	Tree* Remove(Tree* Root, int findkey);
	void DeleteTree(Tree *Root);
	Tree* Insert(Tree* Root, int info, String line);
	unsigned char Height(Tree* Root);
	int BalanceFactor(Tree* Root);
	void FixHeight(Tree* Root); 
	Tree* RotateRight(Tree *Root); 
	Tree* RotateLeft(Tree *Root);
	Tree* Balance(Tree* Root); 

	Tree* Findmin(Tree* Root); 
	Tree* Removemin(Tree* Root);
	int Complete(Tree* tr);

};