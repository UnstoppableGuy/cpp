//---------------------------------------------------------------------------

#ifndef CustomSquareH
#define CustomSquareH
//---------------------------------------------------------------------------

#include "CustomRectangle.h"

class MySquare : public MyRectangle
{
public:
   MySquare(int x, int y, int a);
   void remake(int x, int y, int a);
};

#endif
