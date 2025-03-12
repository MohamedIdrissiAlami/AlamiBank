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

		static clsClient _ConvertRecordToClientObject(string Line)
	{
		vector<string>vClient = clsString::Split(Line, Separator);
		return clsClient(vClient[0],vClient[1],vClient[2],vClient[3],vClient[4],vClient[5],stof(vClient[6]));
	}
	static clsClient GetEmptyClientObject()
	{
		return clsClient("", "", "", "", "", "", 0);
	}

	static vector<clsClient> _LoadClientsDataFromFileToVector()
	{
		vector<clsClient>vClients;
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::in);//open file in read mode
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				vClients.push_back(_ConvertRecordToClientObject(Line));
			}
			MyFile.close();
		}
		return vClients;
	}


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

	static clsClient Find(string AccountNumber, string PinCode)
	{
		clsClient Client = GetEmptyClientObject();
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::in);//open file in read mode
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				if ((Client = _ConvertRecordToClientObject(Line)).AccountNumber == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			//if you reached here this means the client you're looking for was not found!
			MyFile.close();
		}
		return Client;

	}
	static clsClient Find(string AccountNumber)
	{
		clsClient Client = GetEmptyClientObject();
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::in);//open file in read mode
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				if ((Client = _ConvertRecordToClientObject(Line)).AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			//if you reached here this means the client you're looking for was not found!
			MyFile.close();
		}
		return Client;

	}

	static vector<clsClient> GetAllAvailableClients()
	{
		return _LoadClientsDataFromFileToVector();
	}



};

