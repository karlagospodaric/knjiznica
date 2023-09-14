//---------------------------------------------------------------------------

#ifndef registracijaH
#define registracijaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <map>
//---------------------------------------------------------------------------
class TFRegistracija : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Eemail;
	TEdit *Ekime;
	TEdit *Elozinka;
	TButton *BRegistracija;
	TButton *BOdustani;
	void __fastcall BRegistracijaClick(TObject *Sender);
	void __fastcall BOdustaniClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	std::map<String, std::map<String, String>> prijevod;
	__fastcall TFRegistracija(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFRegistracija *FRegistracija;
//---------------------------------------------------------------------------
#endif
