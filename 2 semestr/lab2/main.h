// ---------------------------------------------------------------------------

#ifndef mainH
#define mainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TButton *Press;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TButton *Button1;
	TMemo *Mem;
	TButton *Sort;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TLabel *Name;
	TLabel *Surname;
	TLabel *Math;
	TLabel *Physics;
	TLabel *Patronymic;
	TLabel *RussianLanguage;
	TEdit *Edit8;
	TEdit *Edit9;
	TLabel *Specialty;
	TLabel *Certificate;
	TButton *JustDoIt;
	TRadioGroup *WhatToDo;
	TComboBox *ComboBox1;

	void __fastcall PressClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall WhatToDoClick(TObject *Sender);
	void __fastcall JustDoItClick(TObject *Sender);
	void __fastcall SortClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
