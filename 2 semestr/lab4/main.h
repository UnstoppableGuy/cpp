//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <string>
//---------------------------------------------------------------------------
/*struct stack
{
	char s;
	stack* next;
};*/

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TButton *Button1;
	TLabel *Label8;
	TPanel *Panel1;
	TPanel *Panel2;
	void __fastcall Button1Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
/*void In(stack** top, char s)
{
	stack* t = new stack;
	t->s = s;
	if (t == NULL)
	{
		*top = t;
	}
	else
	{
		t->next = *top;
		*top = t;
	}
}

void Out(stack** top, char& buff)
{
	stack* q = *top;
	buff = q->s;
	if (q == *top)
	{
		*top = q->next;
		free(q);
	}
	else
		free(q);
	q = q->next;
}

int PrimaryRight(char s)
{
	if (s == '*' || s == '/') return 2;
	if (s == '+' || s == '-') return 1;
	if (s == '(') return 0;
}
double Analysis(stack** top, UnicodeString final, float a, float b, float c, float d, float e)
{

	char ss, comp1, comp2;
	float op1, op2, result;
	float mas[1000];
	mas[int('a')] = a;
	mas[int('b')] = b;
	mas[int('c')] = c;
	mas[int('d')] = d;
	mas[int('e')] = e;
	char chr = 'z' + 1;
	for (int i = 1; i <= (int)final.Length(); i++)
	{
		ss = final[i];
		if (ss >= 'a' && ss <= 'z')
			In(top, ss);
		else
		{
			Out(top, comp1);
			Out(top, comp2);

			op1 = mas[int(comp1)];
			op2 = mas[int(comp2)];
			switch (ss)
			{
				case '*':   result = op2 * op1;
					break;
				case '/':   result = op2 / op1;
					break;
				case '+':   result = op2 + op1;
					break;
				case '-':   result = op2 - op1;
					break;
			}
			mas[int(chr)] = result;
			In(top, chr);
			chr++;
		}
	}
	return result;
}*/
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
