//---------------------------------------------------------------------------

#ifndef ShapeH
#define ShapeH
//---------------------------------------------------------------------------
#endif

#include <vcl.h>

class Shape{
	public:
		virtual void Draw(TCanvas*) = 0;
		virtual void Hide(TCanvas*) = 0;
		virtual void MouseDown(TCanvas*, int, int) = 0;
		virtual void MouseUp(TCanvas*,int,int) = 0;
		virtual void MouseMove(TCanvas*,int,int) = 0;
		virtual void WheelUp(TCanvas*) = 0;
		virtual void WheelDown(TCanvas*) = 0;
		virtual void Rotate(TCanvas*) = 0;
		virtual void Set_Angle(float) = 0;
		virtual float Get_Angle() = 0;
		virtual float Get_area() = 0;
		virtual float Get_per() = 0;
};
