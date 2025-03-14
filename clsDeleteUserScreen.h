#pragma once
#include "clsScreen.h"
class clsDeleteUserScreen:public clsScreen
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
			cout << "\n\t-Show clients list.";
		if (Permissions & clsUser::enPermissions::pAddNewClients)
			cout << "\n\t-Add new clients.";
		if (Permissions & clsUser::enPermissions::pDeleteClient)
			cout << "\n\t-Delete client.";
		if (Permissions & clsUser::enPermissions::pUpdateClient)
			cout << "\n\t-Update client.";
		if (Permissions & clsUser::enPermissions::pFindClient)
			cout << "\n\t-Find client.";
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
public:
	static void ShowDeleteUserScreen()
	{
		//cout << "\nDelete User screen will be here...";
		DrawScreenHeader("D E L E T E  U S E R ", "SCREEN");
		string UserName = clsInputValidate::ReadString("\n\nProvide UserName ..");

		clsUser User = clsUser::Find(UserName);
		if (!User.IsEmptyUserObjet())
		{
			_PrintUserCard(User);
			if (tolower(clsInputValidate::ReadChar("\nyou are going to delete this User!Are You Sure ? [Y/N]..")) == 'y')
			{
				User.Delete();
				if (User.IsEmptyUserObjet())
				{
					cout << "\nthe User with UserName [" << UserName << "] was deleted successfully!";
				}
				else
				{
					cout << "\nCouldn't delete this User!";
				}
			}
		}
		else
		{
			cout << "\n the User with [" << UserName << "] doesn't exist!";
		}
	}
};

