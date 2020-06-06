//---------------------------------------------------------------------------
#include "Plane.h"
#include <vcl.h>
#ifndef landing_stripH
#define landing_stripH
//---------------------------------------------------------------------------
#endif
class Strip: Plane
{
  int v1,b1,v2,b2;
  public:
  Strip (int n1,int m1,int n2,int m2){v1=n1;b1=m1;v2=n2;b2=m2;}
  void show(TCanvas *Canvas)
  {

  }
  void move(TCanvas *Canvas)
  {

  }
  void hide(TCanvas *Canvas)
  {

  }
} ;