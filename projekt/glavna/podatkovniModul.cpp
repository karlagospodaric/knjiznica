//---------------------------------------------------------------------------


#pragma hdrstop
#include <vcl.h>
#include <SysUtils.hpp>
#include "podatkovniModul.h"
#include <System.NetEncoding.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
Tdata *data;
//---------------------------------------------------------------------------
void Tdata::prijevodApk(TForm* Form, String jezik, const std::map<String, std::map<String, String>>& prijevod){
	for(int i = 0; i < Form->ComponentCount; i++) // iterate though all components on the form
		for(auto it_ComponentName = prijevod.begin(); it_ComponentName != prijevod.end(); it_ComponentName++)
			if(Form->Components[i]->Name == it_ComponentName->first) // find component by name
				for(auto it_Language = it_ComponentName->second.begin(); it_Language != it_ComponentName->second.end(); it_Language++)
					if(it_Language->first == jezik) // find translation for the target language
						if(IsPublishedProp(Form->Components[i], "Caption"))
							SetPropValue(Form->Components[i], "Caption", it_Language->second);
}

//metoda za hash lozinki (MD5)
void FHash::MD5Hash(UnicodeString text){
	sol = md5hash->GetHashString(text);
}

//metoda za hash lozinki (SHA256)
void FHash::SHA2Hash(UnicodeString tekst){;
	hash = sha2hash->GetHashString(tekst, THashSHA2::TSHA2Version::SHA256);
}

//metoda za čitanje podataka iz baze - tablica Korisnici
bool Korisnici::Prijava(UnicodeString ime, UnicodeString pass){
	TLocateOptions opcije;
	opcije.Clear();
	opcije << loCaseInsensitive;

	//provjeri postoji li korisnik u bazi
	if(data->TKorisnici->Locate("korisnickoIme", ime, opcije) == false){
		return false;
	}

	//provjeri je li lozinka točna
	if(data->TKorisnici->FieldByName("lozinka")->AsString == pass){
		kime = ime;
		password = pass;
		email = data->TKorisnici->FieldByName("email")->AsString;
		return true;
	}else{
		return false;
	}

}

//metoda za unos novih korisnika u bazu
bool Korisnici::Registracija(UnicodeString mail, UnicodeString ime, UnicodeString pass){
	FHash lozinka;
	_di_IValidator provjera = GetIValidator(); //instanca vlastitog soap servisa za provjeru logina

	//ako je upisan ispravan format maila i lozinka duža od 8 znakova
	if(provjera->passValid(pass) and provjera->emailValid(mail)){
		lozinka.MD5Hash(ime); //hashiraj korisničko ime (promjenjiva sol)
		lozinka.SHA2Hash(lozinka.sol + pass); //hashiraj sol+lozinku
		data->TKorisnici->Append();
		data->TKorisnici->FieldByName("korisnickoIme")->AsString = ime;
		data->TKorisnici->FieldByName("lozinka")->AsString = lozinka.hash; //upisi hashiranu lozinku u bazu
		data->TKorisnici->FieldByName("email")->AsString = mail;
		data->TKorisnici->Post();
		return true;
	}else{
		return false;
	}

}

//metoda za uređivanje korisničkog profila (Tablica Korisnici)
bool Korisnici::Uredi(UnicodeString mail, UnicodeString ime, UnicodeString pass){
	FHash l;
	_di_IValidator provjera = GetIValidator(); //instanca vlastitog soap servisa za provjeru logina

	//ako je upisan ispravan format maila i lozinka duža od 8 znakova
	if(provjera->passValid(pass) and provjera->emailValid(mail)){
		l.MD5Hash(ime); //hashiraj korisničko ime (promjenjiva sol)
		l.SHA2Hash(l.sol + pass); //hashiraj sol+lozinku
		data->TKorisnici->Edit();
		data->TKorisnici->FieldByName("lozinka")->AsString = l.hash; //upisi hashiranu lozinku u bazu
		data->TKorisnici->FieldByName("email")->AsString = mail;
		data->TKorisnici->Post();
		return true;
	}else{
		return false;
	}
}

//metoda za brisanje korisnika iz tablice Korisnici
bool Korisnici::Obrisi(UnicodeString ime){
    TLocateOptions opcije;
	opcije.Clear();
	opcije << loCaseInsensitive;

	//provjeri postoji li korisnik u bazi
	if(data->TKorisnici->Locate("korisnickoIme", ime, opcije) == true){
		//izbriši ga iz tablice
    	data->TKorisnici->Delete();
		return true;
	}else{
		return false;
	}


}

//metoda za pronalaženje ID-a autora
int Autori::pronadi(UnicodeString imePrezime){
	TLocateOptions opcije;
	opcije.Clear();
	opcije << loCaseInsensitive;

	//pozicija razmaka između imena i prezimena, duljina teksta
	int razmak = imePrezime.Pos(" ");
	int duljina = imePrezime.Length();

	//prezime je druga riječ (od razmaka do kraja teksta) i makni višak razmaka
	prezime = imePrezime.SubString(razmak, duljina).Trim();
	if(data->TAutori->Locate("prezimeAutora", prezime, opcije) == true){
		id = data->TAutori->FieldByName("IDAutora")->AsInteger;
		return id;
	}else{
		return 0;
	}
}

//metoda za dodavanje nove knjige u tablicu Knjige
bool Knjige::Dodaj(UnicodeString naslov, int autorID, int godina, UnicodeString izdavac, TMemoryStream* slika){
	if(naslov != "" and autorID != 0 and godina != 0 and izdavac != ""){
		data->TKnjige->Append();
		data->TKnjige->FieldByName("naslov")->AsString = naslov;
		data->TKnjige->FieldByName("autorID")->AsInteger = autorID;
		data->TKnjige->FieldByName("dostupnost")->AsBoolean = true;
		data->TKnjige->FieldByName("godinaIzdanja")->AsInteger = godina;
		data->TKnjige->FieldByName("izdavac")->AsString = izdavac;
		static_cast<TBlobField*>(data->TKnjige->FieldByName("logo"))->LoadFromStream(slika);
		data->TKnjige->Post();
		return true;
	}else{
		return false;
	}
}

//metoda za uređivanje knjige u tablici Knjige
bool Knjige::Uredi(UnicodeString naslov, int autorID, int godina, UnicodeString izdavac, TMemoryStream* slika){
	if(naslov != "" and autorID != 0 and godina != 0 and izdavac != ""){
		data->TKnjige->Edit();
		data->TKnjige->FieldByName("naslov")->AsString = naslov;
		data->TKnjige->FieldByName("autorID")->AsInteger = autorID;
		data->TKnjige->FieldByName("dostupnost")->AsBoolean = true;
		data->TKnjige->FieldByName("godinaIzdanja")->AsInteger = godina;
		data->TKnjige->FieldByName("izdavac")->AsString = izdavac;
		static_cast<TBlobField*>(data->TKnjige->FieldByName("logo"))->LoadFromStream(slika);
		data->TKnjige->Post();
		return true;
	}else{
		return false;
	}
}

//metoda za brisanje knjige iz tablice Knjige
bool Knjige::Obrisi(UnicodeString naslov){
	TLocateOptions opcije;
	opcije.Clear();
	opcije << loCaseInsensitive;

	if(data->TKnjige->Locate("naslov", naslov, opcije)){
		data->TKnjige->Delete();
		return true;
	}else{
		return false;
	}
}

//metoda za posuđivanje knjige
bool Knjige::posudenaKnjiga(UnicodeString naslov){
	TLocateOptions opcije;
	opcije.Clear();
	opcije << loCaseInsensitive;

	if(data->TKnjige->Locate("naslov", naslov, opcije) == true){
		data->TKnjige->Edit();
		data->TKnjige->FieldByName("dostupnost")->AsBoolean = false;
		data->TKnjige->Post();
	}else{
		return false;
	}
	return true;
}

//metoda za vraćanje knjige
bool Knjige::vratiKnjigu(UnicodeString naslov){
	TLocateOptions opcije;
	opcije.Clear();
	opcije << loCaseInsensitive;

	if(data->TKnjige->Locate("naslov", naslov, opcije) == true){
		data->TKnjige->Edit();
		data->TKnjige->FieldByName("dostupnost")->AsBoolean = true;
		data->TKnjige->Post();
	}else{
		return false;
	}
	return true;
}

//---------------------------------------------------------------------------
__fastcall Tdata::Tdata(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tdata::TKnjigeCalcFields(TDataSet *DataSet)
{
	int godina = TKnjige->FieldByName("godinaIzdanja")->AsInteger;
	TDateTime currentDate = Date(); // trenutni datum
	unsigned short year, month, day; // varijable za godinu, mjesec i dan

	DecodeDate(currentDate, year, month, day); //razlomi datum na godinu , mjesec i dan
	//izračunaj starost knjige oduzimajući godinu izdanja od trenutne godine
	TKnjige->FieldByName("starostKnjige")->AsInteger = year - godina;
}
//---------------------------------------------------------------------------



