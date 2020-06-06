//---------------------------------------------------------------------------

#pragma hdrstop

#include "DoubleList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Doublelist::newShow()
{
	Node* temp = Tail;
	temp = Head;
	//�������� ��������� �� ����� ������� ��������
	while (temp != NULL) {
		//���� �� �������� ������ ��������
		//cout<<temp->x<<" ";
		//������� ������ ��������� �������� �� �����
		Form2->Memo2->Lines->Add(temp->x);
		//std::cout << temp->x << " ";
		//����� ������ �� ����� ���������� ��������
		temp = temp->Next;
	}
}
Doublelist::~Doublelist()
{
	while (Head)
	{     //���� �� ������ �� ������ ������ ���-�� ����
	 //��������� ����� ������ ���������� ����� ������
		Tail = Head->Next;
		delete Head; //������� ������ �� ������� �����
		//����� ������ ������ �� ����� ���������� ��������
		Head = Tail;
	}
}
void Doublelist:: list_remove()
{
		for (Node* p = Head; p != NULL; )
		{
			if (resolution(p,p->x) == true)
				p = list_delete(p);
			else
				p = p->Next;
		}
}
bool Doublelist::resolution(Node* x, int value)
{
		Node* temp = x->Prev; ;
		for (temp; temp != NULL;)
		{
			if (value == temp->x)
			{
				//std::cout << "returned true\n";
				return true;
			}
			else
				temp = temp->Prev;
		}
		return false;
}
Node* Doublelist::list_delete(Node* pos)
	{
		//std::cout << "struct with value " << pos->x << " deleted\n";
		Node* p;
		Node*& h = Head;
		Node*& t = Tail;
		if (pos == NULL)
			return NULL;
		else if (pos == h) {
			p = h = h->Next;
			if (h != NULL)
				h->Prev = NULL;
			else
				t = NULL;
		}
		else if (pos == t) {
			p = NULL;
			t = t->Prev;
			if (t != NULL)
				t->Next = NULL;
			else
				h = NULL;
		}
		else {
			pos->Prev->Next = pos->Next;
			pos->Next->Prev = pos->Prev;
			p = pos->Next;
		}
		delete pos;
		return p;
	}
