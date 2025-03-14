#pragma once
#include "clsPerson.h";
#include "clsString.h"
#include <fstream>
#include "Global.h"
class clsUser:public clsPerson
{
private:
	enum enObjectMode { eEmpty, eUpdated, eAddNewMode };
	enObjectMode _ObjectMode;
	string _UserName, _Password;
	int _Permissions;
	bool _MarkedForDelete = false;

	static clsUser _ConvertRecordToUserObject(string Line)
	{
		vector<string>vUser = clsString::Split(Line, Separator);
		return clsUser(enObjectMode::eUpdated, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], vUser[5], stoi(vUser[6]));
	}
	static clsUser GetEmptyUserObject()
	{
		return clsUser(enObjectMode::eEmpty, "", "", "", "", "", "", 0);
	}

	static vector<clsUser> _LoadUsersDataFromFileToVector()
	{
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);//open file in read mode
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				vUsers.push_back(_ConvertRecordToUserObject(Line));
			}
			MyFile.close();
		}
		return vUsers;
	}

	static string _ConvertUserObjectToRecord(clsUser User)
	{
		string UserRecord = "";
		UserRecord += User.FirstName + Separator;
		UserRecord += User.LastName + Separator;
		UserRecord += User.Email + Separator;
		UserRecord += User.Phone + Separator;
		UserRecord += User.UserName + Separator;
		UserRecord += User.Password + Separator;
		UserRecord += to_string(User.Permissions);
		return UserRecord;
	}

	static void _SaveUpdatedDataToUsersFile(vector<clsUser>vUsers)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::out);//open file in overwrite mode
		if (MyFile.is_open())
		{
			for (clsUser& User : vUsers)
			{
				if (!User._MarkedForDelete)
				{
					MyFile << _ConvertUserObjectToRecord(User) << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsUser>vUsers = _LoadUsersDataFromFileToVector();
		for (clsUser& User : vUsers)
		{
			if (User.UserName == this->UserName)
			{
				User = *this;
				break;
			}
		}
		_SaveUpdatedDataToUsersFile(vUsers);
	}

	void _SaveAddedNewUser()
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::out | ios::app);//open file in the append mode
		if (MyFile.is_open())
		{
			MyFile << _ConvertUserObjectToRecord(*this) << endl;
			MyFile.close();
		}
	}

public:
	clsUser(enObjectMode ObjectMode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, float Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_ObjectMode = ObjectMode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	enum enPermissions {
		pAll = -1, pNothing = 0, pShowClientsList = 1, pAddNewClients = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransactions = 32,
		pManageUsesrs = 64, pLoginRegister = 128, pUpdateCurrencyRate = 256
	};

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	void SetPermissions(float Permissions)
	{
		_Permissions = Permissions;
	}
	string GetUserName()
	{
		return _UserName;
	}
	string GetPassword()
	{
		return _Password;
	}
	float GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	__declspec(property(get = GetPermissions, put = SetPermissions)) float Permissions;

	static bool IsEmptyUserObjet(clsUser User)
	{
		return User._ObjectMode == enObjectMode::eEmpty;
	}
	bool IsEmptyUserObjet()
	{
		return IsEmptyUserObjet(*this);
	}
	static bool IsUserExist(string UserName)
	{
		vector<clsUser>vUsers = _LoadUsersDataFromFileToVector();
		for (clsUser& C : vUsers)
		{
			if (C.UserName == UserName)
				return true;
		}
		// if you reached here this means that the User you're looking for is already exist
		return false;
	}
	bool IsUserExist()
	{
		return IsUserExist(this->UserName);
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enObjectMode::eAddNewMode, "", "", "", "", UserName, "", 0);
	}

	static clsUser Find(string UserName, string Password)
	{
		clsUser User = GetEmptyUserObject();
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);//open file in read mode
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				if ((User = _ConvertRecordToUserObject(Line)).UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
			}
			//if you reached here this means the User you're looking for was not found!
			MyFile.close();
		}
		return GetEmptyUserObject();
	}
	static clsUser Find(string UserName)
	{
		clsUser User = GetEmptyUserObject();
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);//open file in read mode
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				if ((User = _ConvertRecordToUserObject(Line)).UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			//if you reached here this means the User you're looking for was not found!
			MyFile.close();
		}
		return GetEmptyUserObject();

	}

	static vector<clsUser> GetAllAvailableUsers()
	{
		return _LoadUsersDataFromFileToVector();
	}

	void Delete()
	{
		vector<clsUser>vUsers = _LoadUsersDataFromFileToVector();
		for (clsUser& User : vUsers)
		{
			if (User.UserName == UserName)
			{
				User._MarkedForDelete = true;
				_SaveUpdatedDataToUsersFile(vUsers);
				break;
			}
		}
		*this = GetEmptyUserObject();
	}


	enum enSaveResult { eFailedEmptyObject, eSucceded, eFailedUserExists };
	enSaveResult Save()
	{
		switch (_ObjectMode)
		{
		case clsUser::eEmpty:
			return enSaveResult::eFailedEmptyObject;
		case clsUser::eUpdated:
			if (!IsEmptyUserObjet())
			{
				_Update();
				return enSaveResult::eSucceded;
			}
		case clsUser::eAddNewMode:
			if (IsUserExist())
				return enSaveResult::eFailedUserExists;
			else
			{
				this->_ObjectMode = enObjectMode::eUpdated;
				_SaveAddedNewUser();
				return enSaveResult::eSucceded;
			}
			break;
		default:
			break;
		}
	}


};


