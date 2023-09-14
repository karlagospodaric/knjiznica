#include <Registry.hpp>
#ifdef EXPORTS  // definirati u DLL projektu
  #define DLL_EXPORT __declspec(dllexport) // U DLL-u
#else
  #define DLL_EXPORT __declspec(dllimport) // U aplikaciji koja koristi DLL
#endif

extern "C"{
    //klasa za spremanje postavki za fast login u Windows registry
	class DLL_EXPORT PostavkeWR
	{
	public:
		//properties
		TRegistry *registar;
		UnicodeString kljuc;
		bool pohrana;
		UnicodeString korisnickoIme;
		UnicodeString lozinka;
		UnicodeString jezik;

		//metode
		virtual bool citaj();
		virtual void upisi();
		virtual void brisi();
		virtual void spremiJezik(UnicodeString odabrano);

		PostavkeWR();
		virtual ~PostavkeWR();
	};

    //binarni format (zaglavlje)
	class DLL_EXPORT Izdavaci{
	public:
		wchar_t _naziv[10];
		float _verzija;
		Izdavaci();
	};

	//binarni format (popis izdavača)
	class DLL_EXPORT Izdavac{
	public:
		wchar_t _imeTvrtke[25], _drzava[25];
		int _sifra;
		Izdavac(){}
		Izdavac(int sifra, wchar_t* naziv, wchar_t* drzava);
	};
}

