//---------------------------------------------------------------------------

#ifndef CustomEllipseH
#define CustomEllipseH

#include "CustomObject.h"

//---------------------------------------------------------------------------

class MyEllipse : public MyObject
{
public:
   int c_x, c_y;
   MyEllipse();
   MyEllipse(int x, int y, int a, int b);
   void draw();
   void move(int a, int b);
   void turn(int a, int b, float angle, int old[2][100]);
   void scale(int a, int b, float k, int old[2][100]);
   int getX(int i);
   int getY(int i);
   void remake(int x, int y, int a, int b);
};


#endif
