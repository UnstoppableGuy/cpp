//---------------------------------------------------------------------------

#pragma hdrstop

#include "CustomRectangle.h"
#include "Task2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MyRectangle :: MyRectangle(int x1, int y1, int x2, int y2)
{
	points = new TPoint[4];
	points[0].x = points[3].x = x1;
	points[1].x = points[2].x = x2;
	points[0].y = points[1].y = y1;
	points[2].y = points[3].y = y2;
}

MyRectangle :: MyRectangle()
{
	points = new TPoint[4];
}

MyRectangle :: ~MyRectangle()
{
	delete[] points;
}

void MyRectangle::draw()
{
	MainForm->Image1->Canvas->Brush->Color = clSilver;
	MainForm->Image1->Canvas->FillRect(Rect(0, 0, 800, 800));
	MainForm->Image1->Canvas->Brush->Color = clWhite;
	MainForm->Image1->Canvas->Pen->Width = 4;
	MainForm->Image1->Canvas->Polygon(points, 3);
}

void MyRectangle::move(int a, int b)
{
	int cx = a - points[0].x;
	int cy = b - points[0].y;
	for (int i = 0; i < 4; i++)
	{
		points[i].x += cx;
		points[i].y += cy;
	}
	c_x += cx;
	c_y += cy;
	draw();
}

void MyRectangle::turn(int a, int b, float angle, int old[2][4])
{
	   points[0].x = round((old[0][0] - a) * cos(angle)) - round((old[1][0] - b) * sin(angle)) + a;
	   points[1].x = round((old[0][1] - a) * cos(angle)) - round((old[1][1] - b) * sin(angle)) + a;
	   points[2].x = round((old[0][2] - a) * cos(angle)) - round((old[1][2] - b) * sin(angle)) + a;
	   points[3].x = round((old[0][3] - a) * cos(angle)) - round((old[1][3] - b) * sin(angle)) + a;
	   points[0].y = round((old[0][0] - a) * sin(angle)) + round((old[1][0] - b) * cos(angle)) + b;
	   points[1].y = round((old[0][1] - a) * sin(angle)) + round((old[1][1] - b) * cos(angle)) + b;
	   points[2].y = round((old[0][2] - a) * sin(angle)) + round((old[1][2] - b) * cos(angle)) + b;
	   points[3].y = round((old[0][3] - a) * sin(angle)) + round((old[1][3] - b) * cos(angle)) + b;
	   draw();
}

void MyRectangle::scale(int a, int b, float dk, int old[2][4])
{
	  points[0].x = round((old[0][0] - a) * dk) + a;
	  points[1].x = round((old[0][1] - a) * dk) + a;
	  points[2].x = round((old[0][2] - a) * dk) + a;
	  points[3].x = round((old[0][3] - a) * dk) + a;
	  points[0].y = round((old[1][0] - b) * dk) + b;
	  points[1].y = round((old[1][1] - b) * dk) + b;
	  points[2].y = round((old[1][2] - b) * dk) + b;
	  points[3].y = round((old[1][3] - b) * dk) + b;
	  draw();
}

int MyRectangle::getX(int i)
{
	return points[i].x;
}

int MyRectangle::getY(int i)
{
	return points[i].y;
}


void MyRectangle::remake(int x1, int y1, int x2, int y2)
{
	points[0].x = points[3].x = x1;
	points[1].x = points[2].x = x2;
	points[0].y = points[1].y = y1;
	points[2].y = points[3].y = y2;
}
