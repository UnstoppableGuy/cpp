//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Buttons.h"
#include "Unit1.h"
#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Tree *Root = NULL;
Tree *root1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid1->Cols[1]->Add("Key");     StringGrid1->Cols[0]->Add("Word");
	StringGrid1->Cols[1]->Add("20");      StringGrid1->Cols[0]->Add("mum");
	StringGrid1->Cols[1]->Add("25");       StringGrid1->Cols[0]->Add("dad");
	StringGrid1->Cols[1]->Add("15");       StringGrid1->Cols[0]->Add("brother");
	StringGrid1->Cols[1]->Add("10");       StringGrid1->Cols[0]->Add("sister");
	StringGrid1->Cols[1]->Add("30");       StringGrid1->Cols[0]->Add("pet");
	StringGrid1->Cols[1]->Add("5");       StringGrid1->Cols[0]->Add("grandmother");
	StringGrid1->Cols[1]->Add("25");       StringGrid1->Cols[0]->Add("grandfather");
	StringGrid1->Cols[1]->Add("35");       StringGrid1->Cols[0]->Add("underground");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	Form3->Show();
}
//---------------------------------------------------------------------------
