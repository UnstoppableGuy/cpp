//---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include "landing_strip.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Strip::show(TCanvas *Canvas)
{
	Canvas->Pen->Color=clBlack;
	Canvas->Brush->Color=clBlack ;
	Canvas->Rectangle(v1,b1,v2,b2);
	Canvas->Pen->Color=clWhite;
	Canvas->Brush->Color=clWhite;
	for (int i = v1; i < v2; i=+15)
	{
		Canvas->Rectangle(i,(b1+b2)/2-5,i+10,(b1+b2)/2-5);
	}

}
void Strip::move(TCanvas *Canvas) {}
void Strip::hide(TCanvas *Canvas)
{
	Canvas->Pen->Color=clWhite;
	Canvas->Brush->Color=clWhite ;
	Canvas->Rectangle(v1,b1,v2,b2);
	}
