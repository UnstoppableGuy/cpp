//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Buttons.h"
#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
Tree *Root = NULL;
TForm* form;
TButton* but;
TEdit* edit1;
TEdit* edit2;
TLabel* label;
TMemo* memo;

void ToForm(TForm* f)
{
	f->Height = 350;
	f->Width = 250;
	f->Left = 300;
	f->Top = 400;
}
void ToButton(TButton* but)
{
	but->Height = 30;
	but->Width = 70;
	but->Left = 75;
	but->Top = 250;
}
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	form = new TForm(this);
	ToForm(form);

	but = new TButton(Application);
	ToButton(but);
	but->Caption = "Удалить";
	but->OnClick = DeleteClick;
	but->Parent = form;
	edit1 = new TEdit(Application);
	edit1->Height = 30;
	edit1->Width = 40;
	edit1->Left = 100;
	edit1->Top = 100;
	edit1->Parent = form;
	label = new TLabel(Application);
	label->Left = 60;
	label->Top = 100;
	label->Caption = "Ключ";
	label->Parent = form;
	form->ShowModal();
}
void __fastcall TForm3::DeleteClick(TObject *Sender)
{//delete
	int findkey = StrToInt(edit1->Text);
	Root = Root->Remove(Root, findkey);
	form->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button4Click(TObject *Sender)
{
	form = new TForm(this);
	ToForm(form);
	but = new TButton(Application);
	ToButton(but);
	but->Caption = "Найти";
	but->OnClick = SearchClick;
	but->Parent = form;
	edit1 = new TEdit(Application);
	edit1->Height = 30;
	edit1->Width = 40;
	edit1->Left = 100;
	edit1->Top = 100;
	edit1->Parent = form;
	label = new TLabel(Application);
	label->Left = 60;
	label->Top = 100;
	label->Caption = "Ключ";
	label->Parent = form;
	form->ShowModal();
}
void __fastcall TForm3::SearchClick(TObject *Sender)
{//search
    Form1->Memo1->Clear();
	int findkey = StrToInt(edit1->Text);
	Root->FindInfo(Root, findkey);
	form->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	form = new TForm(this);
	ToForm(form);
	but = new TButton(Application);
	ToButton(but);
	but->Caption = "Добавить";
	but->OnClick = AddClick;
	but->Parent = form;
	edit1 = new TEdit(Application);
	edit1->Height = 30;
	edit1->Width = 50;
	edit1->Left = 100;
	edit1->Top = 80;
	edit1->Parent = form;
	edit2 = new TEdit(Application);
	edit2->Height = 30;
	edit2->Width = 100;
	edit2->Left = 100;
	edit2->Top = 130;
	edit2->Parent = form;

	label = new TLabel(Application);
	label->Left = 40;
	label->Top = 80;
	label->Caption = "Ключ";
	label->Parent = form;

	TLabel *lab = new TLabel(Application);
	lab->Left = 40;
	lab->Top = 130;
	lab->Caption = "Значение";
	lab->Parent = form;

	form->ShowModal();
}
void __fastcall TForm3::AddClick(TObject *Sender)
{
	Root = Root->Insert(Root, StrToInt(edit1->Text), edit2->Text);
	form->Close();
}
void __fastcall TForm3::Button9Click(TObject *Sender)
{
	Form1->TreeView1->Items->Clear();
	Root->PrintTree(Root, -1);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button5Click(TObject *Sender)
{
	Form1->Memo1->Clear();
	Root->PrintDirect(Root);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button6Click(TObject *Sender)
{
	Form1->Memo1->Clear();
	Root->PrintReverse(Root);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button7Click(TObject *Sender)
{
	Form1->Memo1->Clear();
	Root->PrintInOrder(Root);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Form1->Show();
	int i = 1;
	while (Form1->StringGrid1->Cells[0][i] != "")
	{
		String newline = Form1->StringGrid1->Cells[0][i];
		int info =  StrToInt(Form1->StringGrid1->Cells[1][i]);
		Root = Root->Insert(Root, info, newline);
		i++;
	}
	for (int i = 1; i < Form1->StringGrid1->RowCount; i++) {
		Form1->StringGrid1->Cells[0][i]= "";
		Form1->StringGrid1->Cells[1][i] = "";
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm3::Button8Click(TObject *Sender)
{
	int n=(Root->Complete(Root));
	Form1->Edit2->Text = n;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button10Click(TObject *Sender)
{
	Form1->Show();
}
//---------------------------------------------------------------------------

