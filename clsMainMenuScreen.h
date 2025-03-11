#pragma once
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsTransactionsMenuScreen.h"
#include "clsManageUsersMenuScreen.h"
#include "clsCurrencyExchangeMenuScreen.h"
class clsMainMenuScreen :public clsScreen
{
private:
	enum enMainMenuOption{eShowClientList=1,eAddNewClient,eFindClient,eDeleteClient,eUpdateClient,eTransactionsMenu,eManageUsersMenu,eCurrencyExchangeMenu};
	static short _ReadMainMenuOption()
	{
		cout << "\n" << setw(35) << "" << "CHOOSE WHAT DO YOU WANNA DO [1~8] ? ";
		return clsInputValidate::ReadIntNumberBetween(1, 8);

	}

	static void _GoBackToMainMenu()
	{
		system("pause>0");
		cout <<"\n"<< setw(35) << "" << "press any key to go back to main manu..";
		ShowMainMenuScreen();
	}

	static  void _PerformMainMenuOption(enMainMenuOption MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case clsMainMenuScreen::eShowClientList:
			system("cls");
			clsClientsListScreen::ShowClientsListScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::eAddNewClient:
			system("cls");
			clsAddNewClientScreen::ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::eFindClient:
			system("cls");
			clsFindClientScreen::ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::eDeleteClient:
			system("cls");
			clsDeleteClientScreen::ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::eUpdateClient:
			system("cls");
			clsUpdateClientScreen::ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::eTransactionsMenu:
			system("cls");
			clsTransactionsMenuScreen::ShowTransactionsMenuScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::eManageUsersMenu:
			system("cls");
			clsManageUsersMenuScreen::ShowManageUsersMenuScreen();
			_GoBackToMainMenu();
			break;
		case clsMainMenuScreen::eCurrencyExchangeMenu:
			system("cls");
			clsCurrencyExchangeMenuScreen::ShowCurrencyExchangeMenuScreen();
			_GoBackToMainMenu();
			break;
		default:
			break;
		}
	}

public :
	static void ShowMainMenuScreen()
	{
		clsScreen::DrawScreenHeader("M A I N  M E N U","SCREEN");
		cout << "\n\n"   << setw(35) << "" << "*\tS H O W   C L I E N T   L I S T";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tA D D  N E W  C L I E N T(S)";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tF I N D  C L I E N T";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tD E L E T  C L I E N T";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tU P D A T E  C L I E N T";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tT R A N S A C T I O N S  M E N U";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tMA N A G E  U S E R S  M E N U";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tC U R R E N C Y  E X C H A N G E  M E N U";//60
		cout << "\n\n" << setw(35) << "" << "************************************************************";//60

		_PerformMainMenuOption((enMainMenuOption)_ReadMainMenuOption());

	}

};

