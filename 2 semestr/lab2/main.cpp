// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "list.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
PuplistReal *list = new PuplistReal();

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::PressClick(TObject *Sender) {
	// show();
	if (OpenDialog1->Execute())
	{
		Mem->Clear();
		String FName = OpenDialog1->FileName;
		TFileStream *FileStream = new TFileStream(FName, fmOpenReadWrite);
		TStringList *StringList = new TStringList;
		StringList->LoadFromStream(FileStream);
		int size = StringList->Count;
		for (int i = 0; i < size; i++) {
			AnsiString lineAnsi = StringList->Strings[i];
			std::string line(lineAnsi.c_str());
			std::string surname, name, patronymic, specialty, math, physics,
				english, certificate;
			std::istringstream f(line);
			std::getline(f, surname, ' ');
			std::getline(f, name, ' ');
			std::getline(f, patronymic, ' ');
			std::getline(f, specialty, ' ');
			std::getline(f, math, ' ');
			std::getline(f, physics, ' ');
			std::getline(f, english, ' ');
			std::getline(f, certificate, ' ');

			Puplist *puplist = new Puplist(surname, name, patronymic, specialty,
				math, physics, english, certificate);
			list->addElement(puplist);
		}
		list->show(Mem);
		delete(FileStream);
		delete(StringList);
		//
		Sort->Visible = true;
		Button1->Visible = true;
		Mem->Visible = true;
		ComboBox1->Visible = true;
		//
		WhatToDo->Visible = true;
		Edit2->Visible = false;
		Edit3->Visible = false;
		Edit4->Visible = false;
		Edit5->Visible = false;
		Edit6->Visible = false;
		Edit7->Visible = false;
		Edit8->Visible = false;
		Edit9->Visible = false;
		Name->Visible = false;
		Surname->Visible = false;
		Patronymic->Visible = false;
		Specialty->Visible = false;
		Math->Visible = false;
		Physics->Visible = false;
		RussianLanguage->Visible = false;
		Certificate->Visible = false;
		JustDoIt->Visible = false;

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (SaveDialog1->Execute())
	{
		String FName = SaveDialog1->FileName;
		TFileStream *FileStream = new TFileStream(FName, fmOpenReadWrite);
		TStringList *StringList = new TStringList;
		for (int i = 0; i < Mem->Lines->Count; i++)
		{
			StringList->Add(Mem->Lines->Strings[i]);
		}
		StringList->SaveToStream(FileStream);
		delete(FileStream);
		delete(StringList);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::WhatToDoClick(TObject *Sender) {
	if (WhatToDo->ItemIndex == 0)
	{
		Edit2->Visible = true;
		Edit3->Visible = true;
		Edit4->Visible = true;
		Edit5->Visible = false;
		Edit6->Visible = false;
		Edit7->Visible = false;
		Edit8->Visible = false;
		Edit9->Visible = false;
		Name->Visible = true;
		Surname->Visible = true;
		Patronymic->Visible = true;
		Specialty->Visible = false;
		Math->Visible = false;
		Physics->Visible = false;
		RussianLanguage->Visible = false;
		Certificate->Visible = false;
		JustDoIt->Visible = true;
	}
	else if (WhatToDo->ItemIndex == 1)
	{
		Edit2->Visible = true;
		Edit3->Visible = true;
		Edit4->Visible = true;
		Edit5->Visible = true;
		Edit6->Visible = true;
		Edit7->Visible = true;
		Edit8->Visible = true;
		Edit9->Visible = true;
		Name->Visible = true;
		Surname->Visible = true;
		Patronymic->Visible = true;
		Specialty->Visible = true;
		Math->Visible = true;
		Physics->Visible = true;
		RussianLanguage->Visible = true;
		Certificate->Visible = true;
		JustDoIt->Visible = true;
	}
	else if (WhatToDo->ItemIndex == 2) {
		Edit2->Visible = true;
		Edit3->Visible = true;
		Edit4->Visible = true;
		Edit5->Visible = false;
		Edit6->Visible = false;
		Edit7->Visible = false;
		Edit8->Visible = false;
		Edit9->Visible = false;
		Name->Visible = true;
		Surname->Visible = true;
		Patronymic->Visible = true;
		Specialty->Visible = false;
		Math->Visible = false;
		Physics->Visible = false;
		RussianLanguage->Visible = false;
		Certificate->Visible = false;
		JustDoIt->Visible = true;

	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::JustDoItClick(TObject *Sender) {
	if (WhatToDo->ItemIndex == 0)
	{
		AnsiString lineAnsi = Edit2->Text;
		std::string surname(lineAnsi.c_str());
		lineAnsi = Edit3->Text;
		std::string name(lineAnsi.c_str());
		lineAnsi = Edit4->Text;
		std::string patronymic(lineAnsi.c_str());
		Mem->Clear();
		list->search(surname, name, patronymic, Mem);
		Edit2->Text = "";
		Edit3->Text = "";
		Edit4->Text = "";
	}
	else if (WhatToDo->ItemIndex == 1)
	{
		AnsiString lineAnsi = Edit2->Text;
		std::string name(lineAnsi.c_str());
		lineAnsi = Edit3->Text;
		std::string surname(lineAnsi.c_str());
		lineAnsi = Edit4->Text;
		std::string patronymic(lineAnsi.c_str());
		lineAnsi = Edit8->Text;
		std::string specialty(lineAnsi.c_str());
		lineAnsi = Edit5->Text;
		std::string math(lineAnsi.c_str());
		lineAnsi = Edit6->Text;
		std::string physics(lineAnsi.c_str());
		lineAnsi = Edit7->Text;
		std::string certificate(lineAnsi.c_str());
		lineAnsi = Edit9->Text;
		std::string englishlanguage(lineAnsi.c_str());
		Puplist *puplist = new Puplist(surname, name, patronymic, specialty,
			math, physics, englishlanguage, certificate);
		list->addElement(puplist);
		Mem->Clear();
		list->show(Mem);
		Edit2->Text = "";
		Edit3->Text = "";
		Edit4->Text = "";
		Edit5->Text = "";
		Edit6->Text = "";
		Edit7->Text = "";
		Edit8->Text = "";
		Edit9->Text = "";
	}
	else if (WhatToDo->ItemIndex == 2)
	{
		AnsiString lineAnsi = Edit2->Text;
		std::string surname(lineAnsi.c_str());
		lineAnsi = Edit3->Text;
		std::string name(lineAnsi.c_str());
		lineAnsi = Edit4->Text;
		std::string patronymic(lineAnsi.c_str());
		list->delet(surname, name, patronymic, Mem);
		Mem->Clear();
		list->show(Mem);
		Edit2->Text = "";
		Edit3->Text = "";
		Edit4->Text = "";
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SortClick(TObject *Sender)
{
	list->sort();
	Mem->Clear();
	list->show(Mem);
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	if (ComboBox1->ItemIndex == 0)
	{
		Mem->Clear();
		list->show(Mem);
	}
	else if (ComboBox1->ItemIndex == 1)
	{
		Mem->Clear();
		std::string ohimark = "FKSiS";
		list->showtime(ohimark, Mem);
	}
	else if (ComboBox1->ItemIndex == 2)
	{
		Mem->Clear();
		std::string ohimark = "FKP";
		list->showtime(ohimark, Mem);
	}
	else if (ComboBox1->ItemIndex == 3)
	{
		Mem->Clear();
		std::string ohimark = "IEF";
		list->showtime(ohimark, Mem);
	}
	else if (ComboBox1->ItemIndex == 4)
	{
		Mem->Clear();
		std::string ohimark = "FITY";
		list->showtime(ohimark, Mem);
	}
	else if (ComboBox1->ItemIndex == 5)
	{
		Mem->Clear();
		std::string ohimark = "FIK";
		list->showtime(ohimark, Mem);
	}
}
// ---------------------------------------------------------------------------

