//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#define sti StrToInt
#include "AddNewRectangle.h"
#include "CustomRectangle.h"
#include "Task2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddRect *AddRect;

extern MyRectangle *MRectangle;
extern int CurShape;
//---------------------------------------------------------------------------
__fastcall TAddRect::TAddRect(TComponent* Owner)
	: TForm(Owner)
{
	AddRect->Left=Screen->Width/2-AddRect->ClientWidth/2;
	AddRect->Top=Screen->Height/2-AddRect->ClientHeight/2;
}
//---------------------------------------------------------------------------
void __fastcall TAddRect::Button1Click(TObject *Sender)
{
	if(MRectangle == NULL)
	{
	   CurShape = 1;
	   MRectangle = new MyRectangle(StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text), StrToInt(Edit4->Text));
	}
	else
	{
	   CurShape = 1;
	   MRectangle->remake(StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text), StrToInt(Edit4->Text));
	}
	int ls, us;
	ls = sti(Edit3->Text) - sti(Edit1->Text);
	us = sti(Edit4->Text) - sti(Edit2->Text);
	MRectangle->c_x = sti(Edit1->Text);
	MRectangle->c_y = sti(Edit2->Text);
	MainForm->Label5->Caption = FloatToStr(ls * us);
	MainForm->Label6->Caption = FloatToStr(ls * 2 + us * 2);
	MainForm->Label7->Caption = "(" + IntToStr(sti(Edit1->Text) + us / 2) + ", " + IntToStr(sti(Edit2->Text) + ls / 2) + ")";
	MainForm->Label7->Caption = "(" + IntToStr(MRectangle->c_x) + ", " + IntToStr(MRectangle->c_y) + ")";
	MRectangle->draw();
	AddRect->Close();
}
//---------------------------------------------------------------------------
