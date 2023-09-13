//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pocetna.h"
#include "podatkovniModul.h"
#include "autori.h"
#include "knjige.h"
#include "registracija.h"
#include "prijava.h"
#include "..\biblioteke\izdavaci.h"
#include "..\biblioteke\postavkeWR_binarna.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFPocetna *FPocetna;
//---------------------------------------------------------------------------
__fastcall TFPocetna::TFPocetna(TComponent* Owner)
	: TForm(Owner)
{
    //prijevod forme
	prijevod["Label1"] =	{
		{
			{"EN", "List of authors:"},
			{"HR", "Popis autora:"}
		}
	};
	prijevod["Label2"] =	{
		{
			{"EN", "Books & more:"},
			{"HR", "Sve o knjigama:"}
		}
	};
	prijevod["Label3"] =	{
		{
			{"EN", "Add publisher:"},
			{"HR", "Dodajte izdavača:"}
		}
	};
    prijevod["GroupBox1"] =	{
		{
			{"EN", "User account"},
			{"HR", "Korisnički račun"}
		}
	};
	prijevod["GroupBox2"] =	{
		{
			{"EN", "Library"},
			{"HR", "Knjižnica"}
		}
	};
	prijevod["Obrisi"] =	{
		{
			{"EN", "Delete account"},
			{"HR", "Obriši profil"}
		}
	};
	prijevod["Odjava"] =	{
		{
			{"EN", "Logout"},
			{"HR", "Odjava"}
		}
	};
	prijevod["Uredi"] =	{
		{
			{"EN", "Edit account"},
			{"HR", "Uredi profil"}
		}
	};
	prijevod["Button1"] =	{
		{
			{"EN", "Authors"},
			{"HR", "Autori"}
		}
	};
	prijevod["Button2"] =	{
		{
			{"EN", "Books"},
			{"HR", "Knjige"}
		}
	};
	prijevod["Button3"] =	{
		{
			{"EN", "Publishers"},
			{"HR", "Izdavači"}
		}
	};
}

//---------------------------------------------------------------------------
void __fastcall TFPocetna::UrediClick(TObject *Sender)
{
    Visible = false;
	FRegistracija->Caption = "Uredi";  //promjeni naziv forme iz Registracija u Uredi
	//upiši podatke iz varijabli korisnika (k) u edit boxove na formi Registracija
	FRegistracija->Eemail->Text = FPocetna->mail;
	FRegistracija->Ekime->Text = FPocetna->ime;
	FRegistracija->Elozinka->Clear();
	//korisničko ime se ne može mijenjati
	FRegistracija->Ekime->Enabled = false;
	FRegistracija->ShowModal();         //prikaži formu Registracija
}
//---------------------------------------------------------------------------
void __fastcall TFPocetna::ObrisiClick(TObject *Sender)
{
	Korisnici k;
	bool uspjeh;
	PostavkeWR login;
	uspjeh = k.Obrisi(FPocetna->ime);  //pozovi metodu za brisanje korisnika
	if (uspjeh == true) {
		login.brisi();
		FPrijava->EKime->Clear();
		FPrijava->ELozinka->Clear();
		FPocetna->ime = "";
		FPocetna->pass = "";
		FPocetna->mail = "";
		ShowMessage("Korisnik je uspješno obrisan!");
	}else{
		ShowMessage("Greška!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFPocetna::AutoriClick(TObject *Sender)
{
    FAutori->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFPocetna::KnjigeClick(TObject *Sender)
{
	FKnjige->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFPocetna::OdjavaClick(TObject *Sender)
{
    PostavkeWR fast;
	if(FPrijava->FastLogin->Checked == false){
		fast.brisi();
        FPocetna->ime = "";
		FPocetna->pass = "";
		FPocetna->mail = "";
		FPrijava->EKime->Clear();
		FPrijava->ELozinka->Clear();
	}
	Visible = false;
	FPrijava->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TFPocetna::IzdavacClick(TObject *Sender)
{
    //pokretanje dijaloga izdavac koji je smješten u dll biblioteci
	TForm1* dll = new TForm1(this);
    dll->ShowModal();
	delete(dll);
}
//---------------------------------------------------------------------------

void __fastcall TFPocetna::FormClose(TObject *Sender, TCloseAction &Action)
{
	FPrijava->Close();
}
//---------------------------------------------------------------------------


