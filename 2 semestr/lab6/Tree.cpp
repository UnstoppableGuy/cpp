//---------------------------------------------------------------------------


#pragma hdrstop

#include "Tree.h"
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
int number = 0;

bool Tree::IsNull(Tree* Root)
{
	return Root == NULL;
}

void Tree::DeleteTree(Tree* Root)
{
	if (IsNull(Root) == false)
	{
		DeleteTree(Root->Left);
		DeleteTree(Root->Right);
		delete Root;
	}
}

unsigned char Tree::Height(Tree* Root) 
{
	return Root ? Root->heighttr : 0;
}

int Tree::BalanceFactor(Tree* Root)
{
	return Height(Root->Right) - Height(Root->Left);
}

void Tree::FixHeight(Tree* Root)
{
	unsigned char hleft = Height(Root->Left);
	unsigned char hright = Height(Root->Right);
	Root->heighttr = (hleft > hright ? hleft : hright) + 1;
}

Tree* Tree::RotateRight(Tree* Root)
{
	Tree* q = Root->Left;
	Root->Left = q->Right;
	q->Right = Root;
	FixHeight(Root);
	FixHeight(q);
	return q;
}

Tree* Tree::RotateLeft(Tree* Root)
{
	Tree* p = Root->Right;
	Root->Right = p->Left;
	p->Left = Root;
	FixHeight(Root);
	FixHeight(p);
	return p;
}

Tree* Tree::Balance(Tree* Root)   
{
	FixHeight(Root);
	if (BalanceFactor(Root) == 2)
	{
		if (BalanceFactor(Root->Right) < 0)
		{
			Root->Right = RotateRight(Root->Right);
		}
		return RotateLeft(Root);
	}
	if (BalanceFactor(Root) == 1 && Root->Left == NULL)
		return RotateLeft(Root);
	if (BalanceFactor(Root) == -2)
	{
		if (BalanceFactor(Root->Left) > 0)
		{
			Root->Left = RotateLeft(Root->Left);
		}
		return RotateRight(Root);
	}
	if (BalanceFactor(Root) == -1 && Root->Right == NULL)
		return RotateRight(Root);
	return Root;  
}

Tree* Tree::Insert(Tree* Root, int info, String line)
{
	if (!Root) return new Tree(info, line);
	if (info < Root->key)
		Root->Left = Insert(Root->Left, info, line);
	else if (info > Root->key)
		Root->Right = Insert(Root->Right, info, line);
	return Balance(Root);
}

void Tree::PrintTree(Tree* Root, int ind) 
{
	{
		if (Root)
		{
			if (ind == -1)
				Form1->TreeView1->Items->Add(0, Root->key);
			else
				Form1->TreeView1->Items->AddChildFirst(Form1->TreeView1->Items->Item[ind], Root->key);
			ind++;
			PrintTree(Root->Left, ind);
			PrintTree(Root->Right, ind);
		}

	}
}

void Tree::FindInfo(Tree* Root, int findkey)
{
	if (IsNull(Root))
	{
		Application->Title = "Внимание";
		ShowMessage("Объект  не найден");
	}
	else if (findkey > Root->key)
		FindInfo(Root->Right, findkey);
	else if (findkey < Root->key)
		FindInfo(Root->Left, findkey);
	else
	{
		Application->Title = "Внимание";
		ShowMessage("Объект найден");
	  Form1->Memo1->Lines->Add("Word: " + Root->line + "| Key: " + IntToStr(Root->key));
	}
}
int Tree::Complete(Tree* tr)
{
	if (tr == NULL)
		return 0;
	int n = ((tr->Left != NULL) && (tr->Right != NULL));

	if (tr->Left != NULL)
		n += Complete(tr->Left);
	if (tr->Right != NULL)
		n += Complete(tr->Right);
	return n;
}

void Tree::PrintInOrder(Tree* Root)
{
	if (Root != NULL)
	{
		PrintInOrder(Root->Left);
		Form1->Memo1->Lines->Add("Word: " + Root->line + "| Key: " + IntToStr(Root->key));
		PrintInOrder(Root->Right);
	}
}

void Tree::PrintDirect(Tree* Root)
{
	if (Root != NULL)
	{
		Form1->Memo1->Lines->Add("Word: " + Root->line + "| Key: " + IntToStr(Root->key));
		PrintDirect(Root->Left);
		PrintDirect(Root->Right);
	}
}

void Tree::PrintReverse(Tree* Root)
{
	if (Root != NULL)
	{
		PrintInOrder(Root->Left);
		PrintInOrder(Root->Right);
		Form1->Memo1->Lines->Add("Word: " + Root->line + "| Key: " + IntToStr(Root->key));
	}
}

Tree* Tree::Findmin(Tree* Root)
{
	return Root->Left ? Findmin(Root->Left) : Root;
}

Tree* Tree::Removemin(Tree* Root)
{
	if (Root->Left == NULL)
		return Root->Right;
	Root->Left = Removemin(Root->Left);
	return Balance(Root);
}

Tree* Tree::Remove(Tree* Root, int findkey)
{
	if (!Root)
		return 0;
	if (findkey < Root->key)
		Root->Left = Remove(Root->Left, findkey);
	else if (findkey > Root->key)
		Root->Right = Remove(Root->Right, findkey);
	else
	{
		Tree* tempforleft = Root->Left;
		Tree* tempforright = Root->Right;
		delete Root;
		if (!tempforright) return tempforleft;
		Tree* min = Findmin(tempforright);
		min->Right = Removemin(tempforright);
		min->Left = tempforleft;
		return Balance(min);
	}
	return Balance(Root);
}


