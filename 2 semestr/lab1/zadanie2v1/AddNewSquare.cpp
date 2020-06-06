//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Task2.h"
#define sti StrToInt
#include "AddNewSquare.h"
#include "CustomSquare.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddSq *AddSq;
extern MySquare *MSquare;
extern int CurShape;
//---------------------------------------------------------------------------
__fastcall TAddSq::TAddSq(TComponent* Owner)
	: TForm(Owner)
{
	AddSq->Left=Screen->Width/2-AddSq->ClientWidth/2;
	AddSq->Top=Screen->Height/2-AddSq->ClientHeight/2;
}
//---------------------------------------------------------------------------
void __fastcall TAddSq::Button1Click(TObject *Sender)
{
	if(MSquare == NULL)
	{
	   CurShape = 2;
	   MSquare = new MySquare(StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text));
	}
	else
	{
	   CurShape = 2;
	   MSquare->remake(StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text));
	}
	MSquare->c_x = sti(Edit1->Text);
	MSquare->c_y = sti(Edit2->Text);
	MainForm->Label5->Caption =  IntToStr(sti(Edit3->Text) * sti(Edit3->Text));
	MainForm->Label6->Caption =  IntToStr(sti(Edit3->Text) * 4);
	//MainForm->Label7->Caption = "(" + IntToStr(sti(Edit1->Text) +sti(Edit3->Text) / 2) + ", " + IntToStr(sti(Edit2->Text) +sti(Edit3->Text) / 2) + ")";
	MainForm->Label7->Caption = "(" + IntToStr(MSquare->c_x) + ", " + IntToStr(MSquare->c_y) + ")";
	MSquare->draw();
	AddSq->Close();
}
//---------------------------------------------------------------------------
