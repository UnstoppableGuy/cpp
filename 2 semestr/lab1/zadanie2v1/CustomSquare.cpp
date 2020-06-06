//---------------------------------------------------------------------------

#pragma hdrstop

#include "CustomSquare.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MySquare::MySquare(int x, int y, int a)
{
	points[0].x = points[3].x = x;
	points[0].y = points[1].y = y;
	points[1].x = points[2].x = x + a;
	points[2].y = points[3].y = y + a;
}

void MySquare::remake(int x, int y, int a)
{
    points[0].x = points[3].x = x;
	points[0].y = points[1].y = y;
	points[1].x = points[2].x = x + a;
	points[2].y = points[3].y = y + a;
}
