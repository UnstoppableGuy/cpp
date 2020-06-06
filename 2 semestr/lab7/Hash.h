//---------------------------------------------------------------------------

#ifndef HashH
#define HashH
#include <stddef.h>
//---------------------------------------------------------------------------
#endif
#include <vcl.h>
#include "Stack.h"

class Hash
{
	public:
	Stack hashstack [20];
	bool IsExist(int key);
	bool AddToHash(int key);
	bool DeleteFromHash(int key);
	void DeleteAll();
};



