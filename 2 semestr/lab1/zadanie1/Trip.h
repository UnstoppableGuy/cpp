//---------------------------------------------------------------------------
#include "Plane.h"
#ifndef TripH
#define TripH
//---------------------------------------------------------------------------
#endif
class Trip//:public Plane
{
   int x1,y1,x2,y2,length;
   public:
   Trip (int a1,int b1,int a2, int b2,int lt){
   x1=a1;
   y1=b1;
   x2=a2;
   y2=b2;
   length=lt;}
   void show (TCanvas *Canvas);
   void move (TCanvas *Canvas);
   void hide (TCanvas *Canvas);
};