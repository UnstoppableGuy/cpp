//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
#include <vcl.h>
//---------------------------------------------------------------------------
#endif

class Node
{
	public:
	int key;
	Node *Next;
};

class Stack
{
	public:
	Node *Head;
	Stack(){ Head= new Node; Head->key = -1;}
	void DeleteStack();
	void Push(int in);
	int Pop();
	int Top();
	bool Delete(int key);
	String ToString();
};

