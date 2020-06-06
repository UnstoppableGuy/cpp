//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Quene.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Queue ob;
int length=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	//создание очереди
	int lengthtemp=0;
	try
	{
	 lengthtemp=StrToInt(Edit1->Text);
	}
	catch (...)
	{
	}
	int xA;
 	for(int i=0; i < lengthtemp;i++)   {	xA = random(10); 		ob.Add(xA);		//dl.Add(xA);    }	length+=lengthtemp;}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//показать список
	if (length == 0)
	{
		Application->Title = "Внимание";
		ShowMessage("Список пуст");
		return;
	}
	Memo1->Clear();
	ob.Show();	////}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	//очистить весь
	ob.~Queue();
	Memo1->Clear();
	length=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	// удалить из начала
	try
	{
		ob.DeleteNull();		Memo1->Clear();		ob.Show();		length--;	}	catch(...) {}}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	//добавить новый элемент
	int xA = random(10);
	Edit2->Text = xA;
	length++; 
	ob.Add(xA);}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Edit3->Text=ob.LENGTH();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	//Form2->Show();
	//Form1->Close();
	/*Memo1->Clear();
	dl.list_remove();
	dl.Show();*/

}
//---------------------------------------------------------------------------



