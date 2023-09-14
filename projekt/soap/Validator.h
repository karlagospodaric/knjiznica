// ************************************************************************ //
// Invokable interface declaration header for Validator
// ************************************************************************ //
#ifndef   ValidatorH
#define   ValidatorH

#include <System.hpp>
#include <Soap.InvokeRegistry.hpp>
#include <Soap.XSBuiltIns.hpp>
#include <System.Types.hpp>



// ************************************************************************ //
//  Invokable interfaces must derive from IInvokable
//  The methods of the interface will be exposed via SOAP
// ************************************************************************ //
__interface INTERFACE_UUID("{FDE769F0-08AA-4566-A179-5B3096D5AFB7}") IValidator : public IInvokable
{
public:
    //metoda za provjeru maila
	virtual bool emailValid (UnicodeString email) = 0;

	//metoda za provjeru lozinke
    virtual bool passValid (UnicodeString pass) = 0;
};
typedef DelphiInterface<IValidator> _di_IValidator;


#endif // ValidatorH
//---------------------------------------------------------------------------


