//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "izdavaci.h"
#include "postavkeWR_binarna.h"
#include "CountryInfoService.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    //vanjski SOAP servis za popis drzava
	_di_CountryInfoServiceSoapType drzava = GetCountryInfoServiceSoapType();
	ArrayOftCountryCodeAndName drzave = drzava->ListOfCountryNamesByName();
	for(int i = 0; i < drzave.size(); i++){
		CBDrzava->Items->Add(drzave[i]->sName);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BDodajClick(TObject *Sender)
{
    //otvori izdavaci.bff i spremi zaglavlje
	Izdavaci zaglavlje;
	std::unique_ptr<TFileStream> izdavacStream (new TFileStream("izdavaci.bff", fmOpenReadWrite));
	izdavacStream->Write(&zaglavlje, sizeof(Izdavaci));

	//ako nedostaju podatci prekini izvršavanje koda
	if(ESifra->Text == "" or ENaziv->Text == "" or CBDrzava->Text == ""){
		ShowMessage("Upišite podatke!");
		return;
	}

	//spremi upisane podatke u izdavaci.bff (binarni format) na kraj datoteke
	Izdavac izdavac = Izdavac(ESifra->Text.ToInt() , ENaziv->Text.t_str(), CBDrzava->Text.t_str());
	izdavacStream->Seek(0, soFromEnd);
	izdavacStream->Write(&izdavac, sizeof(Izdavac));

	ShowMessage("Uspješno spremljeno!");
	ESifra->Clear();
	ENaziv->Clear();
	CBDrzava->ItemIndex = -1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BOdustaniClick(TObject *Sender)
{
	ESifra->Clear();
	ENaziv->Clear();
	CBDrzava->ItemIndex = -1;
}
//---------------------------------------------------------------------------
