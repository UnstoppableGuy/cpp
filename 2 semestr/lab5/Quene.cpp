//---------------------------------------------------------------------------
#include "Unit1.h"
#pragma hdrstop
#include <vcl.h>
#include "Quene.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//  удаление списка
Queue::~Queue()
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
void Queue::Add(int x)
{
	//Выделение памяти под новый элемент структуры
	Node* temp = new Node;
	//Указываем, что изначально по следующему адресу пусто
	temp->Next = NULL;
	temp->x = x;//Записываем значение в структуру
	if (Head != NULL) { //Если список не пуст
	//Указываем адрес на предыдущий элемент в соотв. поле
		temp->Prev = Tail;
		//Указываем адрес следующего за хвостом элемента
		//Меняем адрес хвоста
		Tail->Next = temp; Tail = temp;
	}
	else
	{
		//Если список пустой
		//Предыдущий элемент указывает в пустоту
		temp->Prev = NULL;
		//Голова=Хвост=тот элемент, что сейчас добавили
		Head = Tail = temp;
	}
}
//удаление элемента из конца очереди
void Queue::DeleteNull() {
	if (Head == 0)
	{

		//std::cout << "Warning";
		Application->Title = "Внимание";
		ShowMessage("Список пуст!!");
		//std::cout << "Quene is free";
		return;
	}
	Node* temp;
	temp = Head->Next; //Резервная копия адреса следующего звена списка
	delete Head; //Очистка памяти от первого звена
	Head = temp;   //Смена адреса начала на адрес следующего элемента
}
void Queue::Show()
{
	Node* temp = Tail;
	temp = Head;
	//Временно указываем на адрес первого элемента
	while (temp != NULL)
	{
		//Пока не встретим пустое значение
		//cout<<temp->x<<" ";
		//Выводим каждое считанное значение на экран
		Form1->Memo1->Lines->Add(temp->x);
		//std::cout << temp->x << " ";
		//Смена адреса на адрес следующего элемента
		temp = temp->Next;
	}
}
int Queue::LENGTH()
{
	int length=0;
	Node* temp = Tail;
	temp = Head;
	//Временно указываем на адрес первого элемента
	while (temp != NULL)
	{
		temp = temp->Next;
		length++;
	}
	return length;
}
