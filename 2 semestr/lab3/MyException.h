//---------------------------------------------------------------------------

#ifndef MyExceptionH
#define MyExceptionH
//---------------------------------------------------------------------------
#endif

class MyException : public Exception
{
	private:
	AnsiString message;
	public:
	MyException(AnsiString str): Exception(str)
	{
		message = str;
	}
	AnsiString Get_Message()
	{
		return message;
	}
};