//---------------------------------------------------------------------------
#include "Unit1.h"
#pragma hdrstop
#include <vcl.h>
#include "Quene.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//  �������� ������
Queue::~Queue()
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
void Queue::Add(int x)
{
	//��������� ������ ��� ����� ������� ���������
	Node* temp = new Node;
	//���������, ��� ���������� �� ���������� ������ �����
	temp->Next = NULL;
	temp->x = x;//���������� �������� � ���������
	if (Head != NULL) { //���� ������ �� ����
	//��������� ����� �� ���������� ������� � �����. ����
		temp->Prev = Tail;
		//��������� ����� ���������� �� ������� ��������
		//������ ����� ������
		Tail->Next = temp; Tail = temp;
	}
	else
	{
		//���� ������ ������
		//���������� ������� ��������� � �������
		temp->Prev = NULL;
		//������=�����=��� �������, ��� ������ ��������
		Head = Tail = temp;
	}
}
//�������� �������� �� ����� �������
void Queue::DeleteNull() {
	if (Head == 0)
	{

		//std::cout << "Warning";
		Application->Title = "��������";
		ShowMessage("������ ����!!");
		//std::cout << "Quene is free";
		return;
	}
	Node* temp;
	temp = Head->Next; //��������� ����� ������ ���������� ����� ������
	delete Head; //������� ������ �� ������� �����
	Head = temp;   //����� ������ ������ �� ����� ���������� ��������
}
void Queue::Show()
{
	Node* temp = Tail;
	temp = Head;
	//�������� ��������� �� ����� ������� ��������
	while (temp != NULL)
	{
		//���� �� �������� ������ ��������
		//cout<<temp->x<<" ";
		//������� ������ ��������� �������� �� �����
		Form1->Memo1->Lines->Add(temp->x);
		//std::cout << temp->x << " ";
		//����� ������ �� ����� ���������� ��������
		temp = temp->Next;
	}
}
int Queue::LENGTH()
{
	int length=0;
	Node* temp = Tail;
	temp = Head;
	//�������� ��������� �� ����� ������� ��������
	while (temp != NULL)
	{
		temp = temp->Next;
		length++;
	}
	return length;
}
