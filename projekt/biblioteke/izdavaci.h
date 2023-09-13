//---------------------------------------------------------------------------

#ifndef izdavaciH
#define izdavaciH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------

#ifdef EXPORTS  // definirati u DLL projektu
  #define DLL_EXPORT __declspec(dllexport) // U DLL-u
#else
  #define DLL_EXPORT __declspec(dllimport) // U aplikaciji koja koristi DLL
#endif

class DLL_EXPORT TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *ESifra;
	TEdit *ENaziv;
	TButton *BDodaj;
	TButton *BOdustani;
	TComboBox *CBDrzava;
	void __fastcall BDodajClick(TObject *Sender);
	void __fastcall BOdustaniClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
