//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <string>
#ifndef structH
#define structH
//---------------------------------------------------------------------------
#endif
 struct stack
{
	char s;
	stack* next;
};
void In(stack** top, char s);

void Out(stack** top, char& buff);


int PrimaryRight(char s);

double Analysis(stack** top, UnicodeString final, float a, float b, float c, float d, float e);
