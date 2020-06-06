//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Move.h"
#include "Task2.h"
#include "CustomRectangle.h"
#include "CustomSquare.h"
#include "CustomEllipse.h"
#include "CustomCircle.h"
#define sti StrToInt
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMoveForm *MoveForm;

extern MyRectangle *MRectangle;
extern MySquare *MSquare;
extern MyEllipse *MEllipse;
extern MyCircle *MCircle;
extern int CurShape;
int totaltime;
int amount;
int x_change, y_change;
const int interval = 25;

//---------------------------------------------------------------------------
__fastcall TMoveForm::TMoveForm(TComponent* Owner)
	: TForm(Owner)
{
	MoveForm->Left=Screen->Width/2-MoveForm->ClientWidth/2;
	MoveForm->Top=Screen->Height/2-MoveForm->ClientHeight/2;
}
//---------------------------------------------------------------------------
void __fastcall TMoveForm::Button1Click(TObject *Sender)
{
	totaltime = StrToInt(Edit3->Text) * 1000;
	amount =  totaltime / interval;
	if(amount == 0) amount = 1;
	if(CurShape == 1)
	{
	   x_change = MRectangle->round((StrToInt(Edit1->Text) - MRectangle->getX(0)) / amount);
	   y_change = MRectangle->round((StrToInt(Edit2->Text) - MRectangle->getY(0)) / amount);
	   if(x_change == 0) x_change = 1;
	   if(y_change == 0) y_change = 1;
	   Timer1->Enabled = true;
	   Timer1->Interval = interval;

	}
	else if(CurShape == 2)
	{
	   x_change = MSquare->round((StrToInt(Edit1->Text) - MSquare->getX(0)) / amount);
	   y_change = MSquare->round((StrToInt(Edit2->Text) - MSquare->getY(0)) / amount);
	   if(x_change == 0) x_change = 1;
	   if(y_change == 0) y_change = 1;
	   Timer2->Enabled = true;
	   Timer2->Interval = interval;
	}
	else if(CurShape == 3)
	{
	   x_change = MEllipse->round((StrToInt(Edit1->Text) - MEllipse->getX(0)) / amount);
	   y_change = MEllipse->round((StrToInt(Edit2->Text) - MEllipse->getY(0)) / amount);
	   if(x_change == 0) x_change = 1;
	   if(y_change == 0) y_change = 1;
	   Timer3->Enabled = true;
	   Timer3->Interval = interval;
	}
	else if(CurShape == 4)
	{
	   x_change = MCircle->round((StrToInt(Edit1->Text) - MCircle->getX(0)) / amount);
	   y_change = MCircle->round((StrToInt(Edit2->Text) - MCircle->getY(0)) / amount);
	   if(x_change == 0) x_change = 1;
	   if(y_change == 0) y_change = 1;
	   Timer4->Enabled = true;
	   Timer4->Interval = interval;
	}
	else if(CurShape == 0) ShowMessage("Фигура не создана");
	MoveForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TMoveForm::Timer1Timer(TObject *Sender)
{
	if(amount == 1)
	{
		MRectangle->move(StrToInt(Edit1->Text),StrToInt(Edit2->Text));
		Timer1->Enabled = false;
	}
	else
	{
		 if(MRectangle->getX(0) == StrToInt(Edit1->Text)) x_change = 0;
		 if(MRectangle->getY(0) == StrToInt(Edit2->Text)) y_change = 0;
		 if(x_change == 0 && y_change == 0)
		 {
			Timer1->Enabled = false;
		 }
		 else
		 {
			MRectangle->move(MRectangle->getX(0) + x_change, MRectangle->getY(0) + y_change);
		 }
	}
	amount--;
	int ls = MRectangle->getY(3) - MRectangle->getY(0);
	int us = MRectangle->getX(1) - MRectangle->getY(0);
	MainForm->Label7->Caption = "(" + IntToStr(MRectangle->getX(0) + us / 2) + ", " + IntToStr(MRectangle->getY(0) + ls / 2) + ")";
}
//---------------------------------------------------------------------------

void __fastcall TMoveForm::Timer2Timer(TObject *Sender)
{
	if(amount == 1)
	{
		MSquare->move(StrToInt(Edit1->Text),StrToInt(Edit2->Text));
		Timer2->Enabled = false;
	}
	else
	{
		 if(MSquare->getX(0) == StrToInt(Edit1->Text)) x_change = 0;
		 if(MSquare->getY(0) == StrToInt(Edit2->Text)) y_change = 0;
		 if(x_change == 0 && y_change == 0)
		 {
			Timer2->Enabled = false;
		 }
		 else
		 {
			MSquare->move(MSquare->getX(0) + x_change, MSquare->getY(0) + y_change);
		 }
	}
	amount--;
	MainForm->Label7->Caption = "(" + IntToStr(MSquare->getX(0) + (MSquare->getX(1) - MSquare->getX(0)) / 2) + ", " + IntToStr(MSquare->getX(0) + (MSquare->getX(1) - MSquare->getX(0)) / 2) + ")";
}
//---------------------------------------------------------------------------

void __fastcall TMoveForm::Timer3Timer(TObject *Sender)
{
	if(amount == 1)
	{
		MEllipse->move(StrToInt(Edit1->Text),StrToInt(Edit2->Text));
		Timer3->Enabled = false;
	}
	else
	{
		 if(MEllipse->getX(0) == StrToInt(Edit1->Text)) x_change = 0;
		 if(MEllipse->getY(0) == StrToInt(Edit2->Text)) y_change = 0;
		 if(x_change == 0 && y_change == 0)
		 {
			Timer3->Enabled = false;
		 }
		 else
		 {
			MEllipse->move(MEllipse->getX(0) + x_change, MEllipse->getY(0) + y_change);
		 }
	}
	amount--;
	MainForm->Label7->Caption = "(" + IntToStr(MEllipse->getX(0)) + ", " + IntToStr(MEllipse->getY(0)) + ")";
}
//---------------------------------------------------------------------------


void __fastcall TMoveForm::Timer4Timer(TObject *Sender)
{
   	if(amount == 1)
	{
		MCircle->move(StrToInt(Edit1->Text),StrToInt(Edit2->Text));
		Timer4->Enabled = false;
	}
	else
	{
		 if(MCircle->getX(0) == StrToInt(Edit1->Text)) x_change = 0;
		 if(MCircle->getY(0) == StrToInt(Edit2->Text)) y_change = 0;
		 if(x_change == 0 && y_change == 0)
		 {
			Timer4->Enabled = false;
		 }
		 else
		 {
			MCircle->move(MCircle->getX(0) + x_change, MCircle->getY(0) + y_change);
		 }
	}
	amount--;
	MainForm->Label7->Caption = "(" + IntToStr(MCircle->getX(0)) + ", " + IntToStr(MCircle->getY(0)) + ")";
	//MainForm->Label7->Caption = "(" + IntToStr(MCircle->getX(0)) + ", " + IntToStr(MCircle->getY(0)) + ")";
}
//---------------------------------------------------------------------------

