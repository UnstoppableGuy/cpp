//---------------------------------------------------------------------------

#ifndef TriangleH
#define TriangleH
//---------------------------------------------------------------------------
#endif

#ifndef ShapeH
#define ShapeH
#include "Shape.h"
#endif

#include <vcl.h>
#include <math.h>

class Tri : public Shape{
	private:
		int X1,Y1,X2,Y2,X3,Y3, operation = 1, x_move,y_move,X0,Y0;
		int x1_save,y1_save,x2_save,y2_save, x3_save,y3_save;
		float angle = 0;
		bool clicked = false,start = true, error = false, rotated = false;
	public:
		Tri();
		Tri(int,int,int,int,int,int);
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
		bool check_in(int x, int y);

        float Get_area();
		float Get_per();
};
