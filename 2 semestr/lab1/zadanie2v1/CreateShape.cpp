//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CreateShape.h"
#include "AddNewRectangle.h"
#include "AddNewSquare.h"
#include "AddNewEllipse.h"
#include "AddNewCircle.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCreate *Create;
//---------------------------------------------------------------------------
__fastcall TCreate::TCreate(TComponent* Owner)
	: TForm(Owner)
{
	Create->Left=Screen->Width/2-Create->ClientWidth/2;
	Create->Top=Screen->Height/2-Create->ClientHeight/2;
}
//---------------------------------------------------------------------------
void __fastcall TCreate::Button1Click(TObject *Sender)
{
	AddRect->Show();
	Create->Close();
}
//---------------------------------------------------------------------------
void __fastcall TCreate::Button2Click(TObject *Sender)
{
	AddSq->Show();
	Create->Close();
}
//---------------------------------------------------------------------------

void __fastcall TCreate::Button3Click(TObject *Sender)
{
	AddEll->Show();
}
//---------------------------------------------------------------------------

void __fastcall TCreate::Button4Click(TObject *Sender)
{
    Form1->Show();
	Create->Close();
}
//---------------------------------------------------------------------------

