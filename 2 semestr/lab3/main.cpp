//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "MyException.h"
#include "List.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
Record* r;
RecordList* CompleteList = new RecordList;
RecordList* WaitList = new RecordList;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm4::Button3Click(TObject *Sender)
{
	try{
		bool A = Edit1 -> Text == "";
		bool B = Edit2 -> Text == "";
		bool C = Edit3 -> Text == "";
		bool D = Edit4 -> Text == "";
		if(A || B || C || D)
		{
			throw MyException("�� ��� ������ �������");
		}
	}
	catch(MyException* e)
	{
	   return;
	}

	int x = StrToInt(Edit1 -> Text);
	AnsiString z = Edit2 -> Text;
	AnsiString v = Edit3 -> Text;
	AnsiString q = Edit4 -> Text;

	WaitList->Add(new Record(x,z,v,q));

	Edit1 -> Text = "";
	Edit2 -> Text = "";
	Edit3 -> Text = "";
	Edit4 -> Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button4Click(TObject *Sender)
{
	Memo1 -> Lines -> Clear();
	WaitList -> Print(Memo1);
	CompleteList -> Print(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	Memo1 -> Lines -> Clear();
	WaitList -> Remove();
	CompleteList -> Remove();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button6Click(TObject *Sender)
{
	Memo1 -> Lines -> Clear();
	WaitList -> Print(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button8Click(TObject *Sender)
{
	Memo1 -> Lines -> Clear();
	CompleteList -> Print(Memo1);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button5Click(TObject *Sender)
{
	Memo1 -> Lines -> Clear();
	try
	{
		if(Edit1 -> Text != "")
		{
			if(WaitList -> Search1(StrToInt(Edit1 -> Text)))
				r = WaitList -> Search1(StrToInt(Edit1 -> Text));
			else
				r = CompleteList -> Search1(StrToInt(Edit1 -> Text));
		}
		else if(Edit2 -> Text != "")
		{
			if(WaitList -> Search2(StrToInt(Edit2 -> Text)))
				r = WaitList -> Search2(Edit2 -> Text);
			else
				r = CompleteList -> Search2(Edit2 -> Text);
		}
		else if(Edit3 -> Text != "")
		{
		   if(WaitList -> Search3(StrToInt(Edit4 -> Text)))
				r = WaitList -> Search3(Edit4 -> Text);
			else
				r = CompleteList -> Search3(Edit4 -> Text);
		}
		if(r)
		{
			Memo1 -> Lines -> Add(IntToStr(r -> Get_Number()));
			Memo1 -> Lines -> Add(r -> Get_Fio());
			Memo1 -> Lines -> Add(r -> Get_Adress());
			Memo1 -> Lines -> Add(r -> Get_Date());
		}
		else
			throw MyException("����� ������� ���");
	}
	catch(MyException* e)
	{
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button7Click(TObject *Sender)
{
	try
	{
		if(!r)
			throw MyException("�������� �����");
		WaitList -> Remove(r);
		int a = StrToInt(Memo1 -> Lines -> Strings[0]);
		AnsiString b = Memo1 -> Lines -> Strings[1];
		AnsiString c = Memo1 -> Lines -> Strings[2];
		AnsiString d = Memo1 -> Lines -> Strings[3];
		Record* y = new Record(a, b, c, d);
		y -> next = nullptr;
		CompleteList -> Add(y);
	}
	catch(MyException* e)
	{
		return;
	}

}
//---------------------------------------------------------------------------
