#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
#include "Global.h"
class clsClient:public clsPerson
{
private:
	string _AccountNumber, _PinCode;
	float _AccountBalance;

public:
	clsClient(string FirstName, string LastName, string Email, string Phone, string AccountNumber,string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	void SetAccountNumber(string AccountNumber)
	{
		_AccountNumber = AccountNumber;
	}
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


};

