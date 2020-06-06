//---------------------------------------------------------------------------
#include "Quene.h"
#ifndef DoubleListH
#define DoubleListH
#include "forDouble.h"
//---------------------------------------------------------------------------
#endif
class Doublelist : public  Queue
{
public:
	void newShow();
	~Doublelist();
	void list_remove();
protected:

	bool resolution(Node* x, int value);

	Node* list_delete(Node* pos);
};
