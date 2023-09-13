//---------------------------------------------------------------------------

#ifndef autoriH
#define autoriH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportBaseDialog.hpp"
#include "frxExportPDF.hpp"
#include "frxExportRTF.hpp"
#include "frxClass.hpp"
#include <map>
//---------------------------------------------------------------------------
class TFAutori : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBAutori;
	TDBNavigator *DBNavigator1;
	TButton *BReport;
	TfrxReport *izvjestaj;
	TfrxDBDataset *frxAutori;
	TfrxDBDataset *frxKnjige;
	TfrxPDFExport *frxPDF;
	TfrxRTFExport *frxRTF;
	void __fastcall BReportClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	std::map<String, std::map<String, String>> prijevod;
	__fastcall TFAutori(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAutori *FAutori;
//---------------------------------------------------------------------------
#endif
