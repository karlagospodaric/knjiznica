#include <Registry.hpp>
#ifdef EXPORTS  // definirati u DLL projektu
  #define DLL_EXPORT __declspec(dllexport) // U DLL-u
#else
  #define DLL_EXPORT __declspec(dllimport) // U aplikaciji koja koristi DLL
#endif

extern "C"{
    class DLL_EXPORT PostavkeWR
	{
	public:
		//properties
		TRegistry *registar;
		UnicodeString kljuc;
		bool pohrana;
		UnicodeString korisnickoIme;
		UnicodeString lozinka;

		//metode
		virtual void citaj();
		virtual void upisi();
		virtual void brisi();

		PostavkeWR();
		virtual ~PostavkeWR();
	};
}

