//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Rec.h"
#include "Elps.h"
#include "Circ.h"
#include "Triangle.h"
#include "Hex.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Shape *s;



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
    Panel1 -> Caption = "";
	Panel2 -> Caption = "";

	s -> MouseDown(Canvas,X,Y);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	s -> MouseUp(Canvas,X,Y);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
	s -> MouseMove(Canvas,X,Y);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
	Canvas -> Brush -> Color = clWhite;
	Canvas -> Pen -> Color =clBlack;
	Canvas -> Pen -> Width = 3;
	Canvas -> Rectangle(10,10,500,440);
	Canvas -> Pen -> Color =clRed;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	s -> Set_Angle(StrToFloat(Edit1->Text)*3.14/180.0);
	Timer1 -> Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	s -> Rotate(Canvas);
	if (s -> Get_Angle() <= 0){
		Timer1 -> Enabled = false;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled)
{
	s -> WheelUp(Canvas);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled)
{
	s -> WheelDown(Canvas);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	RadioButton1 -> Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
	RadioButton1 -> Checked = true;

	Canvas -> Brush -> Color = clWhite;
	Canvas -> Pen -> Color =clBlack;
	Canvas -> Pen -> Width = 3;
	Canvas -> Rectangle(10,10,500,440);
	Canvas -> Pen -> Color =clRed;

	Panel1 -> Caption = "";
	Panel2 -> Caption = "";

	s = new Rec();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
	RadioButton2 -> Checked = true;

	Canvas -> Brush -> Color = clWhite;
	Canvas -> Pen -> Color =clBlack;
	Canvas -> Pen -> Width = 3;
	Canvas -> Rectangle(10,10,500,440);
	Canvas -> Pen -> Color =clRed;

    Panel1 -> Caption = "";
	Panel2 -> Caption = "";

	s = new Elps();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
	RadioButton3 -> Checked = true;

	Canvas -> Brush -> Color = clWhite;
	Canvas -> Pen -> Color =clBlack;
	Canvas -> Pen -> Width = 3;
	Canvas -> Rectangle(10,10,500,440);
	Canvas -> Pen -> Color =clRed;

    Panel1 -> Caption = "";
	Panel2 -> Caption = "";

	s = new Circ();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
	RadioButton4 -> Checked = true;

	Canvas -> Brush -> Color = clWhite;
	Canvas -> Pen -> Color =clBlack;
	Canvas -> Pen -> Width = 3;
	Canvas -> Rectangle(10,10,500,440);
	Canvas -> Pen -> Color =clRed;

    Panel1 -> Caption = "";
	Panel2 -> Caption = "";

	s = new Tri();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
	RadioButton5 -> Checked = true;

	Canvas -> Brush -> Color = clWhite;
	Canvas -> Pen -> Color =clBlack;
	Canvas -> Pen -> Width = 3;
	Canvas -> Rectangle(10,10,500,440);
	Canvas -> Pen -> Color =clRed;

    Panel1 -> Caption = "";
	Panel2 -> Caption = "";

	s = new Hex();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Panel1 -> Caption = FloatToStr(s -> Get_area());
	Panel2 -> Caption = FloatToStr(s -> Get_per());
}
//---------------------------------------------------------------------------

