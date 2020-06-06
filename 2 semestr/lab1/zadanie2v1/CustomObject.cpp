//---------------------------------------------------------------------------

#pragma hdrstop

#include "CustomObject.h"
#include "vcl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MyObject :: MyObject()
{
	n = 0;
}

MyObject :: MyObject(int cnt)
{
	n = cnt;
	points = new TPoint[n];
}

MyObject :: ~MyObject()
{
	delete[] points;
}

int MyObject :: round(float value)
{
	int temp = value;
	if(value - temp > 0.5) return temp + 1;
	else return temp;
}
