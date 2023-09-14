//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "prijava.h"
#include "postavkeIni.h"
#include "..\biblioteke\postavkeWR_binarna.h"
#include <Vcl.Graphics.hpp>
#include <System.NetEncoding.hpp>
#include <System.StrUtils.hpp>
#include "podatkovniModul.h"
#include "registracija.h"
#include <System.Hash.hpp>
#include "autori.h"
#include "knjige.h"
#include "pocetna.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFPrijava *FPrijava;
//---------------------------------------------------------------------------

//stvori novu instancu klase Korisnici
Korisnici *k = new Korisnici;
PostavkeWR fast;

//---------------------------------------------------------------------------
__fastcall TFPrijava::TFPrijava(TComponent* Owner)
	: TForm(Owner)
{
	//prijevod forme
	prijevod["Label1"] =	{
		{
			{"EN", "Username:"},
			{"HR", "Korisničko ime:"}
		}
	};
	prijevod["Label2"] =	{
		{
			{"EN", "Password:"},
			{"HR", "Lozinka:"}
		}
	};
	prijevod["Label3"] =	{
		{
			{"EN", "Don't have an account?"},
			{"HR", "Nemate korisnički račun?"}
		}
	};
	prijevod["GroupBox1"] =	{
		{
			{"EN", "Login"},
			{"HR", "Prijava"}
		}
	};
	prijevod["FastLogin"] =	{
		{
			{"EN", "Remember me!"},
			{"HR", "Zapamti me!"}
		}
	};
	prijevod["Odustani"] =	{
		{
			{"EN", "Cancel"},
			{"HR", "Odustani"}
		}
	};
	prijevod["Prijava"] =	{
		{
			{"EN", "Login"},
			{"HR", "Prijava"}
		}
	};
	prijevod["Registracija"] =	{
		{
			{"EN", "Registration"},
			{"HR", "Registracija"}
		}
	};
	prijevod["Jezik"] =	{
		{
			{"EN", "Language"},
			{"HR", "Jezik"}
		}
	};
	prijevod["Postavke"] =	{
		{
			{"EN", "Settings"},
			{"HR", "Postavke"}
		}
	};
	prijevod["Svjetla"] =	{
		{
			{"EN", "Light theme"},
			{"HR", "Svjetla tema"}
		}
	};
	prijevod["Tamna"] =	{
		{
			{"EN", "Dark theme"},
			{"HR", "Tamna tema"}
		}
	};
	prijevod["Default"] =	{
		{
			{"EN", "Default settings"},
			{"HR", "Postavke sustava"}
		}
	};



	//ucitaj trenutne postavke (INI)
	PostavkeINI postavke;
	postavke.UcitajPostavke("TRENUTNE POSTAVKE");
	//promjena pozadine forme
	Color = StringToColor(postavke.pozadina);
	//promjena fonta na cijeloj formi
	Font->Name = postavke.font;
	Font->Color = StringToColor(postavke.bojaFonta);
	Font->Height = postavke.velicinaFonta;
	//promjena pozadine editboxova
	EKime->Color = StringToColor(postavke.pozadina);
	ELozinka->Color = StringToColor(postavke.pozadina);
	//promjena fonta naslova groupboxa
	GroupBox1->HeaderFont->Name = postavke.font;
	GroupBox1->HeaderFont->Color = StringToColor(postavke.bojaFonta);
	GroupBox1->HeaderFont->Height = postavke.velicinaFonta;
	//promjena fonta buttona
	Prijava->Font->Name = postavke.font;
	Prijava->Font->Color = StringToColor(postavke.bojaFonta);
	Prijava->Font->Height = postavke.velicinaFonta;
	Registracija->Font->Name = postavke.font;
	Registracija->Font->Color = StringToColor(postavke.bojaFonta);
	Registracija->Font->Height = postavke.velicinaFonta;
	Odustani->Font->Name = postavke.font;
	Odustani->Font->Color = StringToColor(postavke.bojaFonta);
	Odustani->Font->Height = postavke.velicinaFonta;

	//ucitaj ako ima spremljene podatke za fast login u Windows registru
	uspjeh = fast.citaj();
	if(uspjeh == true){
		EKime->Text = fast.korisnickoIme;
		ELozinka->Text = fast.lozinka;
		j = fast.jezik;
	}

}
//---------------------------------------------------------------------------

void __fastcall TFPrijava::SvjetlaClick(TObject *Sender)
{
	//ucitaj svjetlu temu (INI)
	PostavkeINI postavke;
	postavke.UcitajPostavke("SVJETLA");
	//promjena pozadine forme
	Color = StringToColor(postavke.pozadina);
	//promjena fonta na cijeloj formi
	Font->Name = postavke.font;
	Font->Color = StringToColor(postavke.bojaFonta);
	Font->Height = postavke.velicinaFonta;
	//promjena pozadine editboxova
	EKime->Color = StringToColor(postavke.pozadina);
	ELozinka->Color = StringToColor(postavke.pozadina);
	//promjena fonta naslova groupboxa
	GroupBox1->HeaderFont->Name = postavke.font;
	GroupBox1->HeaderFont->Color = StringToColor(postavke.bojaFonta);
	GroupBox1->HeaderFont->Height = postavke.velicinaFonta;
	//promjena fonta buttona
	Prijava->Font->Name = postavke.font;
	Prijava->Font->Color = StringToColor(postavke.bojaFonta);
	Prijava->Font->Height = postavke.velicinaFonta;
	Registracija->Font->Name = postavke.font;
	Registracija->Font->Color = StringToColor(postavke.bojaFonta);
	Registracija->Font->Height = postavke.velicinaFonta;
	Odustani->Font->Name = postavke.font;
	Odustani->Font->Color = StringToColor(postavke.bojaFonta);
	Odustani->Font->Height = postavke.velicinaFonta;
}
//---------------------------------------------------------------------------

void __fastcall TFPrijava::TamnaClick(TObject *Sender)
{
	//ucitaj tamnu temu (INI)
	PostavkeINI postavke;
	postavke.UcitajPostavke("TAMNA");
	//promjena pozadine forme
	Color = StringToColor(postavke.pozadina);
	//promjena fonta na cijeloj formi
	Font->Name = postavke.font;
	Font->Color = StringToColor(postavke.bojaFonta);
	Font->Height = postavke.velicinaFonta;
	//promjena pozadine editboxova
	EKime->Color = StringToColor(postavke.pozadina);
	ELozinka->Color = StringToColor(postavke.pozadina);
	//promjena fonta naslova groupboxa
    GroupBox1->HeaderFont->Name = postavke.font;
	GroupBox1->HeaderFont->Color = StringToColor(postavke.bojaFonta);
	GroupBox1->HeaderFont->Height = postavke.velicinaFonta;
	//promjena fonta buttona
	Prijava->Font->Name = postavke.font;
	Prijava->Font->Color = StringToColor(postavke.bojaFonta);
	Prijava->Font->Height = postavke.velicinaFonta;
	Registracija->Font->Name = postavke.font;
	Registracija->Font->Color = StringToColor(postavke.bojaFonta);
	Registracija->Font->Height = postavke.velicinaFonta;
	Odustani->Font->Name = postavke.font;
	Odustani->Font->Color = StringToColor(postavke.bojaFonta);
	Odustani->Font->Height = postavke.velicinaFonta;
}
//---------------------------------------------------------------------------

void __fastcall TFPrijava::DefaultClick(TObject *Sender)
{
	//ucitaj postavke sustava (INI)
	PostavkeINI postavke;
	postavke.UcitajPostavke("DEFAULT");
	//promjena pozadine forme
	Color = StringToColor(postavke.pozadina);
	//promjena fonta na cijeloj formi
	Font->Name = postavke.font;
	Font->Color = StringToColor(postavke.bojaFonta);
	Font->Height = postavke.velicinaFonta;
	//promjena pozadine editboxova
	EKime->Color = StringToColor(postavke.pozadina);
	ELozinka->Color = StringToColor(postavke.pozadina);
	//promjena fonta naslova groupboxa
    GroupBox1->HeaderFont->Name = postavke.font;
	GroupBox1->HeaderFont->Color = StringToColor(postavke.bojaFonta);
	GroupBox1->HeaderFont->Height = postavke.velicinaFonta;
	//promjena fonta buttona
	Prijava->Font->Name = postavke.font;
	Prijava->Font->Color = StringToColor(postavke.bojaFonta);
	Prijava->Font->Height = postavke.velicinaFonta;
	Registracija->Font->Name = postavke.font;
	Registracija->Font->Color = StringToColor(postavke.bojaFonta);
	Registracija->Font->Height = postavke.velicinaFonta;
	Odustani->Font->Name = postavke.font;
	Odustani->Font->Color = StringToColor(postavke.bojaFonta);
	Odustani->Font->Height = postavke.velicinaFonta;
}
//---------------------------------------------------------------------------

void __fastcall TFPrijava::FormClose(TObject *Sender, TCloseAction &Action)
{
	//spremi primjenjene postavke u trenutne postavke (INI)
	PostavkeINI postavke;
	postavke.pozadina = Color;
	postavke.font = Font->Name;
	postavke.bojaFonta = Font->Color;
	postavke.velicinaFonta = Font->Height;
	postavke.SpremiTrenutne();
	//fast.~PostavkeWR(); //pozovi destruktor za WR
	delete k;  //obriši insatancu klase Korisnici

}
//---------------------------------------------------------------------------
void __fastcall TFPrijava::PrijavaClick(TObject *Sender)
{
	//ako nisu upisani podatci ne izvodi dalje program
	if(EKime->Text == "" or ELozinka->Text == ""){
		ShowMessage("Unesite podatke za prijavu!");
		return;
	}

	bool login;

	if (uspjeh == false) {
        FHash lozinka;
		lozinka.MD5Hash(EKime->Text); //hashiraj korisničko ime (promjenjiva sol)
		lozinka.SHA2Hash(lozinka.sol + ELozinka->Text); //hashiraj sol+lozinku
		//pozovi metodu Prijava s hashiranom lozinkom i vrati odgovor u login
		login = k->Prijava(EKime->Text, lozinka.hash);
	}else{
		//pozovi metodu Prijava s upisanim podatcima i vrati odgovor u login
		login = k->Prijava(EKime->Text, ELozinka->Text);
	}

	//provjeri je li login bio uspješan, ako nije - return
	if(login == false){
        ShowMessage("Korisničko ime ili lozinka su neispravni!");
		ELozinka->Text = "";
		return;
	}

	ShowMessage("Uspješna prijava!");

	//spremi podatke korisnika u varijable (definirane u pocetna.h)
	FPocetna->ime = k->kime;
	FPocetna->pass = k->password;
	FPocetna->mail = k->email;

	fast.pohrana = FastLogin->Checked;
	fast.korisnickoIme = FPocetna->ime;
	fast.lozinka = FPocetna->pass;

	//provjeri je li označen checkbox i ako je spremi podatke za fast login
	if(FastLogin->Checked == true){
		fast.upisi();
	}else{  //ako nije označen obrisi podatke
		fast.pohrana = false;;
		fast.korisnickoIme = "";
		fast.lozinka = "";
	}

	Visible = false;
	FPocetna->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFPrijava::RegistracijaClick(TObject *Sender)
{
	Visible = false;
	FRegistracija->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFPrijava::OdustaniClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFPrijava::ENClick(TObject *Sender)
{
	fast.jezik = "EN";
	fast.spremiJezik("EN");
	data->prijevodApk(this, fast.jezik, prijevod);
	data->prijevodApk(FAutori, fast.jezik, FAutori->prijevod);
	data->prijevodApk(FKnjige, fast.jezik, FKnjige->prijevod);
	data->prijevodApk(FPocetna, fast.jezik, FPocetna->prijevod);
	data->prijevodApk(FRegistracija, fast.jezik, FRegistracija->prijevod);
}
//---------------------------------------------------------------------------

void __fastcall TFPrijava::HRClick(TObject *Sender)
{
	fast.jezik = "HR";
	fast.spremiJezik("HR");
	data->prijevodApk(this, fast.jezik, prijevod);
	data->prijevodApk(FAutori, fast.jezik, FAutori->prijevod);
	data->prijevodApk(FKnjige, fast.jezik, FKnjige->prijevod);
	data->prijevodApk(FPocetna, fast.jezik, FPocetna->prijevod);
	data->prijevodApk(FRegistracija, fast.jezik, FRegistracija->prijevod);
}
//---------------------------------------------------------------------------

void __fastcall TFPrijava::FormShow(TObject *Sender)
{
    data->prijevodApk(this, j, prijevod);
	data->prijevodApk(FAutori, j, FAutori->prijevod);
	data->prijevodApk(FKnjige, j, FKnjige->prijevod);
	data->prijevodApk(FPocetna, j, FPocetna->prijevod);
	data->prijevodApk(FRegistracija, j, FRegistracija->prijevod);
}
//---------------------------------------------------------------------------

