//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void RecordList::Add(Record* new_item)
{
	if(!head)
		head = new_item;
	else
		tail -> next = new_item;
	tail = new_item;
}

void RecordList::Remove()
{
	if(!head)
		return;

	Record* prev = head;
	Record* current;
	while(current)
	{
		Record* x = prev;
		current = prev -> next;
		while(current)
		{
			bool A = prev -> Get_Fio() == current -> Get_Fio();
			bool B = prev -> Get_Adress() == current -> Get_Adress();
			if(A || B)
			{
				if(!current -> next)
					tail = x;
				x -> next = current -> next;
				delete current;
				return;
			}
			x = current;
			current = current -> next;
		}
		prev = prev -> next;
	}
}

void RecordList::Remove(Record* item)
{
	if(!head)
		return;

	Record* prev = head;
	Record* current = head -> next;

	if(head == item)
	{
		Record* old_head = head;
		head = head -> next;
		delete old_head;
		return;
	}

	while(current)
	{
		if(item == current)
		{
			if(!current -> next)
				tail = prev;
			prev -> next = current -> next;
			delete current;
			return;
		}
		prev = current;
		current = current -> next;
	}
}

void RecordList::Print(TMemo* m)
{
	if(!head)
		return;
	Record* record = head;
	do{
		m -> Lines -> Add(IntToStr(record -> Get_Number()));
		m -> Lines -> Add(record -> Get_Fio());
		m -> Lines -> Add(record -> Get_Adress());
		m -> Lines -> Add(record -> Get_Date());
		m -> Lines -> Add("----------------------");
		record = record -> next;
	}while(record);
}

Record* RecordList::Search1(int number)
{
	Record* current = head;
	while(current)
	{
		if(current -> Get_Number() == number)
			return current;

		current = current -> next;
	}

	return nullptr;}

Record* RecordList::Search2(AnsiString FIO)
{
    Record* current = head;
	while(current)
	{
		if(current -> Get_Fio() == FIO)
			return current;

		current = current -> next;
	}

	return nullptr;
}

Record* RecordList::Search3(AnsiString Adress)
{
    Record* current = head;
	while(current)
	{
		if(current -> Get_Adress() == Adress)
			return current;

		current = current -> next;
	}

	return nullptr;
}

RecordList::~RecordList()
 {
	Record* next = nullptr;
	while(head) {
		next = head->next;
		delete head;
		head = next;
	}
}

