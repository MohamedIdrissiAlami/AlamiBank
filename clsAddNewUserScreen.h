#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class clsAddNewUserScreen:public clsScreen
{
private:
	static void _PrintUserCard(clsUser User)
	{
		cout << "\n\nThe following are the User info : ";
		cout << "\n- Full Name : " << User.FullName();
		cout << "\n- Email : " << User.Email;
		cout << "\n- Phone : " << User.Phone;
		cout << "\n- UserName : " << User.UserName;
		cout << "\n- Password : " << User.Password;
		printf("\n- Permissions %.2f", User.Permissions);
	}
	static short _ReadUserPermissions()
	{
		short Permissions = 0;
		char Answer = 'n';
		cout << "\n\tdo you want to give him full access ? [Y/N] ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
			return -1;
		else
		{
			cout << "\n\tdo you want to give him access to : ";
			cout << "\n\t+Show clients list ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permissions += clsUser::enPermissions::pShowClientsList;

			cout << "\n\t+Add new  clients ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permissions += clsUser::enPermissions::pAddNewClients;


			cout << "\n\t+delete client ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permissions += clsUser::enPermissions::pDeleteClient;

			cout << "\n\t+Update Client ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permissions += clsUser::enPermissions::pUpdateClient;


			cout << "\n\t+Find Client ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permissions += clsUser::enPermissions::pFindClient;

			cout << "\n\t+Transactions ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permissions += clsUser::enPermissions::pTransactions;

			cout << "\n\t+Manage Users ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permissions += clsUser::enPermissions::pManageUsesrs;

			cout << "\n\t+Login Register ? [Y/N] ";
			cin >> Answer;
			if (tolower(Answer) == 'y')
				Permissions += clsUser::enPermissions::pLoginRegister;

			return Permissions;


		}

	}

	static void _ReadNewUserInfo(clsUser& NewUser)
	{
		NewUser.FirstName = clsInputValidate::ReadString("\nFirst Name : ");
		NewUser.LastName = clsInputValidate::ReadString("\nLast Name : ");
		NewUser.Email = clsInputValidate::ReadString("\nEmail : ");
		NewUser.Phone = clsInputValidate::ReadString("\nPhone : ");
		NewUser.Password = clsInputValidate::ReadString("\nPassword : ");
		NewUser.Permissions = _ReadUserPermissions();
	}
public:

public:
	static void ShowAddNewUserScreen()
	{
		//cout << "\n Add new User screen will be here..";
		DrawScreenHeader("A D D  N E W  U S E R ", "SCREEN");
		string UserName = clsInputValidate::ReadString("\n\nProvide Account Number ..");
		if (!clsUser::IsUserExist(UserName))
		{
			clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
			do
			{

				_ReadNewUserInfo(NewUser);
				if (NewUser.Save() == clsUser::enSaveResult::eSucceded)
				{
					cout << "\nthe new User info saved successfully!";
				}
				else
				{
					cout << "\nsomething went wrong with saving this new User ,please contact us to solve this issue!";
					break;
				}

			} while (tolower(clsInputValidate::ReadChar("\nDo you wanna add more more Users ? [Y/N]..")) == 'y');

		}
		else
		{
			cout << "\nthe User with [" << UserName << "] already exists!";
		}
	}
};



