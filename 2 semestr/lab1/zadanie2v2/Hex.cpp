//---------------------------------------------------------------------------

#pragma hdrstop

#include "Hex.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Hex::Hex() : Shape(){}

void Hex::Draw(TCanvas *Canvas){
	Canvas -> MoveTo(X1,Y1);
	Canvas -> LineTo(X2,Y2);
	Canvas -> LineTo(X3,Y3);
	Canvas -> LineTo(X4,Y4);
	Canvas -> LineTo(X5,Y5);
	Canvas -> LineTo(X6,Y6);
	Canvas -> LineTo(X1,Y1);

	X0 = (X1 + X2 + X3 + X4 + X5 + X6)/6;
	Y0 = (Y1 + Y2 + Y3 + Y4 + Y5 + Y6)/6;

	Canvas -> MoveTo(X0,Y0);
	Canvas -> LineTo(X0,Y0);
}

void Hex::Hide(TCanvas* Canvas){
	Canvas -> Pen -> Color = clWhite;
	Draw(Canvas);
	Canvas -> Pen -> Color = clRed;
}

void Hex::MouseDown(TCanvas* Canvas, int X, int Y){

	if (rotated){
		Hide(Canvas);
		rotated = false;
	} else
	if (!start && !error){
		if (X < X1 + 10 && X > X1 - 10 && abs(Y-Y2) <= abs(Y6-Y2) && abs(Y-Y6) <= abs(Y6-Y2)){
			operation = 2;
		}
		else if (X < X4 + 10 && X > X4 - 10 && abs(Y-Y2) <= abs(Y6-Y2) && abs(Y-Y6) <= abs(Y6-Y2)){
			operation = 3;
		}
		else if (Y < Y2 + 10 && Y > Y2 - 10 && abs(X-X1) <= abs(X4-X1) && abs(X-X4) <= abs(X4-X1)){
			operation = 4;
		}
		else if (Y < Y6 + 10 && Y > Y6 - 10 && abs(X-X1) <= abs(X4-X1) && abs(X-X4) <= abs(X4-X1)){
			operation = 5;
		}
		else if (abs(X - X1) <= abs(X4-X1) && abs(X-X4) <= abs(X4-X1)  && abs(Y - Y2) <= abs(Y6-Y2) && abs(Y-Y6) <= abs(Y6-Y2)){
			operation = 6;
		}
		Hide(Canvas);
	}

	switch (operation){
		case 1 :
			X1 = X;
			Y2 = Y;
			Y3 = Y;
			break;
		case 2 :
			X1 = X;
			X2 = X + (X4 - X)/3;
			X3 = X4 - (X4 - X)/3;
			X5 = X3;
			X6 = X2;
			break;
		case 3 :
			X4 = X;
			X3 = X - (X - X1)/3;
			X5 = X3;
			X2 = X1 + (X-X1)/3;
			X6 = X2;
			break;
		case 4 :
			Y2 = Y;
			Y3 = Y;
			Y1 = (Y6 + Y)/2;
			Y4 = Y1;
			break;
		case 5 :
			Y5 = Y;
			Y6 = Y;
			Y1 = (Y2 + Y)/2;
			Y4 = Y1;
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
			x5_save = X5;
			y5_save = Y5;
			x6_save = X6;
			y6_save = Y6;
			break;
	}
	error = false;
	clicked = true;
}

void Hex::MouseUp(TCanvas *Canvas,int X, int Y){
	switch(operation){
		case 1 :
			Y1 = (Y2 + Y)/2;
			X2 = X1 + (X - X1)/3;
			X3 = X - (X - X1)/3;
			X4 = X;
			Y4 = Y1;
			X5 = X3;
			Y5 = Y;
			X6 = X2;
			Y6 = Y;
			break;
		case 2 :
			X1 = X;
			X2 = X + (X4 - X)/3;
			X3 = X4 - (X4 - X)/3;
			X5 = X3;
			X6 = X2;
			break;
		case 3 :
			X4 = X;
			X3 = X - (X - X1)/3;
			X5 = X3;
			X2 = X1 + (X-X1)/3;
			X6 = X2;
			break;
		case 4 :
			Y2 = Y;
			Y3 = Y;
			Y1 = (Y6 + Y)/2;
			Y4 = Y1;
			break;
		case 5 :
			Y5 = Y;
			Y6 = Y;
			Y1 = (Y2 + Y)/2;
			Y4 = Y1;
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
			X5 = X - x_move + x5_save;
			Y5 = Y - y_move + y5_save;
			X6 = X - x_move + x6_save;
			Y6 = Y - y_move + y6_save;
			break;
	}

	if (X1 < 20 || Y2 < 20 || X1 > 490 || Y2 > 430 || X4 < 20 || Y5 < 20 || X4 > 490 || Y6 > 430)	{
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

void Hex::MouseMove(TCanvas *Canvas, int X, int Y){
	if (!clicked) return;
	if (start){
		Y1 = (Y2 + Y)/2;
		X2 = X1 + (X - X1)/3;
		X3 = X - (X - X1)/3;
		X4 = X;
		Y4 = Y1;
		X5 = X3;
		Y5 = Y;
		X6 = X2;
		Y6 = Y;
		start = false;
	}
	Hide(Canvas);
	switch (operation){
		case 1 :
			Y1 = (Y2 + Y)/2;
			X2 = X1 + (X - X1)/3;
			X3 = X - (X - X1)/3;
			X4 = X;
			Y4 = Y1;
			X5 = X3;
			Y5 = Y;
			X6 = X2;
			Y6 = Y;
			break;
		case 2 :
			X1 = X;
			X2 = X + (X4 - X)/3;
			X3 = X4 - (X4 - X)/3;
			X5 = X3;
			X6 = X2;
			break;
		case 3 :
			X4 = X;
			X3 = X - (X - X1)/3;
			X5 = X3;
			X2 = X1 + (X-X1)/3;
			X6 = X2;
			break;
		case 4 :
			Y2 = Y;
			Y3 = Y;
			Y1 = (Y6 + Y)/2;
			Y4 = Y1;
			break;
		case 5 :
			Y5 = Y;
			Y6 = Y;
			Y1 = (Y2 + Y)/2;
			Y4 = Y1;
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
			X5 = X - x_move + x5_save;
			Y5 = Y - y_move + y5_save;
			X6 = X - x_move + x6_save;
			Y6 = Y - y_move + y6_save;
			break;
	}

	if (X1 < 20 || Y2 < 20 || X1 > 490 || Y2 > 430 || X4 < 20 || Y5 < 20 || X4 > 490 || Y6 > 430)	{
		ShowMessage("You can't draw here!");
		clicked = false;
		error = true;
		operation = 1;
		return;
	}

	Draw(Canvas);
}

void Hex::Set_Angle(float a){
	this -> angle = a;
}

float Hex::Get_Angle(){
	return angle;
}

void Hex::Rotate(TCanvas* Canvas){

	X0 = (X1 + X2 + X3 + X4 + X5 + X6)/6;
	Y0 = (Y1 + Y2 + Y3 + Y4 + Y5 + Y6)/6;
	float a = 0.05;
	angle -= a;
	int X1_new, Y1_new, X2_new, Y2_new, X3_new, Y3_new, X4_new, Y4_new, X5_new,Y5_new,X6_new,Y6_new;
	X1_new = round(X0 + (X1 - X0) * cos(a) - (Y1 - Y0) * sin(a));
	Y1_new = round(Y0 + (X1 - X0) * sin(a) + (Y1 - Y0) * cos(a));
	X2_new = round(X0 + (X2 - X0) * cos(a) - (Y2 - Y0) * sin(a));
	Y2_new = round(Y0 + (X2 - X0) * sin(a) + (Y2 - Y0) * cos(a));
	X3_new = round(X0 + (X3 - X0) * cos(a) - (Y3 - Y0) * sin(a));
	Y3_new = round(Y0 + (X3 - X0) * sin(a) + (Y3 - Y0) * cos(a));
	X4_new = round(X0 + (X4 - X0) * cos(a) - (Y4 - Y0) * sin(a));
	Y4_new = round(Y0 + (X4 - X0) * sin(a) + (Y4 - Y0) * cos(a));
	X5_new = round(X0 + (X5 - X0) * cos(a) - (Y5 - Y0) * sin(a));
	Y5_new = round(Y0 + (X5 - X0) * sin(a) + (Y5 - Y0) * cos(a));
	X6_new = round(X0 + (X6 - X0) * cos(a) - (Y6 - Y0) * sin(a));
	Y6_new = round(Y0 + (X6 - X0) * sin(a) + (Y6 - Y0) * cos(a));
	Hide(Canvas);
	X1 = X1_new;
	Y1 = Y1_new;
	X2 = X2_new;
	Y2 = Y2_new;
	X3 = X3_new;
	Y3 = Y3_new;
	X4 = X4_new;
	Y4 = Y4_new;
	X5 = X5_new;
	Y5 = Y5_new;
	X6 = X6_new;
	Y6 = Y6_new;
	Draw(Canvas);

	rotated = true;
}

void Hex::WheelUp(TCanvas *Canvas){
	if (rotated || start) return;
	Hide(Canvas);
	if(X1 > X4){
		int t = X1;
		X1 = X4;
		X4 = t;

		t = X2;
		X2 = X3;
		X3 = t;

		t = X6;
		X6 = X5;
		X5 = t;
	}
	if (Y2 > Y6){
	   int t = Y2;
		Y2 = Y6;
		Y6 = t;

		t = Y3;
		Y3 = Y5;
		Y5 = t;
	}

	X1-=3;
	Y2 -=3;
	Y3 -=3;
	X4+=3;
	Y5+=3;
	Y6+=3;

	X2 = X1 + (X4 - X1)/3;
	X3 = X4 - (X4 - X1)/3;
	X5 = X3;
	X6 = X2;

	Draw(Canvas);
}

void Hex::WheelDown(TCanvas *Canvas){
	if (rotated || start) return;
	Hide(Canvas);
	if(X1 > X4){
		int t = X1;
		X1 = X4;
		X4 = t;

		t = X2;
		X2 = X3;
		X3 = t;

		t = X6;
		X6 = X5;
		X5 = t;
	}
	if (Y2 > Y6){
	   int t = Y2;
		Y2 = Y6;
		Y6 = t;

		t = Y3;
		Y3 = Y5;
		Y5 = t;
	}

	X1+=3;
	Y2+=3;
	Y3+=3;
	X4-=3;
	Y5-=3;
	Y6-=3;

	X2 = X1 + (X4 - X1)/3;
	X3 = X4 - (X4 - X1)/3;
	X5 = X3;
	X6 = X2;

	Draw(Canvas);
}

float Hex::Get_area(){
	return abs((Y6-Y2)*(X4-X1)) - abs(2*(Y1-Y2)*(X2-X1));
}
float Hex::Get_per(){
	float p = 0;
	float a1,a2,a3,a4,a5,a6;
	a1 = sqrt(pow(X2-X1,2)+pow(Y2-Y1,2));
	a2 = sqrt(pow(X3-X2,2)+pow(Y3-Y2,2));
	a3 = sqrt(pow(X4-X3,2)+pow(Y4-Y3,2));
	a4 = sqrt(pow(X5-X4,2)+pow(Y5-Y4,2));
	a5 = sqrt(pow(X6-X5,2)+pow(Y6-Y5,2));
	a6 = sqrt(pow(X6-X1,2)+pow(Y6-Y1,2));
	p = a1 + a2 + a3 + a4 + a5 + a6;
	return p;
}
