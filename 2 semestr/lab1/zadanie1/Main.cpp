//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//#include "Plane.h"
#include "Trip.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Plane A(20,20,120,50,0);
Trip B(0,300,800,340,10);
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	 B.hide(Image1->Canvas);
	 A.hide(Image1->Canvas);
	 B.move(Image1->Canvas);
	 A.move(Image1->Canvas);
	 B.show(Image1->Canvas);
	 A.show(Image1->Canvas);

	 //A.trip(Image1->Canvas);

}
//---------------------------------------------------------------------------

