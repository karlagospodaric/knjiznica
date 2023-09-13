#pragma hdrstop
#pragma package(smart_init)
#include "postavkeWR_binarna.h"

//konstrukotr za Windows Registry
PostavkeWR::PostavkeWR(){
	registar = new TRegistry;
	kljuc = "Knjiznica";
	registar->RootKey = HKEY_CURRENT_USER;
}

//Spremi postavke za Fast login u Windows Registry
void PostavkeWR::upisi(){
	if (registar->OpenKey(kljuc,true)) {
		if(pohrana == true){
			registar->WriteBool("zapamti", pohrana);
			registar->WriteString("user", korisnickoIme);
			registar->WriteString("pass", lozinka);
			registar->WriteString("jezik", jezik);
		}
	}
	registar->CloseKey();
}

//Ucitaj postavke za Fast login iz Windows Registry
bool PostavkeWR::citaj(){
	if (registar->OpenKey(kljuc,false)) {
		pohrana = registar->ReadBool("zapamti");
		korisnickoIme =registar->ReadString("user");
		lozinka = registar->ReadString("pass");
		jezik = registar->ReadString("jezik");
		return true;
	}
	return false;
	registar->CloseKey();
}

//Briši spremljene postavke iz Windows Registry
void PostavkeWR::brisi(){
	if (registar->KeyExists(kljuc)) {
		registar->DeleteKey(kljuc);
	}
}

//spremi odabrani jezik aplikacije
void PostavkeWR::spremiJezik(UnicodeString odabrano){
	if (registar->OpenKey(kljuc,true)) {
		registar->WriteString("jezik", odabrano);
	}
	registar->CloseKey();
}

//destruktor za Windows Registry
PostavkeWR::~PostavkeWR(){
	delete registar;
}

//konstruktor za zaglavlje binarnog formata
Izdavaci::Izdavaci(){
		wcsncpy(_naziv, L"Izdavači", 10);
		_verzija = 1.0;
}

//konstrukotr za binarni format
Izdavac::Izdavac(int sifra, wchar_t* naziv, wchar_t* drzava){
		_sifra = sifra;
		wcsncpy(_imeTvrtke, naziv, 25);
		wcsncpy(_drzava, drzava, 25);
}