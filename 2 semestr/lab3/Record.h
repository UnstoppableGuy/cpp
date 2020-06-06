//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef RecordH
#define RecordH
//---------------------------------------------------------------------------
#endif

class Record
{
	private:
	int Serialnumber;
	AnsiString FIO;
	AnsiString Adress;
	AnsiString Data;

	public:
	Record* next;
	Record(int a, AnsiString b, AnsiString c, AnsiString d);
	void Set_Number(int x);
	int Get_Number();
	AnsiString Get_Fio();
	AnsiString Get_Adress();
	AnsiString Get_Date();

};
