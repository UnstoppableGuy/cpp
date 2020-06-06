//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "DoubleList.h"
#include "forDouble.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Doublelist dl;
//int length=0;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Memo2->Clear();
	int lengthtemp=0;
	try
	{
		lengthtemp=StrToInt(Edit1->Text);
	}
	catch (...){}
	int xA;
 	for(int i=0; i < lengthtemp;i++)	{		xA = random(10);		dl.Add(xA);    }	//length+=lengthtemp;
	dl.newShow();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
	int xA = random(10);
	Edit2->Text = xA;
	//length++; 
	dl.Add(xA);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	//очистить весь
	dl.~Doublelist();
	Memo2->Clear();
	//length=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
    // удалить из начала
	try
	{
	dl.DeleteNull();	Memo2->Clear();	dl.newShow();	//length--;	}	catch(...) {}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	Edit3->Text=dl.LENGTH();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{	//показать список
	if (dl.LENGTH()== 0)
	{
		Application->Title = "Внимание";
		ShowMessage("Список пуст");
		return;
	}
	Memo2->Clear();
	dl.newShow();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button7Click(TObject *Sender)
{
	Memo2->Clear();
	dl.list_remove();
	dl.newShow();
}
//---------------------------------------------------------------------------


