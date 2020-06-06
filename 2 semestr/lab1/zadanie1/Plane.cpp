//---------------------------------------------------------------------------

#pragma hdrstop

#include "Plane.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Plane::show(TCanvas *Canvas)
{

	if (y2>260)
		{
		Canvas->Pen->Color=clGray;
		Canvas->Brush->Color=clGray ;
		Canvas->Ellipse(x1+10,y2-20+r,x1+30,y2+r);
		Canvas->Ellipse(x2-10,y2-20+r,x2-30,y2+r);
		}
	Canvas->Pen->Color=clBlue;
	Canvas->Brush->Color=clBlue ;
	Canvas->Rectangle(x1,y1,x2,y2);
	Canvas->MoveTo(x1,y1);
	Canvas->LineTo(x1,y1-20);
	Canvas->LineTo(x1+20,y1);
	Canvas->MoveTo(x2,y2);
	Canvas->LineTo(x2+20,y2);
	Canvas->LineTo(x2,y1);
	Canvas->Pen->Color=clWhite;
	Canvas->Brush->Color=clWhite;
	for (int i = x1+5; i < x2; i+=20)
	{
	   Canvas->Ellipse(i,(y2+y1)/2-5,i+10,(y2+y1)/2+5);
	}
}
void Plane::hide(TCanvas *Canvas)
{
	if (y2>280)
		{
		Canvas->Pen->Color=clWhite;
		Canvas->Brush->Color=clWhite;
		Canvas->Ellipse(x1+10,y2-20+r,x1+30,y2+r);
		Canvas->Ellipse(x2-10,y2-20+r,x2-30,y2+r);
		}
		Canvas->Pen->Color=clWhite;
		Canvas->Brush->Color=clWhite;
		Canvas->Rectangle(x1,y1,x2,y2);
		Canvas->MoveTo(x1,y1);
		Canvas->LineTo(x1,y1-20);
		Canvas->LineTo(x1+20,y1);
		Canvas->MoveTo(x2,y2);
		Canvas->LineTo(x2+20,y2);
		Canvas->LineTo(x2,y1);
}
void Plane::move(TCanvas *Canvas)
{		if(y2<280)
		{
			y1+=10;
			y2+=10;
		}
		else if ((r<20))
		{


			y1++;
			y2++;
			r++;
		}
		x1+=10;
		x2+=10;
}
void Plane::trip(TCanvas *Canvas)
{
	Canvas->Pen->Color=clBlack;
	Canvas->Brush->Color=clBlack ;
	Canvas->Rectangle(0,300,800,340);
	Canvas->Pen->Color=clWhite;
	Canvas->Brush->Color=clWhite ;
	for (int j=0; j < 800; j+=30)
	{
		Canvas->Rectangle(j,(300+340)/2-5,j+20,(300+340)/2+5);
	}

}
