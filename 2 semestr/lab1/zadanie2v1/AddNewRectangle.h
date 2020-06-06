//---------------------------------------------------------------------------

#ifndef AddNewRectangleH
#define AddNewRectangleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TAddRect : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAddRect(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddRect *AddRect;
//---------------------------------------------------------------------------
#endif
