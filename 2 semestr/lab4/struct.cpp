//---------------------------------------------------------------------------

#pragma hdrstop

#include "struct.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 void In(stack** top, char s)
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
	float mas[150];
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
}