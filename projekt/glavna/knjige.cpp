//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "knjige.h"
#include "podatkovniModul.h"
#include "prijava.h"
#include "..\biblioteke\postavkeWR_binarna.h"
#include <jpeg.hpp>
#include <pngimage.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFKnjige *FKnjige;
//---------------------------------------------------------------------------
__fastcall TFKnjige::TFKnjige(TComponent* Owner)
	: TForm(Owner)
{
    //prijevod forme
	prijevod["Label4"] =	{
		{
			{"EN", "Title:"},
			{"HR", "Naslov:"}
		}
	};
	prijevod["Label5"] =	{
		{
			{"EN", "Author:"},
			{"HR", "Autor:"}
		}
	};
	prijevod["Label1"] =	{
		{
			{"EN", "Year of publication:"},
			{"HR", "Godina izdanja:"}
		}
	};
	prijevod["Label2"] =	{
		{
			{"EN", "Publisher:"},
			{"HR", "Izdavač:"}
		}
	};
	prijevod["Label9"] =	{
		{
			{"EN", "Choose the logo of the publisher:"},
			{"HR", "Odaberite logo izdavača:"}
		}
	};
	prijevod["Label8"] =	{
		{
			{"EN", "Logo of the publisher:"},
			{"HR", "Logo izdavača:"}
		}
	};
	prijevod["GroupBox2"] =	{
		{
			{"EN", "Book details"},
			{"HR", "Podatci o knjizi"}
		}
	};
	prijevod["BDodaj"] =	{
		{
			{"EN", "Add"},
			{"HR", "Dodaj"}
		}
	};
	prijevod["BObrisi"] =	{
		{
			{"EN", "Delete"},
			{"HR", "Obriši"}
		}
	};
	prijevod["BOdustani"] =	{
		{
			{"EN", "Cancel"},
			{"HR", "Odustani"}
		}
	};
	prijevod["BUredi"] =	{
		{
			{"EN", "Edit"},
			{"HR", "Uredi"}
		}
	};
	prijevod["BPosudi"] =	{
		{
			{"EN", "Borrow a book"},
			{"HR", "Posudi knjigu"}
		}
	};
	prijevod["BFilter"] =	{
		{
			{"EN", "Available books"},
			{"HR", "Dostupne knjige"}
		}
	};
	prijevod["BVrati"] =	{
		{
			{"EN", "Return a book"},
			{"HR", "Vrati knjigu"}
		}
	};
}
//---------------------------------------------------------------------------
void __fastcall TFKnjige::BDodajClick(TObject *Sender)
{
	//ne izvodi program ako nedostaju podatci
	if(ENaslov->Text == "" or EGodina->Text == "" or CBAutori->ItemIndex == -1 or CBIzdavaci->ItemIndex == -1){
		ShowMessage("Unesite podatke!");
		return;
	}

	//pronađi autorID pomoću metode pronadi
	Autori autor;
	int autorID;
	autorID = autor.pronadi(CBAutori->Text);



	//pozovi metodu dodaj da se upišu podatci u tablicu Knjige
	Knjige knjiga;
	bool dodano;

	dodano = knjiga.Dodaj(ENaslov->Text, autorID, EGodina->Text.ToInt(), CBIzdavaci->Text, pic);

	if(dodano == true){
		ShowMessage("Uspješno dodana knjiga!");
		ENaslov->Clear();
		EGodina->Clear();
		CBAutori->ItemIndex = -1;
		CBIzdavaci->ItemIndex = -1;
	}else{
		ShowMessage("Pogreška");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFKnjige::DBGrid1CellClick(TColumn *Column)
{
	if(DBGrid1->SelectedIndex != -1){
		ENaslov->Text = DBGrid1->Columns->Items[0]->Field->Value;
		EGodina->Text = DBGrid1->Columns->Items[3]->Field->Value;
		BDodaj->Enabled = false;
		BUredi->Enabled = true;
        BObrisi->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFKnjige::BUrediClick(TObject *Sender)
{
    //pronađi autorID pomoću metode pronadi
	Autori autor;
	int autorID;
	if(CBAutori->ItemIndex != -1){
		autorID = autor.pronadi(CBAutori->Text);
	}

    Knjige knjiga;
	bool uredeno;
	uredeno = knjiga.Uredi(ENaslov->Text, autorID, EGodina->Text.ToInt(), CBIzdavaci->Text, pic);

	if(uredeno == true){
		ShowMessage("Uspješno uređena knjiga!");
		ENaslov->Clear();
		EGodina->Clear();
		CBAutori->ItemIndex = -1;
		CBIzdavaci->ItemIndex = -1;
		BDodaj->Enabled = true;
		BUredi->Enabled = false;
		BObrisi->Enabled = false;
	}else{
		ShowMessage("Pogreška");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFKnjige::BObrisiClick(TObject *Sender)
{
	Knjige knjiga;
	bool obrisano;
	obrisano = knjiga.Obrisi(ENaslov->Text);

	if(obrisano == true){
		ShowMessage("Uspješno obrisana knjiga!");
		ENaslov->Clear();
		EGodina->Clear();
		CBAutori->ItemIndex = -1;
		CBIzdavaci->ItemIndex = -1;
		BDodaj->Enabled = true;
		BUredi->Enabled = false;
		BObrisi->Enabled = false;
	}else{
		ShowMessage("Pogreška");
	}
}
//---------------------------------------------------------------------------


void __fastcall TFKnjige::BOdustaniClick(TObject *Sender)
{
	//obriši sve podatke i vrati na početno stanje
	ENaslov->Clear();
	EGodina->Clear();
	CBAutori->ItemIndex = -1;
	CBIzdavaci->ItemIndex = -1;
	BDodaj->Enabled = true;
	BUredi->Enabled = false;
	BObrisi->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFKnjige::BPosudiClick(TObject *Sender)
{
	Knjige k;
	bool posudeno;

	//ako je označena knjiga pozovi metodu posudenaKnjiga
	if(DBGrid1->SelectedIndex != -1){
		posudeno = k.posudenaKnjiga(ENaslov->Text);
	}

	if(posudeno == true){
		ShowMessage("Uspješno posuđena knjiga!");
		ENaslov->Clear();
		EGodina->Clear();
		CBAutori->ItemIndex = -1;
		CBIzdavaci->ItemIndex = -1;
		BDodaj->Enabled = true;
		BUredi->Enabled = false;
		BObrisi->Enabled = false;
	}else{
		ShowMessage("Pogreška");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFKnjige::BVratiClick(TObject *Sender)
{
	Knjige book;
	bool vraceno;
	//pozovi metodu vratiKnjigu ako je označena knjiga
	if(DBGrid1->SelectedIndex != -1){
		vraceno = book.vratiKnjigu(ENaslov->Text);
	}

	if(vraceno == true){
		ShowMessage("Uspješno vraćena knjiga!");
		ENaslov->Clear();
		EGodina->Clear();
		CBAutori->ItemIndex = -1;
		CBIzdavaci->ItemIndex = -1;
		BDodaj->Enabled = true;
		BUredi->Enabled = false;
		BObrisi->Enabled = false;
	}else{
		ShowMessage("Pogreška");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFKnjige::BFilterClick(TObject *Sender)
{
	//filtriraj podatke iz tablice Knjige po dostupnosti
	data->TKnjige->Filtered = false;
	data->TKnjige->Filter = "dostupnost = " + BoolToStr(true);
	data->TKnjige->Filtered = true;

}
//---------------------------------------------------------------------------

void __fastcall TFKnjige::FormShow(TObject *Sender)
{
	//osvježi tablice
	data->TKnjige->Refresh();
	data->TAutori->Refresh();

	//makni master detail
    data->TKnjige->MasterSource = NULL;
	data->TKnjige->MasterFields = "";

	//sortiraj knjige po naslovu
	data->TKnjige->IndexFieldNames = "naslov";

	//instanciranje toka za spremanje slike iz image komponente
	pic = new TMemoryStream();

	//čitanje podataka iz binarnog formata u stream
	std::unique_ptr<TFileStream> izdavacStream (new TFileStream("izdavaci.bff", fmOpenRead));
	Izdavaci format;
	izdavacStream->Read(&format, sizeof(Izdavaci));

	//provjeri je li dobar format
	if(UnicodeString(format._naziv) != L"Izdavači" || format._verzija != 1.0){
		ShowMessage("Pogrešan format!");
		return;
	}

	Izdavac pomocna;
	int brIzdavaca = (izdavacStream->Size - sizeof(Izdavaci)) / sizeof(Izdavac);

	CBIzdavaci->Clear();

	//dodaj naziv izdavača u combo box
	for (int i = 0; i < brIzdavaca; i++){
		izdavacStream->Read(&pomocna, sizeof(Izdavac));
		CBIzdavaci->Items->Add(String(pomocna._imeTvrtke));
	}

	//dodavanje autora u combo box autori
    CBAutori->Clear();
	data->TAutori->First();
	for(int i = 0; i < data->TAutori->RecordCount; i++){
		UnicodeString ime = data->TAutori->FieldByName("imeAutora")->AsString;
		UnicodeString prezime = data->TAutori->FieldByName("prezimeAutora")->AsString;
		CBAutori->Items->Add(ime + " " + prezime);
		data->TAutori->Next();
	}

	//učitavanje slika iz dinamičkeBiblioteke u Image komponente
	HINSTANCE slikaDll;
	if((slikaDll = LoadLibrary(L"dinamickaBiblioteka.dll")) == NULL){
		ShowMessage("DLL greška");
		return;
	}
	TResourceStream* slika1 = new TResourceStream((int)slikaDll, "ALEGRIA", RT_RCDATA);
	TResourceStream* slika2 = new TResourceStream((int)slikaDll, "ALGORITAM", RT_RCDATA);
	TResourceStream* slika3 = new TResourceStream((int)slikaDll, "LUMEN", RT_RCDATA);
	Image1->Picture->LoadFromStream(slika1);
	Image2->Picture->LoadFromStream(slika2);
	Image3->Picture->LoadFromStream(slika3);
	delete slika1;
	delete slika2;
	delete slika3;
}
//---------------------------------------------------------------------------

void __fastcall TFKnjige::FormClose(TObject *Sender, TCloseAction &Action)
{
	data->TKnjige->Filtered = false;
	data->TKnjige->Filter = "";
	data->TAutori->Refresh();
	data->TKnjige->Refresh();
	delete pic;
}
//---------------------------------------------------------------------------

void __fastcall TFKnjige::Image1Click(TObject *Sender)
{
	pic->Clear();
	Image1->Picture->SaveToStream(pic);
}
//---------------------------------------------------------------------------

void __fastcall TFKnjige::Image2Click(TObject *Sender)
{
	pic->Clear();
	Image2->Picture->SaveToStream(pic);
}
//---------------------------------------------------------------------------

void __fastcall TFKnjige::Image3Click(TObject *Sender)
{
    pic->Clear();
	Image3->Picture->SaveToStream(pic);
}
//---------------------------------------------------------------------------



