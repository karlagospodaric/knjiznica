// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost/SoapProvjera.dll/wsdl/IValidator
// Version  : 1.0
// (9.8.2023. 12:23:34 - - $Rev: 108085 $)
// ************************************************************************ //

#include <System.hpp>
#pragma hdrstop

#include "IValidator.h"



namespace NS_IValidator {

_di_IValidator GetIValidator(bool useWSDL, System::String addr, Soaphttpclient::THTTPRIO* HTTPRIO)
{
  static const char* defWSDL= "http://localhost/SoapProvjera.dll/wsdl/IValidator";
  static const char* defURL = "http://localhost/SoapProvjera.dll/soap/IValidator";
  static const char* defSvc = "IValidatorservice";
  static const char* defPrt = "IValidatorPort";
  if (addr=="")
    addr = useWSDL ? defWSDL : defURL;
  Soaphttpclient::THTTPRIO* rio = HTTPRIO ? HTTPRIO : new Soaphttpclient::THTTPRIO(0);
  if (useWSDL) {
    rio->WSDLLocation = addr;
    rio->Service = defSvc;
    rio->Port = defPrt;
  } else {
    rio->URL = addr;
  }
  _di_IValidator service;
  rio->QueryInterface(service);
  if (!service && !HTTPRIO)
    delete rio;
  return service;
}


// ************************************************************************ //
// This routine registers the interfaces and types exposed by the WebService.
// ************************************************************************ //
static void RegTypes()
{
  /* IValidator */
  InvRegistry()->RegisterInterface(__delphirtti(IValidator), L"urn:Validator-IValidator", L"");
  InvRegistry()->RegisterDefaultSOAPAction(__delphirtti(IValidator), L"urn:Validator-IValidator#%operationName%");
  /* IValidator->emailValid */
  InvRegistry()->RegisterParamInfo(__delphirtti(IValidator), "emailValid", "return_", L"return", L"");
  /* IValidator->passValid */
  InvRegistry()->RegisterParamInfo(__delphirtti(IValidator), "passValid", "return_", L"return", L"");
}
#pragma startup RegTypes 32

};     // NS_IValidator


