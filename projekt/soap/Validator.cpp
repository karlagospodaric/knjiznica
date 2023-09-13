// ************************************************************************ //
// Implementation class for interface IValidator
// ************************************************************************ //
#include <stdio.h>
#include <vcl.h>
#pragma hdrstop

#if !defined(__Validator_h__)
#include "Validator.h"
#endif

// ************************************************************************ //
//  TValidatorImpl implements interface IValidator
// ************************************************************************ //
class TValidatorImpl : public TInvokableClass, public IValidator
{
public:

  /* IUnknown */
  HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& IID, void **Obj)
                        { return GetInterface(IID, Obj) ? S_OK : E_NOINTERFACE; }
  ULONG STDMETHODCALLTYPE AddRef() { return TInvokableClass::_AddRef();  }
  ULONG STDMETHODCALLTYPE Release() { return TInvokableClass::_Release();  }

  //implementacija metode za provjeru emaila
  bool emailValid(UnicodeString email){
	int atPos = email.Pos("@");  //lociraj @
	if (atPos == 0 or atPos == email.Length()) {
		return false; // "@" nije pronađen ili je na početku/kraju
	}
	int comPos = email.Pos(".com");  //lociraj .com
	int hrPos = email.Pos(".hr");    // lociraj .hr
	if(comPos > atPos or hrPos > atPos){
		return true; //ako je .com ili .hr iza @ vrati true
	}else{
		return false;
	}
  }

  //implementacija metode za provjeru lozinke
  bool passValid(UnicodeString pass){
	int duljina = pass.Length();
	if (duljina < 8){           //duljina lozinke mora biti minimalno 6 znakova
		return false;
	}else{
		return true;
    }
  }
};


static void __fastcall ValidatorFactory(System::TObject* &obj)
{
  static _di_IValidator iInstance;
  static TValidatorImpl *instance = 0;
  if (!instance)
  {
    instance = new TValidatorImpl();
    instance->GetInterface(iInstance);
  }
  obj = instance;
}

// ************************************************************************ //
//  The following routine registers the interface and implementation class
// ************************************************************************ //
static void RegTypes()
{
  InvRegistry()->RegisterInterface(__delphirtti(IValidator));
  InvRegistry()->RegisterInvokableClass(__classid(TValidatorImpl), ValidatorFactory);
}
#pragma startup RegTypes 32

