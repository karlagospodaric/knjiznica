//---------------------------------------------------------------------------

#ifndef pocetnaH
#define pocetnaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <map>
//---------------------------------------------------------------------------
class TFPocetna : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *Uredi;
	TButton *Obrisi;
	TButton *Odjava;
	TGroupBox *GroupBox2;
	TLabel *Label1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label2;
	TLabel *Label3;
	void __fastcall UrediClick(TObject *Sender);
	void __fastcall ObrisiClick(TObject *Sender);
	void __fastcall AutoriClick(TObject *Sender);
	void __fastcall KnjigeClick(TObject *Sender);
	void __fastcall OdjavaClick(TObject *Sender);
	void __fastcall IzdavacClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    UnicodeString ime;
	UnicodeString pass;
	UnicodeString mail;
	std::map<String, std::map<String, String>> prijevod;
	__fastcall TFPocetna(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPocetna *FPocetna;
//---------------------------------------------------------------------------
#endif
