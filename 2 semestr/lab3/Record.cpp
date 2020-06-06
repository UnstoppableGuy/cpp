//---------------------------------------------------------------------------

#pragma hdrstop

#include "Record.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Record::Record(int a, AnsiString b, AnsiString c, AnsiString d)
	{
		Set_Number(a);
		FIO = b;
		Adress = c;
		Data = d;
	}
void Record:: Set_Number(int x)
	{
		if(x > 0)
			Serialnumber = x;
		else
			Set_Number(x);
	}
int Record::Get_Number()
	{
		return Serialnumber;
	}

AnsiString Record::Get_Fio()
	{
		return FIO;
	}

AnsiString Record::Get_Adress()
	{
		return Adress;
	}

AnsiString Record:: Get_Date()
	{
		return Data;
	}

