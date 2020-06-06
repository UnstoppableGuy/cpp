//---------------------------------------------------------------------------

#pragma hdrstop

#include "CustomCircle.h"
#include "math.h"
#include "Task2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


MyCircle::MyCircle()
{
   points = new TPoint[200];
}

MyCircle::MyCircle(int x, int y, int a)
{
   int b = a;
   this->n = 100;
   points = new TPoint[n];
   int dx = this->round((float) 4 * a / n);
   if(dx == 0) dx = 1;
   int cx = -a;
   for(int i = 0; i < n / 2; i++, cx += dx)
   {
	   points[i].x = cx + x;
	   float m, k, p;
	   m = (float)cx / (float)a;
	   k = 1 - m * m;
	   p = b * b;
	   points[i].y = -(powf(p * k, (float)0.5)) + y;
   }
   for(int i = n / 2; i < n; i++, cx -= dx)
   {
	   points[i].x = cx + x;
	   points[i].x = cx + x;
	   float m, k, p;
	   m = (float)cx / (float)a;
	   k = 1 - m * m;
	   p = b * b;
	   points[i].y = (powf(p * k, (float)0.5)) + y;
   }

}


void MyCircle::draw()
{
	MainForm->Image1->Canvas->Brush->Color = clSilver;
	MainForm->Image1->Canvas->FillRect(Rect(0, 0, 800, 800));
	MainForm->Image1->Canvas->Brush->Color = clWhite;
	MainForm->Image1->Canvas->Pen->Width = 4;
	MainForm->Image1->Canvas->Polygon(points, n - 1);
}

int MyCircle::getX(int i)
{
	return points[i].x;
}

int MyCircle::getY(int i)
{
	return points[i].y;
}

void MyCircle::move(int a, int b)
{
	int newx = a - points[0].x;
	int newy = b - points[0].y;
	for(int i = 0; i < n; i++)
	{
		points[i].x += newx;
		points[i].y += newy;
	}
	c_x += newx;
	c_y += newy;
	draw();
}

void MyCircle::turn(int a, int b, float angle, int old[2][100])
{
	for(int i = 0; i < 100; i++)
	{
	   points[i].x = round((old[0][i] - a) * cos(angle)) - round((old[1][i] - b) * sin(angle)) + a;
	   points[i].y = round((old[0][i] - a) * sin(angle)) + round((old[1][i] - b) * cos(angle)) + b;
	}
	draw();
}

void MyCircle::scale(int a, int b, float k, int old[2][100])
{
   for(int i = 0; i < 100; i++)
   {
	  points[i].x = round((old[0][i] - a) * k) + a;
	  points[i].y = round((old[1][i] - b) * k) + b;

   }
   draw();
}

void MyCircle::remake(int x, int y, int a)
{
   int b = a;
   int dx = round((float)4 * a / n);
   if(dx == 0) dx = 1;
   int cx = -a;
   for(int i = 0; i < n / 2; i++, cx += dx)
   {
	   points[i].x = cx + x;
	   float m, k, p;
	   m = (float)cx / (float)a;
	   k = 1 - m * m;
	   p = b * b;
	   points[i].y = -(powf(p * k, (float)0.5)) + y;
   }
   for(int i = n / 2; i < n; i++, cx -= dx)
   {
	   points[i].x = cx + x;
	   points[i].x = cx + x;
	   float m, k, p;
	   m = (float)cx / (float)a;
	   k = 1 - m * m;
	   p = b * b;
	   points[i].y = (powf(p * k, (float) 0.5)) + y;
   }
}