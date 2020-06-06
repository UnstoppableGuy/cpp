//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop
#include "struct.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	float a, b, c, d, e, NewValues, ChangeExpression;
	int length;
	UnicodeString final;
	char ss, ss_buff;
	stack* top = NULL;
	AnsiString s = Edit1->Text;
	UnicodeString begin = s.c_str();
	for (int i = 1; i <= (int)begin.Length(); i++)
	{
			ss = begin[i];
			if (ss == '(')
				In(&top, ss);
			if (ss == ')')
			{
				while (top->s != '(')
				{
					Out(&top, ss_buff);
					final += ss_buff;
				}
				Out(&top, ss_buff);
			}
			if (ss >= 'a' && ss <= 'z')
				final += ss;
			if (ss == '-' || ss == '+' || ss == '*' || ss == '/')
			{
				while (top != NULL && PrimaryRight(top->s) >= PrimaryRight(ss))
				{
					Out(&top, ss_buff);
					final += ss_buff;
				}
				In(&top, ss);
			}
	}
		while (top != NULL)
		{
			Out(&top, ss_buff);
			final += ss_buff;
		}
		Panel1->Caption=final;
		a=StrToFloat(Edit2->Text);
		b=StrToFloat(Edit3->Text);
		c=StrToFloat(Edit4->Text);
		d=StrToFloat(Edit5->Text);
		e=StrToFloat(Edit6->Text);
		//UnicodeString temp=Analysis(&top, final, a, b, c, d, e);
		Panel2->Caption=Analysis(&top, final, a, b, c, d, e);//temp;
}
//---------------------------------------------------------------------------


