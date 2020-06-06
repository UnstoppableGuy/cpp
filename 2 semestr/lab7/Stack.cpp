//---------------------------------------------------------------------------


#pragma hdrstop
#include "Stack.h"
#include <stddef.h>
#include <vcl.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)

void Stack::DeleteStack()
{
		Node *node = Head;
		Node *temp;
		while( node != NULL)
		{
			temp = node;
			node = node -> Next;
			delete temp;
		}
}
 void Stack::Push( int in)
{
		Node *node = new Node;
		if (Head->key == -1) {
			 Head->key = in;
		}
		else
		{
			node->key = in;
			node->Next = Head;
			Head = node;
		}
}
String Stack::ToString()
{
		if (Head->key == -1)
			return "->Nothing (0)";
		String output = "";
		Node *node = Head;
		int size=0;
		while (node != NULL)
		{
		   if (node->Next != NULL)
		   {
				output+="->";
				output+=node->key;
		   }
		   else
			{
            	output+="->";
				output+=IntToStr(node->key);
			}
			node = node->Next;
			size++;
		}
		output+="("+IntToStr(size)+")";
		return  output;
}
int Stack::Pop()
{
		int info = Head->key;
		Node *temp = Head;
		Head = Head->Next;
		delete temp;
		return info;
}
bool Stack::Delete(int Key)
{
		if (Head->key == -1) {
		   return false;
		}
		Node *node = Head;
		if (Head->key ==Key) {
			if (Head->Next == NULL)
				Head->key = -1;
			 else Head = Head->Next;
		}
			if (node != Head) {
			 Head = node->Next;
			 delete node;
			 return true;
			}
		while (node->Next != NULL)
		{
			if (node->Next->key == Key) {
			   Node *temp = node->Next;
			   node->Next = temp->Next;
			   delete temp;
			   return true;
			}
			else node = node->Next;
		}
		return false;
}

int Stack::Top()
{
	if (Head!= NULL)
	{
		 return Head->key;
	}
}
