//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#define sti StrToInt
#include "AddNewEllipse.h"
#include "CustomEllipse.h"
#include "Task2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddEll *AddEll;
extern MyEllipse *MEllipse;
extern int CurShape;
//---------------------------------------------------------------------------
__fastcall TAddEll::TAddEll(TComponent* Owner)
	: TForm(Owner)
{
	AddEll->Left=Screen->Width/2-AddEll->ClientWidth/2;
	AddEll->Top=Screen->Height/2-AddEll->ClientHeight/2;
}
//---------------------------------------------------------------------------
void __fastcall TAddEll::Button1Click(TObject *Sender)
{

	if(MEllipse == NULL)
	{
	   CurShape = 3;
	   MEllipse = new MyEllipse(StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text), StrToInt(Edit4->Text));
	}
	else
	{
	   CurShape = 3;
	   MEllipse->remake(StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text), StrToInt(Edit4->Text));
	}
	MEllipse->c_x = sti(Edit1->Text);
	MEllipse->c_y = sti(Edit2->Text);
	MainForm->Label5->Caption = FloatToStr(sti(Edit3->Text) * sti(Edit4->Text) * 3.14);
	MainForm->Label6->Caption = FloatToStr((sti(Edit3->Text) + sti(Edit4->Text)) * 3.14);
	MainForm->Label7->Caption = "(" + IntToStr(MEllipse->c_x) + ", " + IntToStr(MEllipse->c_y) + ")";
	MEllipse->draw();
	AddEll->Close();
}
//---------------------------------------------------------------------------


