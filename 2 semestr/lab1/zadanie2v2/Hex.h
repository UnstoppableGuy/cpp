//---------------------------------------------------------------------------

#ifndef HexH
#define HexH
//---------------------------------------------------------------------------
#endif

#ifndef ShapeH
#define ShapeH
#include "Shape.h"
#endif

#include <vcl.h>
#include <math.h>

class Hex : public Shape{
	private:
		int X1,Y1,X2,Y2,X3,Y3,X4,Y4,X5,Y5,X6,Y6, operation = 1, x_move,y_move;
		int x1_save,y1_save,x2_save,y2_save, x3_save,y3_save,x4_save,y4_save,x5_save,y5_save,x6_save,y6_save;
        int X0,Y0;
		float angle = 0;
		bool clicked = false,start = true, error = false, rotated = false;
	public:
		Hex();
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

        float Get_area();
		float Get_per();
};