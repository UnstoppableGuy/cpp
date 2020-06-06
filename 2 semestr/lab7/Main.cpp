//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <cstdlib>
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Hash HashTable;
TForm* form;
TButton* but;
TEdit* edit1;
TEdit* edit2;
TLabel* label;
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
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	Memo2->Clear();
	int n = StrToInt(Edit1->Text);
	int range = StrToInt(Edit2->Text);
	for (int i = 0; i < n; i++)
	{
		int newkey = rand() % range + 1;
		Memo2->Lines->Add(newkey);
		HashTable.AddToHash(newkey);
	}
	for (int i = 0; i < 20; i++)
	{
		Memo1->Lines->Add(HashTable.hashstack[i].ToString());
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
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

	label = new TLabel(Application);
	label->Left = 40;
	label->Top = 80;
	label->Caption = "Ключ";
	label->Parent = form;
	form->ShowModal();


}
void __fastcall TForm2::AddClick(TObject *Sender)
{
		Memo1->Clear();
	   HashTable.AddToHash(edit1->Text.ToInt());
		for (int i = 0; i < 20; i++)
		{
			Memo1->Lines->Add(HashTable.hashstack[i].ToString());
		}
        form->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
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
void __fastcall TForm2::DeleteClick(TObject *Sender)
{
	 Memo1->Clear();
	 HashTable.DeleteFromHash(edit1->Text.ToInt());
	  for (int i = 0; i < 20; i++)
	  {
		Memo1->Lines->Add(HashTable.hashstack[i].ToString());
	  }
      form->Close();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
	HashTable.DeleteAll();
}
//---------------------------------------------------------------------------



