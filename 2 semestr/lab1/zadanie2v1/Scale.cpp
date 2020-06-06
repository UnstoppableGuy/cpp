//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Scale.h"
#include "CustomRectangle.h"
#include "CustomSquare.h"
#include "CustomEllipse.h"
#include "CustomCircle.h"
#include "math.h"
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

int old[2][4];
int oldEllipse[2][100];
int oldCircle[2][100];
int amount;
float k, delta_k, temp;
const int interval = 25;
TScaleForm *ScaleForm;
//---------------------------------------------------------------------------
__fastcall TScaleForm::TScaleForm(TComponent* Owner)
	: TForm(Owner)
{
	ScaleForm->Left=Screen->Width/2-ScaleForm->ClientWidth/2;
	ScaleForm->Top=Screen->Height/2-ScaleForm->ClientHeight/2;
}
//---------------------------------------------------------------------------
void __fastcall TScaleForm::Button1Click(TObject *Sender)
{

	int totaltime = StrToInt(Edit4->Text) * 1000;
	amount = totaltime / interval;
	k = StrToFloat(Edit3->Text);
	temp = delta_k = powf(k, 1 / (float) amount);
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
	ScaleForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TScaleForm::Timer1Timer(TObject *Sender)
{
	if(amount == 1)
	{
		MRectangle->scale(StrToInt(Edit1->Text),StrToInt(Edit2->Text),k, old);
		Timer1->Enabled = false;
        int ls = MRectangle->getY(3) - MRectangle->getY(0);
		int us = MRectangle->getX(1) - MRectangle->getY(0);
		MainForm->Label5->Caption = FloatToStr(sti(MainForm->Label5->Caption) * StrToFloat(Edit3->Text) * StrToFloat(Edit3->Text));
		MainForm->Label6->Caption = FloatToStr(sti(MainForm->Label6->Caption) * StrToFloat(Edit3->Text));
		//MainForm->Label7->Caption = "(" + IntToStr(MRectangle->getX(0) + us / 2) + ", " + IntToStr(MRectangle->getY(0) + ls / 2) + ")";
		MRectangle->c_x = ((MRectangle->c_x - StrToInt(Edit1->Text)) * k) + StrToInt(Edit1->Text);
		MRectangle->c_y = ((MRectangle->c_y - StrToInt(Edit2->Text)) * k) + StrToInt(Edit2->Text);
		MainForm->Label7->Caption = "(" + IntToStr(MRectangle->c_x) + ", " + IntToStr(MRectangle->c_y) + ")";
	}
	else
	{
		MRectangle->scale(StrToInt(Edit1->Text),StrToInt(Edit2->Text),delta_k, old);
		delta_k = delta_k * temp;
	}
	amount--;

}
//---------------------------------------------------------------------------
void __fastcall TScaleForm::Timer2Timer(TObject *Sender)
{
	if(amount == 1)
	{
		MSquare->scale(StrToInt(Edit1->Text),StrToInt(Edit2->Text),k, old);
		Timer2->Enabled = false;
        MainForm->Label5->Caption = FloatToStr(sti(MainForm->Label5->Caption) * StrToFloat(Edit3->Text) * StrToFloat(Edit3->Text));
		MainForm->Label6->Caption = FloatToStr(sti(MainForm->Label6->Caption) * StrToFloat(Edit3->Text));
		//MainForm->Label7->Caption = "(" + IntToStr(MSquare->getX(0) + (MSquare->getX(1) - MSquare->getX(0)) / 2) + ", " + IntToStr(MSquare->getX(0) + (MSquare->getX(1) - MSquare->getX(0)) / 2) + ")";
		MSquare->c_x = ((MSquare->c_x - StrToInt(Edit1->Text)) * k) + StrToInt(Edit1->Text);
		MSquare->c_y = ((MSquare->c_y - StrToInt(Edit2->Text)) * k) + StrToInt(Edit2->Text);
		MainForm->Label7->Caption = "(" + IntToStr(MSquare->c_x) + ", " + IntToStr(MSquare->c_y) + ")";
	}
	else
	{
		MSquare->scale(StrToInt(Edit1->Text),StrToInt(Edit2->Text),delta_k, old);
		delta_k = delta_k * temp;
	}
	amount--;
}
//---------------------------------------------------------------------------

void __fastcall TScaleForm::Timer3Timer(TObject *Sender)
{
	if(amount == 1)
	{
		MEllipse->scale(StrToInt(Edit1->Text),StrToInt(Edit2->Text), k, oldEllipse);
		Timer3 ->Enabled = false;
        MainForm->Label5->Caption = FloatToStr(sti(MainForm->Label5->Caption) * StrToFloat(Edit3->Text) * StrToFloat(Edit3->Text));
		MainForm->Label6->Caption = FloatToStr(sti(MainForm->Label6->Caption) * StrToFloat(Edit3->Text));
		//MainForm->Label7->Caption = "(" + IntToStr(MEllipse->getX(0)) + ", " + IntToStr(MEllipse->getY(0)) + ")";
		MEllipse->c_x = ((MEllipse->c_x - StrToInt(Edit1->Text)) * k) + StrToInt(Edit1->Text);
		MEllipse->c_y = ((MEllipse->c_y - StrToInt(Edit2->Text)) * k) + StrToInt(Edit2->Text);
		MainForm->Label7->Caption = "(" + IntToStr(MEllipse->c_x) + ", " + IntToStr(MEllipse->c_y) + ")";
	}
	else
	{
		MEllipse->scale(StrToInt(Edit1->Text),StrToInt(Edit2->Text),delta_k, oldEllipse);
		delta_k = delta_k * temp;
	}
	amount--;
}
//---------------------------------------------------------------------------



void __fastcall TScaleForm::Timer4Timer(TObject *Sender)
{
    if(amount == 1)
	{
		MCircle->scale(StrToInt(Edit1->Text),StrToInt(Edit2->Text), k, oldCircle);
		Timer4->Enabled = false;
        MainForm->Label5->Caption = FloatToStr(sti(MainForm->Label5->Caption) * StrToFloat(Edit3->Text) * StrToFloat(Edit3->Text));
		MainForm->Label6->Caption = FloatToStr(sti(MainForm->Label6->Caption) * StrToFloat(Edit3->Text));
		//MainForm->Label7->Caption = "(" + IntToStr(MCircle->getX(0)) + ", " + IntToStr(MCircle->getY(0)) + ")";
		MCircle->c_x = ((MCircle->c_x - StrToInt(Edit1->Text)) * k) + StrToInt(Edit1->Text);
		MCircle->c_y = ((MCircle->c_y - StrToInt(Edit2->Text)) * k) + StrToInt(Edit2->Text);
		MainForm->Label7->Caption = "(" + IntToStr(MCircle->c_x) + ", " + IntToStr(MCircle->c_y) + ")";
	}
	else
	{
		MCircle->scale(StrToInt(Edit1->Text),StrToInt(Edit2->Text),delta_k, oldCircle);
		delta_k = delta_k * temp;
	}
	amount--;
}
//---------------------------------------------------------------------------

