//---------------------------------------------------------------------------
#include <vcl.h>
#include "Record.h"
#ifndef ListH
#define ListH
//---------------------------------------------------------------------------
#endif

class RecordList
{
	private:
	Record* head = nullptr;
	Record* tail = nullptr;
	public:
	void Add(Record* item);
	void Add(Record* new_item, int index);
	void Remove();
    void Remove(Record* item);
	void Print(TMemo* m);
	Record* Search1(int number);
	Record* Search2(AnsiString FIO);
	Record* Search3(AnsiString data);
	~RecordList();
};