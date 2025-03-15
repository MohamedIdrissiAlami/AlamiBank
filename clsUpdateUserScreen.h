#pragma once
#include "clsScreen.h"
class clsUpdateUserScreen:public clsScreen
{
private:
	static void _PrintUserPermissions(short Permissions)
	{
		if (Permissions == clsUser::enPermissions::pAll)
		{
			cout << "\n\t-Full access.";
			return;
		}
		if (Permissions == clsUser::clsUser::enPermissions::pNothing)
		{
			cout << "\n\t-Nothing.";
			return;
		}
		if (Permissions & clsUser::enPermissions::pShowClientsList)
			cout << "\n\t-Show Client list.";
		if (Permissions & clsUser::enPermissions::pAddNewClients)
			cout << "\n\t-Add new Clients.";
		if (Permissions & clsUser::enPermissions::pDeleteClient)
			cout << "\n\t-Delete Client.";
		if (Permissions & clsUser::enPermissions::pUpdateClient)
			cout << "\n\t-Update Client.";
		if (Permissions & clsUser::enPermissions::pFindClient)
			cout << "\n\t-Find Client.";
		if (Permissions & clsUser::enPermissions::pTransactions)
			cout << "\n\t-Transations.";
		if (Permissions & clsUser::enPermissions::pManageUsesrs)
			cout << "\n\t-Manage Users.";



	}
	static void _PrintUserCard(clsUser User)
	{
		cout << "\nthe following are the User's info";

		cout << "\n\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUserName    : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nthe following are their permissions : ";
		_PrintUserPermissions(User.Permissions);

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
		static void ShowUpdateUserScreen()
		{
			//cout << "\nUpdate User screen will be here..";
			DrawScreenHeader("U P D A T E  U S E R ", "SCREEN");
			string UserName = clsInputValidate::ReadString("\n\nProvide UserName ..");
			clsUser User = clsUser::Find(UserName);

			if (!User.IsEmptyUserObjet())
			{
				_PrintUserCard(User);
				if (tolower(clsInputValidate::ReadChar("\nyou are going to update the User above info.Are you sure? [Y/N]..")) == 'y')
				{
					_ReadNewUserInfo(User);
					if (User.Save() == clsUser::enSaveResult::eSucceded)
					{
						cout << "\nthe new User info saved successfully!";
					}
					else
					{
						cout << "\nsomething went wrong with saving this new User ,please contact us to solve this issue!";
					}
				}
				else
					cout << "\nCanceled!";
			}
			else
			{
				cout << "\nthe User with [" << UserName << "] is not found!";
			}
		}

	};

