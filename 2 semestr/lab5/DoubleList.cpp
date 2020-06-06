//---------------------------------------------------------------------------

#pragma hdrstop

#include "DoubleList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Doublelist::newShow()
{
	Node* temp = Tail;
	temp = Head;
	//Временно указываем на адрес первого элемента
	while (temp != NULL) {
		//Пока не встретим пустое значение
		//cout<<temp->x<<" ";
		//Выводим каждое считанное значение на экран
		Form2->Memo2->Lines->Add(temp->x);
		//std::cout << temp->x << " ";
		//Смена адреса на адрес следующего элемента
		temp = temp->Next;
	}
}
Doublelist::~Doublelist()
{
	while (Head)
	{     //Пока по адресу на начало списка что-то есть
	 //Резервная копия адреса следующего звена списка
		Tail = Head->Next;
		delete Head; //Очистка памяти от первого звена
		//Смена адреса начала на адрес следующего элемента
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
