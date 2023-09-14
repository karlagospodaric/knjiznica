//---------------------------------------------------------------------------

#ifndef prijavaH
#define prijavaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <map>
//---------------------------------------------------------------------------
class TFPrijava : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *Postavke;
	TMenuItem *Svjetla;
	TMenuItem *Tamna;
	TMenuItem *Default;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EKime;
	TEdit *ELozinka;
	TButton *Prijava;
	TButton *Odustani;
	TCheckBox *FastLogin;
	TLabel *Label3;
	TButton *Registracija;
	TMenuItem *Jezik;
	TMenuItem *EN;
	TMenuItem *HR;
	void __fastcall SvjetlaClick(TObject *Sender);
	void __fastcall TamnaClick(TObject *Sender);
	void __fastcall DefaultClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PrijavaClick(TObject *Sender);
	void __fastcall RegistracijaClick(TObject *Sender);
	void __fastcall OdustaniClick(TObject *Sender);
	void __fastcall ENClick(TObject *Sender);
	void __fastcall HRClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	UnicodeString j;
    bool uspjeh;
	std::map<String, std::map<String, String>> prijevod;
	__fastcall TFPrijava(TComponent* Owner);

};


//---------------------------------------------------------------------------
extern PACKAGE TFPrijava *FPrijava;
//---------------------------------------------------------------------------
#endif
