#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
#include "Global.h"
class clsClient:public clsPerson
{
private:
	enum enObjectMode{eEmpty,eUpdated,eAddNewMode};
	enObjectMode _ObjectMode;
	string _AccountNumber, _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsClient _ConvertRecordToClientObject(string Line)
	{
		vector<string>vClient = clsString::Split(Line, Separator);
		return clsClient(enObjectMode::eUpdated,vClient[0],vClient[1],vClient[2],vClient[3],vClient[4],vClient[5],stof(vClient[6]));
	}
	static clsClient GetEmptyClientObject()
	{
		return clsClient(enObjectMode::eEmpty,"", "", "", "", "", "", 0);
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

	static string _ConvertClientObjectToRecord(clsClient Client)
	{
		string ClientRecord = "";
		ClientRecord += Client.FirstName + Separator;
		ClientRecord += Client.LastName + Separator;
		ClientRecord += Client.Email + Separator;
		ClientRecord += Client.Phone + Separator;
		ClientRecord += Client.AccountNumber + Separator;
		ClientRecord += Client.PinCode + Separator;
		ClientRecord += to_string(Client.AccountBalance);
		return ClientRecord;
	}

	static void _SaveUpdatedDataToClientsFile(vector<clsClient>vClients)
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::out);//open file in overwrite mode
		if (MyFile.is_open())
		{
			for (clsClient& Client : vClients)
			{
				if (!Client._MarkedForDelete)
				{
					MyFile << _ConvertClientObjectToRecord(Client) << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsClient>vClients = _LoadClientsDataFromFileToVector();
		for (clsClient& Client : vClients)
		{
			if (Client.AccountNumber == this->AccountNumber)
			{
				Client = *this;
				break;
			}
		}
		_SaveUpdatedDataToClientsFile(vClients);
	}

	void _SaveAddedNewClient()
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::out | ios::app);//open file in the append mode
		if (MyFile.is_open())
		{
			MyFile << _ConvertClientObjectToRecord(*this) << endl;
			MyFile.close();
		}
	}

public:
	clsClient(enObjectMode ObjectMode,string FirstName, string LastName, string Email, string Phone, string AccountNumber,string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_ObjectMode = ObjectMode;
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

	static bool IsEmptyClientObjet(clsClient Client)
	{
		return Client._ObjectMode == enObjectMode::eEmpty;
	}
	bool IsEmptyClientObjet()
	{
		return IsEmptyClientObjet(*this);
	}
	static bool IsClientExist(string AccountNumber)
	{
		vector<clsClient>vClients = _LoadClientsDataFromFileToVector();
		for (clsClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
				return true;
		}
		// if you reached here this means that the client you're looking for is already exist
		return false;
	}
	bool IsClientExist()
	{
		return IsClientExist(this->AccountNumber);
	}



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

	void Delete()
	{
		vector<clsClient>vClients = _LoadClientsDataFromFileToVector();
		for (clsClient& Client : vClients)
		{
			if (Client.AccountNumber == AccountNumber)
			{
				Client._MarkedForDelete = true;
				_SaveUpdatedDataToClientsFile(vClients);
				break;
			}
		}
		*this = GetEmptyClientObject();
	}

	enum enSaveResult{eFailedEmptyObject,eSucceded,eFailedClientExists};
	enSaveResult Save()
	{
		switch (_ObjectMode)
		{
		case clsClient::eEmpty:
			return enSaveResult::eFailedEmptyObject;
		case clsClient::eUpdated:
			if (!IsEmptyClientObjet())
			{
				_Update();
				return enSaveResult::eSucceded;
			}
		case clsClient::eAddNewMode:
			if (!IsClientExist())
				return enSaveResult::eFailedClientExists;
			else
			{
				this->_ObjectMode = enObjectMode::eUpdated;
				_SaveAddedNewClient();
				return enSaveResult::eSucceded;
			}
			break;
		default:
			break;
		}
	}


};

