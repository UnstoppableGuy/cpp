//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddNewCircle.h"
#include "CustomCircle.h"
#include "Task2.h"
#define sti StrToInt
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
extern MyCircle *MCircle;
extern int CurShape;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1->Left=Screen->Width/2-Form1->ClientWidth/2;
	Form1->Top=Screen->Height/2-Form1->ClientHeight/2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(MCircle == NULL)
	{
	   CurShape = 4;
	   MCircle = new MyCircle(StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text));
	}
	else
	{
	   CurShape = 4;
	   MCircle->remake(StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text));
	}
	MCircle->c_x = sti(Edit1->Text);
	MCircle->c_y = sti(Edit2->Text);
	MainForm->Label5->Caption = FloatToStr(sti(Edit3->Text) * sti(Edit3->Text) * 3.14);
	MainForm->Label6->Caption = FloatToStr(2 * sti(Edit3->Text) * 3.14);
	MainForm->Label7->Caption = "(" + IntToStr(MCircle->c_x) + ", " + IntToStr(MCircle->c_y) + ")";
	MCircle->draw();
	Form1->Close();
}
//---------------------------------------------------------------------------
