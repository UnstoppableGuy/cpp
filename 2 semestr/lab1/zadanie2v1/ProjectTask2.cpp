//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Move.cpp", MoveForm);
USEFORM("Scale.cpp", ScaleForm);
USEFORM("Turn.cpp", TurnForm);
USEFORM("Task2.cpp", MainForm);
USEFORM("AddNewSquare.cpp", AddSq);
USEFORM("AddNewRectangle.cpp", AddRect);
USEFORM("AddNewEllipse.cpp", AddEll);
USEFORM("CreateShape.cpp", Create);
USEFORM("AddNewCircle.cpp", Form1);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TCreate), &Create);
		Application->CreateForm(__classid(TAddRect), &AddRect);
		Application->CreateForm(__classid(TMoveForm), &MoveForm);
		Application->CreateForm(__classid(TTurnForm), &TurnForm);
		Application->CreateForm(__classid(TScaleForm), &ScaleForm);
		Application->CreateForm(__classid(TAddSq), &AddSq);
		Application->CreateForm(__classid(TAddEll), &AddEll);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
