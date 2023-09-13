//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("prijava.cpp", FPrijava);
USEFORM("podatkovniModul.cpp", data); /* TDataModule: File Type */
USEFORM("registracija.cpp", FRegistracija);
USEFORM("autori.cpp", FAutori);
USEFORM("pocetna.cpp", FPocetna);
USEFORM("knjige.cpp", FKnjige);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFPrijava), &FPrijava);
		Application->CreateForm(__classid(TFPocetna), &FPocetna);
		Application->CreateForm(__classid(Tdata), &data);
		Application->CreateForm(__classid(TFRegistracija), &FRegistracija);
		Application->CreateForm(__classid(TFAutori), &FAutori);
		Application->CreateForm(__classid(TFKnjige), &FKnjige);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
