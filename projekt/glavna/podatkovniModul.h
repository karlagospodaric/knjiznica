//---------------------------------------------------------------------------

#ifndef podatkovniModulH
#define podatkovniModulH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <System.Hash.hpp>
#include "IValidator.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <System.Classes.hpp>
#include <map>

//---------------------------------------------------------------------------
class Tdata : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *Veza;
	TDataSource *DAutori;
	TDataSource *DKnjige;
	TDataSource *DKorisnici;
	TADOTable *TAutori;
	TADOTable *TKnjige;
	TADOTable *TKorisnici;
	TAutoIncField *TAutoriIDAutora;
	TWideStringField *TAutoriimeAutora;
	TWideStringField *TAutoriprezimeAutora;
	TDateTimeField *TAutoridatumRodjenja;
	TAutoIncField *TKnjigeIDKnjiga;
	TStringField *TKnjigenaslov;
	TIntegerField *TKnjigeautorID;
	TBooleanField *TKnjigedostupnost;
	TIntegerField *TKnjigegodinaIzdanja;
	TStringField *TKnjigeizdavac;
	TBlobField *TKnjigelogo;
	TStringField *TKnjigeprezimeAutora;
	TIntegerField *TKnjigestarostKnjige;
	void __fastcall TKnjigeCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
	void prijevodApk(TForm* Form, String jezik, const std::map<String, std::map<String, String>>& prijevod);
	__fastcall Tdata(TComponent* Owner);
};

//klasa za Hash lozinke
class FHash{
public:
	//properties
	THashSHA2 *sha2hash = new THashSHA2;
	THashMD5 *md5hash = new THashMD5;
	UnicodeString sol;
	UnicodeString hash;

	//methods
	virtual void MD5Hash(UnicodeString text);  //za promjenjivu sol
	virtual void SHA2Hash(UnicodeString tekst); //za konacni rezultat hashiranja
};

//klasa za rad s bazom podataka (tablica Korisnici)
class Korisnici {
public:
	//properties
	UnicodeString kime;
	UnicodeString password;
	UnicodeString email;

	//metode
	virtual bool Prijava(UnicodeString ime, UnicodeString pass);
	virtual bool Registracija(UnicodeString mail, UnicodeString ime, UnicodeString pass);
	virtual bool Uredi(UnicodeString mail, UnicodeString ime, UnicodeString pass);
	virtual bool Obrisi(UnicodeString ime);

};

//klasa za rad s bazom podataka (tablica Autori)
class Autori{
public:
	//properties
	UnicodeString prezime;
	int id;

	//metode
	virtual int pronadi(UnicodeString imePrezime);
};

//klasa za rad s bazom podataka (tablica Knjige)
class Knjige{
public:

	//metode
	virtual bool Dodaj(UnicodeString naslov, int autorID, int godina, UnicodeString izdavac, TMemoryStream* slika);
	virtual bool Uredi(UnicodeString naslov, int autorID, int godina, UnicodeString izdavac, TMemoryStream* slika);
	virtual bool Obrisi(UnicodeString naslov);
	virtual bool posudenaKnjiga(UnicodeString naslov);
	virtual bool vratiKnjigu(UnicodeString naslov);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdata *data;
//---------------------------------------------------------------------------
#endif
