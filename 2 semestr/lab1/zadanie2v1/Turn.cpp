//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Turn.h"
#include "CustomRectangle.h"
#include "CustomSquare.h"
#include "CustomEllipse.h"
#include "CustomCircle.h"
#include "Task2.h"
#define sti StrToInt
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern MyRectangle *MRectangle;
extern MySquare *MSquare;
extern MyEllipse *MEllipse;
extern MyCircle *MCircle;
extern int CurShape;
int amount;
float angle_change, temp, angle;
int old[2][4];
int oldEllipse[2][100];
int oldCircle[2][100];
const int interval = 25;
TTurnForm *TurnForm;
//---------------------/------------------------------------------------------
__fastcall TTurnForm::TTurnForm(TComponent* Owner)
	: TForm(Owner)
{
	TurnForm->Left=Screen->Width/2-TurnForm->ClientWidth/2;
	TurnForm->Top=Screen->Height/2-TurnForm->ClientHeight/2;
}
//---------------------------------------------------------------------------
void __fastcall TTurnForm::Button1Click(TObject *Sender)
{
	int totaltime = StrToInt(Edit4->Text) * 1000;
	amount = totaltime / interval;
	angle = StrToFloat(Edit3->Text) * 3.14 / 180;
	if(amount == 0) amount = 1;
	angle_change = temp = angle / amount;
	if(CurShape == 1)
	{
		old[0][0] = MRectangle->getX(0);
		old[0][1] = MRectangle->getX(1);
		old[0][2] = MRectangle->getX(2);
		old[0][3] = MRectangle->getX(3);
		old[1][0] = MRectangle->getY(0);
		old[1][1] = MRectangle->getY(1);
		old[1][2] = MRectangle->getY(2);
		old[1][3] = MRectangle->getY(3);

		Timer1->Enabled = true;
		Timer1->Interval = interval;
	}
	else if(CurShape == 2)
	{
		old[0][0] = MSquare->getX(0);
		old[0][1] = MSquare->getX(1);
		old[0][2] = MSquare->getX(2);
		old[0][3] = MSquare->getX(3);
		old[1][0] = MSquare->getY(0);
		old[1][1] = MSquare->getY(1);
		old[1][2] = MSquare->getY(2);
		old[1][3] = MSquare->getY(3);

		Timer2->Enabled = true;
		Timer2->Interval = interval;
	}
	else if(CurShape == 3)
	{
		for(int i = 0; i < 100; i++)
		{
			oldEllipse[0][i] = MEllipse->getX(i);
			oldEllipse[1][i] = MEllipse->getY(i);
		}
		Timer3->Enabled = true;
		Timer3->Interval = interval;
	}
	else if(CurShape == 4)
	{
		for(int i = 0; i < 100; i++)
		{
			oldCircle[0][i] = MCircle->getX(i);
			oldCircle[1][i] = MCircle->getY(i);
		}
		Timer4->Enabled = true;
		Timer4->Interval = interval;
	}
	else ShowMessage("Фигура не создана");
	TurnForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TTurnForm::Timer1Timer(TObject *Sender)
{
	if(amount == 1)
	{
		MRectangle->turn(StrToInt(Edit1->Text), StrToInt(Edit2->Text), angle, old);
		Timer1->Enabled = false;
		MRectangle->c_x = (MRectangle->c_x - StrToInt(Edit1->Text)) * cos(angle) - (MRectangle->c_x - StrToInt(Edit2->Text)) * sin(angle) + StrToInt(Edit1->Text);
		MRectangle->c_y = (MRectangle->c_y - StrToInt(Edit1->Text)) * sin(angle) + (MRectangle->c_y - StrToInt(Edit2->Text)) * cos(angle) + StrToInt(Edit2->Text);
		MainForm->Label7->Caption = "(" + IntToStr(MRectangle->c_x) + ", " + IntToStr(MRectangle->c_y) + ")";
	}
	else
	{
		MRectangle->turn(StrToInt(Edit1->Text), StrToInt(Edit2->Text), angle_change, old);
	}
	amount--;
	angle_change = angle_change + temp;
}
//---------------------------------------------------------------------------
void __fastcall TTurnForm::Timer2Timer(TObject *Sender)
{
	if(amount == 1)
	{
		MSquare->turn(StrToInt(Edit1->Text), StrToInt(Edit2->Text), angle, old);
		Timer2->Enabled = false;
		MSquare->c_x = (MSquare->c_x - StrToInt(Edit1->Text)) * cos(angle) - (MSquare->c_x - StrToInt(Edit2->Text)) * sin(angle) + StrToInt(Edit1->Text);
		MSquare->c_y = (MSquare->c_y - StrToInt(Edit1->Text)) * sin(angle) + (MSquare->c_y - StrToInt(Edit2->Text)) * cos(angle) + StrToInt(Edit2->Text);
		MainForm->Label7->Caption = "(" + IntToStr(MSquare->c_x) + ", " + IntToStr(MSquare->c_y) + ")";
	}
	else
	{
		MSquare->turn(StrToInt(Edit1->Text), StrToInt(Edit2->Text), angle_change, old);
	}
	amount--;
	angle_change = angle_change + temp;
}
//---------------------------------------------------------------------------

void __fastcall TTurnForm::Timer3Timer(TObject *Sender)
{
	if(amount == 1)
	{
		MEllipse->turn(StrToInt(Edit1->Text), StrToInt(Edit2->Text), angle, oldEllipse);
		Timer3->Enabled = false;
		MEllipse->c_x = (MEllipse->c_x - StrToInt(Edit1->Text)) * cos(angle) - (MEllipse->c_x - StrToInt(Edit2->Text)) * sin(angle) + StrToInt(Edit1->Text);
		MEllipse->c_y = (MEllipse->c_y - StrToInt(Edit1->Text)) * sin(angle) + (MEllipse->c_y - StrToInt(Edit2->Text)) * cos(angle) + StrToInt(Edit2->Text);
		MainForm->Label7->Caption = "(" + IntToStr(MEllipse->c_x) + ", " + IntToStr(MEllipse->c_y) + ")";
	}
	else
	{
		MEllipse->turn(StrToInt(Edit1->Text), StrToInt(Edit2->Text), angle_change, oldEllipse);
	}
	amount--;
	angle_change = angle_change + temp;
}
//---------------------------------------------------------------------------


void __fastcall TTurnForm::Timer4Timer(TObject *Sender)
{
	if(amount == 1)
	{
		MCircle->turn(StrToInt(Edit1->Text), StrToInt(Edit2->Text), angle, oldCircle);
		Timer4->Enabled = false;
		MCircle->c_x = (MCircle->c_x - StrToInt(Edit1->Text)) * cos(angle) - (MCircle->c_x - StrToInt(Edit2->Text)) * sin(angle) + StrToInt(Edit1->Text);
		MCircle->c_y = (MCircle->c_y - StrToInt(Edit1->Text)) * sin(angle) + (MCircle->c_y - StrToInt(Edit2->Text)) * cos(angle) + StrToInt(Edit2->Text);
		MainForm->Label7->Caption = "(" + IntToStr(MCircle->c_x) + ", " + IntToStr(MCircle->c_y) + ")";
	}
	else
	{
		MCircle->turn(StrToInt(Edit1->Text), StrToInt(Edit2->Text), angle_change, oldCircle);
	}
	amount--;
	angle_change = angle_change + temp;
}
//---------------------------------------------------------------------------

