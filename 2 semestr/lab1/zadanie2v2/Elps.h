//---------------------------------------------------------------------------

#ifndef ElpsH
#define ElpsH
//---------------------------------------------------------------------------
#endif

#ifndef ShapeH
#define ShapeH
#include "Shape.h"
#endif

#include <vcl.h>

class Elps : public Shape{
	int X1,Y1,X2,Y2,X3,Y3,X4,Y4,X0,Y0, operation = 1, x_move,y_move;
		int x1_save,y1_save,x2_save,y2_save, x3_save,y3_save,x4_save,y4_save;
		float angle = 0, d_angle = 0;
		bool clicked = false,start = true, error = false, rotated = false;
	public:
		Elps();
		Elps(int,int,int,int,int,int,int,int);
		void Draw(TCanvas*);
		void Hide(TCanvas*);
		void MouseDown(TCanvas*, int, int);
		void MouseUp(TCanvas*,int,int);
		void MouseMove(TCanvas*,int,int);
		void WheelUp(TCanvas*);
		void WheelDown(TCanvas*);
		void Rotate(TCanvas*);
		void Set_Angle(float);
		float Get_Angle();

		int rot_x(int, int, double);
		int rot_y(int, int, double);

        float Get_area();
		float Get_per();
};