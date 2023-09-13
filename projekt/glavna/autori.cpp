//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "autori.h"
#include "podatkovniModul.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma link "frxExportRTF"
#pragma link "frxClass"
#pragma resource "*.dfm"
TFAutori *FAutori;
//---------------------------------------------------------------------------
__fastcall TFAutori::TFAutori(TComponent* Owner)
	: TForm(Owner)
{
    //prijevod forme
	prijevod["BReport"] =	{
		{
			{"EN", "Report"},
			{"HR", "Izvještaj"}
		}
	};

}
//---------------------------------------------------------------------------
void __fastcall TFAutori::BReportClick(TObject *Sender)
{
	data->TKnjige->MasterSource = data->DAutori;
	data->TKnjige->IndexFieldNames = "AutorID";
	data->TKnjige->MasterFields = "IDAutora";
	izvjestaj->ShowReport();
	data->TKnjige->MasterSource = NULL;
	data->TKnjige->MasterFields = "";
}
//---------------------------------------------------------------------------




void __fastcall TFAutori::FormClose(TObject *Sender, TCloseAction &Action)
{
	data->TAutori->Refresh();
	data->TKnjige->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TFAutori::FormShow(TObject *Sender)
{
    data->TAutori->Refresh();
	data->TKnjige->Refresh();

}
//---------------------------------------------------------------------------

