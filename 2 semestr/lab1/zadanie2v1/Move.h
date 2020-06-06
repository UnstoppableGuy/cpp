//---------------------------------------------------------------------------

#ifndef MoveH
#define MoveH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMoveForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button1;
	TTimer *Timer1;
	TTimer *Timer2;
	TTimer *Timer3;
	TTimer *Timer4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMoveForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMoveForm *MoveForm;
//---------------------------------------------------------------------------
#endif
