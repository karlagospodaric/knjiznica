// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost/SoapProvjera.dll/wsdl/IValidator
// Version  : 1.0
// (9.8.2023. 12:23:34 - - $Rev: 108085 $)
// ************************************************************************ //

#ifndef   IValidatorH
#define   IValidatorH

#include <System.hpp>
#include <Soap.InvokeRegistry.hpp>
#include <Soap.XSBuiltIns.hpp>
#include <Soap.SOAPHTTPClient.hpp>

#if !defined(SOAP_REMOTABLE_CLASS)
#define SOAP_REMOTABLE_CLASS __declspec(delphiclass)
#endif

namespace NS_IValidator {

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were referred
// to but never[!] declared in the document. The types from the latter category
// typically map to predefined/known XML or Embarcadero types; however, they could also
// indicate incorrect WSDL documents that failed to declare or import a schema type.
// ************************************************************************ //
// !:string          - "http://www.w3.org/2001/XMLSchema"[]
// !:boolean         - "http://www.w3.org/2001/XMLSchema"[]


// ************************************************************************ //
// Namespace : urn:Validator-IValidator
// soapAction: urn:Validator-IValidator#%operationName%
// transport : http://schemas.xmlsoap.org/soap/http
// style     : rpc
// use       : encoded
// binding   : IValidatorbinding
// service   : IValidatorservice
// port      : IValidatorPort
// URL       : http://localhost/SoapProvjera.dll/soap/IValidator
// ************************************************************************ //
__interface INTERFACE_UUID("{0B65E3BB-A65C-224E-CACA-0FB55802C860}") IValidator : public IInvokable
{
public:
  virtual bool            emailValid(const UnicodeString email) = 0;
  virtual bool            passValid(const UnicodeString pass) = 0;
};
typedef DelphiInterface<IValidator> _di_IValidator;

_di_IValidator GetIValidator(bool useWSDL=false, System::String addr= System::String(), Soaphttpclient::THTTPRIO* HTTPRIO=0);


};     // NS_IValidator

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace NS_IValidator;
#endif



#endif // IValidatorH

