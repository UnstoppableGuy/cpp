//---------------------------------------------------------------------------

#ifndef CustomObjectH
#define CustomObjectH
//---------------------------------------------------------------------------


#include "vcl.h"

class MyObject
{
protected:
   int n;
   TPoint *points;
public:
   MyObject();
   MyObject(int n);
   ~MyObject();
   int round(float value);
};

#endif
