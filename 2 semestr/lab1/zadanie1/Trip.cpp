//---------------------------------------------------------------------------

#pragma hdrstop

#include "Trip.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Trip::show(TCanvas *Canvas)
{
  	Canvas->Pen->Color=clBlack;
	Canvas->Brush->Color=clBlack ;
	Canvas->Rectangle(x1,y1,x2,y2);
	Canvas->Pen->Color=clWhite;
	Canvas->Brush->Color=clWhite ;
	for (int j=x1; j<x2; j+=30+length)
	{
		Canvas->Rectangle(j,(y1+y2)/2-5,j+20+length,(y1+y2)/2+5);
	}
}
void Trip::hide(TCanvas *Canvas)
{
	Canvas->Pen->Color=clWhite;
	Canvas->Brush->Color=clWhite;
	Canvas->Rectangle(x1,y1,x2,y2);
}
void Trip::move(TCanvas *Canvas)
{
	length+=3;
}
