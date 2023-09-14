#include <System.Classes.hpp>
#include <Registry.hpp>   //za INI registre

//klasa za INI
class PostavkeINI
{
public:
	//Properties
	TIniFile* iniFile;
	UnicodeString pozadina;
	UnicodeString font;
	UnicodeString bojaFonta;
	int velicinaFonta;

	//Metode
	virtual void UcitajPostavke(UnicodeString ime);
	virtual void SpremiTrenutne();

};
