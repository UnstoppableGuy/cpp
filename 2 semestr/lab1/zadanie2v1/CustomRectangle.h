//---------------------------------------------------------------------------

#ifndef CustomRectangleH
#define CustomRectangleH
//---------------------------------------------------------------------------


#include "CustomObject.h"

class MyRectangle : public MyObject
{
public:
   int c_x, c_y;
   MyRectangle(int x1, int y1, int x2, int y2);
   MyRectangle();
   ~MyRectangle();
   void draw();
   void move(int a, int b);
   void turn(int a, int b, float angle, int old[2][4]);
   void scale(int a, int b, float dk, int old[2][4]);
   int getX(int i);
   int getY(int i);
   virtual void remake(int x1, int y1, int x2, int y2);
};

#endif
