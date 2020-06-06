//---------------------------------------------------------------------------

#pragma hdrstop

#include "Elps.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Elps::Elps() : Shape(){}

Elps::Elps(int X1,int Y1, int X2, int Y2,int X3,int Y3, int X4, int Y4) : Shape(){
	this -> X1 = X1;
	this -> Y1 = Y1;
	this -> X2 = X2;
	this -> Y2 = Y2;
	this -> X3 = X3;
	this -> Y3 = Y3;
	this -> X4 = X4;
	this -> Y4 = Y4;
}

void Elps::Draw(TCanvas *Canvas){
	X0 = (X1 + X2 + X3 + X4)/4, Y0 = (Y1 + Y2 + Y3 + Y4)/4;

	int sx, sy, rx, ry, i;

	sx = X0 + rot_x(X2 - X0,0,d_angle);
	sy = Y0 + rot_y(X2 - X0,0,d_angle);

	Canvas -> MoveTo(sx,sy);

	double du = 0;

	for (i = 0; i < 40; i++){
		du = du + 3.14/20;

		rx = round((X2-X0)*cos(du));
		ry = round((Y0-Y2)*sin(du));

		Canvas -> LineTo(X0+rot_x(rx,ry,d_angle),Y0+rot_y(rx,ry,d_angle));
	}
	Canvas -> LineTo(sx,sy);

	Canvas -> MoveTo(X0,Y0);
	Canvas -> LineTo(X0,Y0);

}

void Elps::Hide(TCanvas* Canvas){
	Canvas -> Pen -> Color = clWhite;
	Draw(Canvas);
	Canvas -> Pen -> Color = clRed;
}

void Elps::MouseDown(TCanvas* Canvas, int X, int Y){

	if (rotated){
		Hide(Canvas);
		d_angle = 0;
		rotated = false;
	} else
	if (!start && !error){
		if (X < X1 + 10 && X > X1 - 10 && abs(Y-Y1) <= abs(Y3-Y1) && abs(Y-Y3) <= abs(Y3-Y1)){
			operation = 2;
		}
		else if (X < X2 + 10 && X > X2 - 10 && abs(Y-Y1) <= abs(Y3-Y1) && abs(Y-Y3) <= abs(Y3-Y1)){
			operation = 3;
		}
		else if (Y < Y1 + 10 && Y > Y1 - 10 && abs(X-X1) <= abs(X2-X1) && abs(X-X2) <= abs(X2-X1)){
			operation = 4;
		}
		else if (Y < Y3 + 10 && Y > Y3 - 10 && abs(X-X1) <= abs(X2-X1) && abs(X-X2) <= abs(X2-X1)){
			operation = 5;
		}
		else if (abs(X - X1) <= abs(X2-X1) && abs(X-X2) <= abs(X2-X1)  && abs(Y - Y1) <= abs(Y3-Y1) && abs(Y-Y3) <= abs(Y3-Y1)){
			operation = 6;
		}
		Hide(Canvas);
	}

	switch (operation){
		case 1 :
			X1 = X;
			X4 = X;
			Y1 = Y;
			Y2 = Y;
			break;
		case 2 :
			X1 = X;
			X4 = X;
			break;
		case 3 :
			X2 = X;
			X3 = X;
			break;
		case 4 :
			Y1 = Y;
			Y2 = Y;
			break;
		case 5 :
			Y3 = Y;
			Y4 = Y;
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
			x4_save = X4;
			y4_save = Y4;
			break;
	}
	error = false;
	clicked = true;
}

void Elps::MouseUp(TCanvas *Canvas,int X, int Y){
	switch(operation){
		case 1 :
			X2 = X;
			X3 = X;
			Y3 = Y;
			Y4 = Y;
			break;
		case 2 :
			X1 = X;
			X4 = X;
			break;
		case 3 :
			X2 = X;
			X3 = X;
			break;
		case 4 :
			Y1 = Y;
			Y2 = Y;
			break;
		case 5 :
			Y3 = Y;
			Y4 = Y;
			break;
		case 6 :
			X1 = X - x_move + x1_save;
			Y1 = Y - y_move + y1_save;
			X2 = X - x_move + x2_save;
			Y2 = Y - y_move + y2_save;
			X3 = X - x_move + x3_save;
			Y3 = Y - y_move + y3_save;
			X4 = X - x_move + x4_save;
			Y4 = Y - y_move + y4_save;
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

void Elps::MouseMove(TCanvas *Canvas, int X, int Y){
	if (!clicked) return;
	if (start){
		X2 = X;
		X3 = X;
		Y3 = Y;
		Y4 = Y;
		start = false;
	}
	Hide(Canvas);
	switch (operation){
		case 1 :
			X2 = X;
			X3 = X;
			Y3 = Y;
			Y4 = Y;
			break;
		case 2 :
			X1 = X;
			X4 = X;
			break;
		case 3 :
			X2 = X;
			X3 = X;
			break;
		case 4 :
			Y1 = Y;
			Y2 = Y;
			break;
		case 5 :
			Y3 = Y;
			Y4 = Y;
			break;
		case 6 :
			X1 = X - x_move + x1_save;
			Y1 = Y - y_move + y1_save;
			X2 = X - x_move + x2_save;
			Y2 = Y - y_move + y2_save;
			X3 = X - x_move + x3_save;
			Y3 = Y - y_move + y3_save;
			X4 = X - x_move + x4_save;
			Y4 = Y - y_move + y4_save;
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

void Elps::Set_Angle(float a){
	this -> angle = a;
}

float Elps::Get_Angle(){
	return angle;
}

void Elps::Rotate(TCanvas* Canvas){

	Hide(Canvas);
	d_angle += 0.05;
	angle -= 0.05;
	Draw(Canvas);
	rotated = true;
}

void Elps::WheelUp(TCanvas *Canvas){
	if (rotated || start) return;
	Hide(Canvas);
	if(X1 > X2){
		int t = X1;
		X1 = X2;
		X2 = t;

		t = X4;
		X4 = X3;
		X3 = t;
	}
	if (Y2 > Y3){
	   int t = Y2;
		Y2 = Y3;
		Y3 = t;

		t = Y1;
		Y1 = Y4;
		Y4 = t;
	}
	X1-=3;
	Y1-=3;
	X2+=3;
	Y2-=3;
	X3+=3;
	Y3+=3;
	X4-=3;
	Y4+=3;

	Draw(Canvas);
}

void Elps::WheelDown(TCanvas *Canvas){
	if (rotated || start) return;
	Hide(Canvas);
	if(X1 > X2){
		int t = X1;
		X1 = X2;
		X2 = t;

		t = X4;
		X4 = X3;
		X3 = t;
	}
	if (Y2 > Y3){
	   int t = Y2;
		Y2 = Y3;
		Y3 = t;

		t = Y1;
		Y1 = Y4;
		Y4 = t;
	}
	X1+=3;
	Y1+=3;
	X2-=3;
	Y2+=3;
	X3-=3;
	Y3-=3;
	X4+=3;
	Y4-=3;
	Draw(Canvas);
}

int Elps::rot_x(int x, int y, double a){
	return round(x * cos(a) - y * sin(a));
}

int Elps::rot_y(int x, int y, double a){
	return round(x * sin(a) + y * cos(a));
}

float Elps::Get_area(){
	return abs(3.14*(Y4-Y1)*(X2-X1)/4.0);
}
float Elps::Get_per(){
	return 2*3.14*sqrt((pow(X2-X1,2)+pow(Y4-Y1,2))/8);
}