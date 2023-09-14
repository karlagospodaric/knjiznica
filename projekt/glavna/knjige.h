//---------------------------------------------------------------------------

#ifndef knjigeH
#define knjigeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <map>
//---------------------------------------------------------------------------
class TFKnjige : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TGroupBox *GroupBox2;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *ENaslov;
	TButton *BDodaj;
	TButton *BOdustani;
	TLabel *Label1;
	TEdit *EGodina;
	TLabel *Label2;
	TComboBox *CBIzdavaci;
	TComboBox *CBAutori;
	TButton *BUredi;
	TButton *BObrisi;
	TButton *BPosudi;
	TButton *BFilter;
	TButton *BVrati;
	TDBImage *slika;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TLabel *Label8;
	TLabel *Label9;
	void __fastcall BDodajClick(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall BUrediClick(TObject *Sender);
	void __fastcall BObrisiClick(TObject *Sender);
	void __fastcall BOdustaniClick(TObject *Sender);
	void __fastcall BPosudiClick(TObject *Sender);
	void __fastcall BVratiClick(TObject *Sender);
	void __fastcall BFilterClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	std::map<String, std::map<String, String>> prijevod;
	TMemoryStream* pic;  //za spremanje odabrane slike izdavaca
	__fastcall TFKnjige(TComponent* Owner);


};
//---------------------------------------------------------------------------
extern PACKAGE TFKnjige *FKnjige;
//---------------------------------------------------------------------------
#endif
