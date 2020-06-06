//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Task2.h"
#include "CreateShape.h"
#include "CustomObject.h"
#include "CustomRectangle.h"
#include "CustomSquare.h"
#include "CustomEllipse.h"
#include "CustomCircle.h"
#include "Move.h"
#include "Turn.h"
#include "Scale.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;

int CurShape = 0;
MyRectangle *MRectangle;
MySquare *MSquare;
MyEllipse *MEllipse;
MyCircle *MCircle;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	MainForm->Left=Screen->Width/2-MainForm->ClientWidth/2;
	MainForm->Top=Screen->Height/2-MainForm->ClientHeight/2;
	MainForm->Image1->Canvas->Brush->Color = clSilver;
	MainForm->Image1->Canvas->FillRect(Rect(0, 0, 800, 800));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	Create->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
	MoveForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button3Click(TObject *Sender)
{
	TurnForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button4Click(TObject *Sender)
{
    ScaleForm->Show();
}
//---------------------------------------------------------------------------





