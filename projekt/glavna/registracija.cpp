//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "registracija.h"
#include "podatkovniModul.h"
#include "pocetna.h"
#include "prijava.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFRegistracija *FRegistracija;
//---------------------------------------------------------------------------

__fastcall TFRegistracija::TFRegistracija(TComponent* Owner)
	: TForm(Owner)
{
	//prijevod forme
	prijevod["Label1"] =	{
		{
			{"EN", "Email:"},
			{"HR", "Email:"}
		}
	};
	prijevod["Label2"] =	{
		{
			{"EN", "Username:"},
			{"HR", "Korisničko ime:"}
		}
	};
	prijevod["Label3"] =	{
		{
			{"EN", "Password:"},
			{"HR", "Lozinka:"}
		}
	};
	prijevod["GroupBox1"] =	{
		{
			{"EN", "Data"},
			{"HR", "Podatci"}
		}
	};
	prijevod["BOdustani"] =	{
		{
			{"EN", "Cancel"},
			{"HR", "Odustani"}
		}
	};
	prijevod["BRegistracija"] =	{
		{
			{"EN", "Registration"},
			{"HR", "Registracija"}
		}
	};
}
//---------------------------------------------------------------------------
void __fastcall TFRegistracija::BRegistracijaClick(TObject *Sender)
{
	//ne izvodi program ako nedostaju podatci za registraciju
	if(Ekime->Text == "" or Elozinka->Text == "" or Eemail->Text == ""){
		ShowMessage("Unesite podatke za registraciju!");
		return;
	}

	Korisnici user;
	bool reg, uredivanje;

	//ako je caption forme "Spremi" pozovi metodu Uredi
	if(FRegistracija->Caption == "Uredi"){
		uredivanje = user.Uredi(Eemail->Text, Ekime->Text, Elozinka->Text);
		if(uredivanje == false){
			ShowMessage("Promjene nisu pohranjene.");
			return;
		}else{
			ShowMessage("Promjene su pohranjene");
			Close();
			FPocetna->Visible = true;
			return;
		}
	}
	//pozovi metodu Registracija i odgovor spremi u reg
	reg = user.Registracija(Eemail->Text, Ekime->Text, Elozinka->Text);

	if(reg == false){
		ShowMessage("Upišite ispravnu mail adresu. Minimalna duljina lozinke je 8 znakova.");
		return;
	}
	FPocetna->ime = Ekime->Text;;
	FPocetna->pass = Elozinka->Text;
	FPocetna->mail = Eemail->Text;
	ShowMessage("Uspješno ste se registrirali!");
	Close();
	FPocetna->Visible = true;


}
//---------------------------------------------------------------------------
void __fastcall TFRegistracija::BOdustaniClick(TObject *Sender)
{
	Visible = false;;
	if(FRegistracija->Caption == "Uredi"){
		FPocetna->Visible = true;
	}else{
        FPrijava->Visible = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFRegistracija::FormClose(TObject *Sender, TCloseAction &Action)
{
	FPrijava->Close();
}
//---------------------------------------------------------------------------

