//---------------------------------------------------------------------------

#pragma hdrstop

#include "Triangle.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Tri::Tri() : Shape(){}

Tri::Tri(int X1,int Y1, int X2, int Y2,int X3,int Y3) : Shape(){
	this -> X1 = X1;
	this -> Y1 = Y1;
	this -> X2 = X2;
	this -> Y2 = Y2;
	this -> X3 = X3;
	this -> Y3 = Y3;
}

void Tri::Draw(TCanvas *Canvas){
	Canvas -> MoveTo(X1,Y1);
	Canvas -> LineTo(X2,Y2);
	Canvas -> LineTo(X3,Y3);
	Canvas -> LineTo(X1,Y1);

	X0 = (X1 + X2 + X3)/3;
	Y0 = (Y1 + Y2 + Y3)/3;

	Canvas -> MoveTo(X0,Y0);
	Canvas -> LineTo(X0,Y0);
}

void Tri::Hide(TCanvas* Canvas){
	Canvas -> Pen -> Color = clWhite;
	Draw(Canvas);
	Canvas -> Pen -> Color = clRed;
}

void Tri::MouseDown(TCanvas* Canvas, int X, int Y){

	if (rotated){
		Hide(Canvas);
		rotated = false;
	} else
	if (!start && !error){
		if (X1 - 10 < X && X1 + 10 > X && Y1 - 10 < Y && Y1 + 10 > Y){
			operation = 2;
		}
		else if (X2 - 10 < X && X2 + 10 > X && Y2 - 10 < Y && Y2 + 10 > Y){
			operation = 3;
		}
		else if (X3 - 10 < X && X3 + 10 > X && Y3 - 10 < Y && Y3 + 10 > Y){
			operation = 4;
		}
		else if (check_in(X,Y) == true){
			operation = 6;
		}
		Hide(Canvas);
	}

	switch (operation){
		case 1 :
			X1 = X;
			Y1 = Y;
			X2 = X;
			break;
		case 2 :
			X1 = X;
			Y1 = Y;
			break;
		case 3 :
			X2 = X;
			Y2 = Y;
			break;
		case 4 :
			X3 = X;
			Y3 = Y;
			break;
		case 6 :
			x_move = X;
			y_move = Y;
			x1_save = X1;
			y1_save = Y1;
			x2_save = X2;
			y2_save = Y2;
			x3_save = X3;
			y3_save = Y3;
			break;
	}
	error = false;
	clicked = true;
}

void Tri::MouseUp(TCanvas *Canvas,int X, int Y){
	switch(operation){
		case 1 :
			X3 = X;
			Y3 = Y;
			Y2 = Y;
			break;
		case 2 :
			X1 = X;
			Y1 = Y;
			break;
		case 3 :
			X2 = X;
			Y2 = Y;
			break;
		case 4 :
			X3 = X;
			Y3 = Y;
			break;
		case 6 :
			X1 = X - x_move + x1_save;
			Y1 = Y - y_move + y1_save;
			X2 = X - x_move + x2_save;
			Y2 = Y - y_move + y2_save;
			X3 = X - x_move + x3_save;
			Y3 = Y - y_move + y3_save;
			break;
	}

	if (X1 < 20 || Y1 < 20 || X1 > 490 || Y1 > 430 || X3 < 20 || Y3 < 20 || X3 > 490 || Y3 > 430)	{
		ShowMessage("You can't draw here!");
		clicked = false;
		error = true;
		operation = 1;
		return;
	}

	Draw(Canvas);

	operation = 1;

	clicked = false;
}

void Tri::MouseMove(TCanvas *Canvas, int X, int Y){
	if (!clicked) return;
	if (start){
		X3 = X;
		Y3 = Y;
		Y2 = Y;
		start = false;
	}
	Hide(Canvas);
	switch (operation){
		case 1 :
			X3 = X;
			Y3 = Y;
			Y2 = Y;
			break;
		case 2 :
			X1 = X;
			Y1 = Y;
			break;
		case 3 :
			X2 = X;
			Y2 = Y;
			break;
		case 4 :
			X3 = X;
			Y3 = Y;
			break;
		case 6 :
			X1 = X - x_move + x1_save;
			Y1 = Y - y_move + y1_save;
			X2 = X - x_move + x2_save;
			Y2 = Y - y_move + y2_save;
			X3 = X - x_move + x3_save;
			Y3 = Y - y_move + y3_save;
			break;
	}

	if (X1 < 20 || Y1 < 20 || X1 > 490 || Y1 > 430 || X3 < 20 || Y3 < 20 || X3 > 490 || Y3 > 430)	{
		ShowMessage("You can't draw here!");
		clicked = false;
		error = true;
		operation = 1;
		return;
	}

	Draw(Canvas);
}

void Tri::Set_Angle(float a){
	this -> angle = a;
}

float Tri::Get_Angle(){
	return angle;
}

void Tri::Rotate(TCanvas* Canvas){

	X0 = (X1 + X2 + X3)/3;
	Y0 = (Y1 + Y2 + Y3)/3;
	float a = 0.05;
	angle -= a;
	int X1_new, Y1_new, X2_new, Y2_new, X3_new, Y3_new;
	X1_new = round(X0 + (X1 - X0) * cos(a) - (Y1 - Y0) * sin(a));
	Y1_new = round(Y0 + (X1 - X0) * sin(a) + (Y1 - Y0) * cos(a));
	X2_new = round(X0 + (X2 - X0) * cos(a) - (Y2 - Y0) * sin(a));
	Y2_new = round(Y0 + (X2 - X0) * sin(a) + (Y2 - Y0) * cos(a));
	X3_new = round(X0 + (X3 - X0) * cos(a) - (Y3 - Y0) * sin(a));
	Y3_new = round(Y0 + (X3 - X0) * sin(a) + (Y3 - Y0) * cos(a));

	Hide(Canvas);
	X1 = X1_new;
	Y1 = Y1_new;
	X2 = X2_new;
	Y2 = Y2_new;
	X3 = X3_new;
	Y3 = Y3_new;
	Draw(Canvas);

	rotated = true;
}

void Tri::WheelUp(TCanvas *Canvas){
	if (rotated || start) return;
	Hide(Canvas);

	float k = 1.05;

	float a = sqrt(pow(X1-X0,2) + pow(Y1-Y0,2));
	float cos = (float)(X1-X0)/a;
	float sin = (float)(Y1-Y0)/a;
	X1 += (k-1)*a*cos;
	Y1 += (k-1)*a*sin;

	a = sqrt(pow(X2-X0,2) + pow(Y2-Y0,2));
	cos = (float)(X2-X0)/a;
	sin = (float)(Y2-Y0)/a;
	X2 += (k-1)*a*cos;
	Y2 += (k-1)*a*sin;

	a = sqrt(pow(X3-X0,2) + pow(Y3-Y0,2));
	cos = (float)(X3-X0)/a;
	sin = (float)(Y3-Y0)/a;
	X3 += (k-1)*a*cos;
	Y3 += (k-1)*a*sin;

	Draw(Canvas);
}

void Tri::WheelDown(TCanvas *Canvas){
	if (rotated || start) return;
	Hide(Canvas);

	float k = 0.95;

	float a = sqrt(pow(X1-X0,2) + pow(Y1-Y0,2));
	float cos = (float)(X1-X0)/a;
	float sin = (float)(Y1-Y0)/a;
	X1 += (k-1)*a*cos;
	Y1 += (k-1)*a*sin;

	a = sqrt(pow(X2-X0,2) + pow(Y2-Y0,2));
	cos = (float)(X2-X0)/a;
	sin = (float)(Y2-Y0)/a;
	X2 += (k-1)*a*cos;
	Y2 += (k-1)*a*sin;

	a = sqrt(pow(X3-X0,2) + pow(Y3-Y0,2));
	cos = (float)(X3-X0)/a;
	sin = (float)(Y3-Y0)/a;
	X3 += (k-1)*a*cos;
	Y3 += (k-1)*a*sin;

	Draw(Canvas);
}

bool Tri::check_in(int x, int y){
	int a,b,c;
	a = (X1 - x) * (Y2 - Y1) - (X2 - X1) * (Y1 - y);
	b = (X2 - x) * (Y3 - Y2) - (X3 - X2) * (Y2 - y);
	c = (X3 - x) * (Y1 - Y3) - (X1 - X3) * (Y3 - y);
	if ((a <= 0 && b <= 0 && c <= 0) || (a >= 0 && b >= 0 && c >= 0)) return true;
	return false;
}

float Tri::Get_area(){
	float p,a,b,c;
	a = sqrt(pow(X2-X1,2)+pow(Y2-Y1,2));
	b = sqrt(pow(X3-X2,2)+pow(Y3-Y2,2));
	c = sqrt(pow(X3-X1,2)+pow(Y3-Y1,2));
	p = (a + b + c)/2;
	float s = sqrt(p*(p-a)*(p-b)*(p-c));
	return s;
}
float Tri::Get_per(){
	float a,b,c;
	a = sqrt(pow(X2-X1,2)+pow(Y2-Y1,2));
	b = sqrt(pow(X3-X2,2)+pow(Y3-Y2,2));
	c = sqrt(pow(X3-X1,2)+pow(Y3-Y1,2));
	return a + b + c;
}
