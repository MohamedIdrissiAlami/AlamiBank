#pragma once
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsersMenuScreen:public clsScreen
{
private:
	enum enManageUsersMenuOption{eShowUsersList=1,eAddNewUsers,eDeleteUsers,eUpdateUsers,eFindUsers,eExit};
	static int _ReadManageUsersMenuOption()
	{
		return clsInputValidate::ReadNumberBetween<short>(1, 6,"\nChoose what do you wanna do [1~6] ");
	}

	static void _GoBackToManageUsersMenuScreen()
	{
		cout << "\nPress any key to go back to manage users menu screen...";
		system("pause>0");
		ShowManageUsersMenuScreen();
	}

	static void _PerformTransactionsMenuOption(enManageUsersMenuOption Option)
	{
		switch (Option)
		{
		case clsManageUsersMenuScreen::eShowUsersList:
			system("cls");
			clsUsersListScreen::ShowUsersListScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case clsManageUsersMenuScreen::eAddNewUsers:
			system("cls");
			clsAddNewUserScreen::ShowAddNewUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case clsManageUsersMenuScreen::eDeleteUsers:
			system("cls");
			clsDeleteUserScreen::ShowDeleteUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case clsManageUsersMenuScreen::eUpdateUsers:
			system("cls");
			clsUpdateUserScreen::ShowUpdateUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case clsManageUsersMenuScreen::eFindUsers:
			system("cls");
			clsFindUserScreen::ShowFindUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case clsManageUsersMenuScreen::eExit:
			break;
		default:
			break;
		}
	}

public:
	static void ShowManageUsersMenuScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pManageUsesrs))
			return;

		//cout << "\nManage users menu screen will be here..";
		system("cls");
		clsScreen::DrawScreenHeader("M A N A G E  U S E R S   M E N U", "SCREEN");
		cout << "\n\n"   << setw(35) << "" << "*\t[1] + S H O W  U S E R S  L I S T";
		cout << "\n\n\n" << setw(35) << "" << "*\t[2] + A D D  N E W  U S E R(S)";
		cout << "\n\n\n" << setw(35) << "" << "*\t[3] + D E L E T E  U S E R";
		cout << "\n\n\n" << setw(35) << "" << "*\t[4] + U P D A T E  U S E R  I N F O";
		cout << "\n\n\n" << setw(35) << "" << "*\t[5] + F I N D  U S E R";
		cout << "\n\n\n" << setw(35) << "" << "*\t[6] + E X I T";

		cout << "\n\n" << setw(35) << "" << "************************************************************";//60

		_PerformTransactionsMenuOption((enManageUsersMenuOption)_ReadManageUsersMenuOption());

	}
};

