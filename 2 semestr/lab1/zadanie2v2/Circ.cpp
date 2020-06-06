//---------------------------------------------------------------------------

#pragma hdrstop

#include "Circ.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Circ::Circ() : Shape(){}

Circ::Circ(int X1,int Y1, int X2, int Y2,int X3,int Y3, int X4, int Y4) : Shape(){
	this -> X1 = X1;
	this -> Y1 = Y1;
	this -> X2 = X2;
	this -> Y2 = Y2;
	this -> X3 = X3;
	this -> Y3 = Y3;
	this -> X4 = X4;
	this -> Y4 = Y4;
}

void Circ::Draw(TCanvas *Canvas){
	Canvas -> Ellipse(X1,Y1,X1 + Y4-Y1,Y3);

	int X0 = (2 * X1 + Y4 - Y1)/2;
	int Y0 = (Y1 + Y3)/2;

	Canvas -> MoveTo(X0,Y0);
	Canvas -> LineTo(X0,Y0);
}

void Circ::Hide(TCanvas* Canvas){
	Canvas -> Pen -> Color = clWhite;
	Draw(Canvas);
	Canvas -> Pen -> Color = clRed;
}

void Circ::MouseDown(TCanvas* Canvas, int X, int Y){

	if (rotated){
		Hide(Canvas);
		rotated = false;
	} else
	if (!start && !error){

		if (abs(X - X1) <= abs(X2-X1) && abs(X-X2) <= abs(X2-X1)  && abs(Y - Y1) <= abs(Y3-Y1) && abs(Y-Y3) <= abs(Y3-Y1)){
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

void Circ::MouseUp(TCanvas *Canvas,int X, int Y){
	switch(operation){
		case 1 :
			Y3 = Y;
			Y4 = Y;
			X2 = X1 + (Y3-Y1);
			X3 = X2;
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

void Circ::MouseMove(TCanvas *Canvas, int X, int Y){
	if (!clicked) return;
	if (start){
        Y3 = Y;
		Y4 = Y;
		X2 = X1 + (Y3-Y1);
		X3 = X2;
		start = false;
	}
	Hide(Canvas);
	switch (operation){
		case 1 :
            Y3 = Y;
			Y4 = Y;
			X2 = X1 + (Y3-Y1);
			X3 = X2;
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

void Circ::Set_Angle(float a){
	this -> angle = a;
}

float Circ::Get_Angle(){
	return angle;
}

void Circ::Rotate(TCanvas* Canvas){
    angle = 0;
	rotated = true;
}

void Circ::WheelUp(TCanvas *Canvas){
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

void Circ::WheelDown(TCanvas *Canvas){
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

float Circ::Get_area(){
    return 3.14*(Y4-Y1)*(Y4-Y1)/4.0;
}
float Circ::Get_per(){
	return 3.14*(Y4-Y1);
}