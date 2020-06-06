//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef PlaneH
#define PlaneH
//---------------------------------------------------------------------------
#endif
class Plane
{
int x1,x2,y1,y2,r;
public:
Plane (int a1,int b1,int a2,int b2,int d){x1=a1;x2=a2;y1=b1;y2=b2;r=d;}
	void show(TCanvas *Canvas);
	void move(TCanvas *Canvas);
	void hide(TCanvas *Canvas);
    void trip(TCanvas *Canvas);
};