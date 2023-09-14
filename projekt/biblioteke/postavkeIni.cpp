#include "postavkeIni.h"
//#include <Vcl.Graphics.hpp>  //za korištenje StringToColor

//Učitaj postavke iz zadanog odjeljka (čitanje iz INI file-a)
void PostavkeINI::UcitajPostavke(UnicodeString ime){
	iniFile = new TIniFile("..\\glavna\\postavke.ini");
	pozadina = iniFile->ReadString(ime, "pozadina", "clBtnFace");
	font = iniFile->ReadString(ime, "font", "Segoe UI");
	bojaFonta = iniFile->ReadString(ime, "bojaFonta", "clWindowText");
	velicinaFonta = iniFile->ReadInteger(ime, "velicinaFonta", 22);
	delete iniFile;
}

//Spremi postavke u TRENUTNE POSTAVKE (pisanje u INI file)
void PostavkeINI::SpremiTrenutne(){
	iniFile = new TIniFile("..\\glavna\\postavke.ini");
	iniFile->WriteString("TRENUTNE POSTAVKE", "pozadina", pozadina);
	iniFile->WriteString("TRENUTNE POSTAVKE", "font", font);
	iniFile->WriteString("TRENUTNE POSTAVKE", "bojaFonta", bojaFonta);
	iniFile->WriteInteger("TRENUTNE POSTAVKE", "velicinaFonta", velicinaFonta);
	delete iniFile;
}

