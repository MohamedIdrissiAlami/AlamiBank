#pragma once
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotatlBalancesScreen.h"
#include "clsTransfertScreen.h"
class clsTransactionsMenuScreen:public clsScreen
{
private :
	enum enTransactionsMenuOption{eDepost=1,eWithdraw,eTransfert,eTotalBalances};
	static int _ReadTransactioinsMenuOption()
	{
		return clsInputValidate::ReadNumberBetween(1, 5,"\nMake an option [1~5]..");
	}

	static void GoBackToTransactionsMenuScreen()
	{
		cout << "\npress any key to go back to transactions menu screen..";
		system("pause>0");
		ShowTransactionsMenuScreen();
	}
	static void _PerformTransactionsMenuOption(enTransactionsMenuOption Option)
	{
		switch (Option)
		{
		case clsTransactionsMenuScreen::eDepost:
			system("cls");
			clsDepositScreen::ShowDepositScreen();
			GoBackToTransactionsMenuScreen();
			break;
		case clsTransactionsMenuScreen::eWithdraw:
			system("cls");
			clsWithdrawScreen::ShowWithdrawScreen();
			GoBackToTransactionsMenuScreen();
			break;
		case clsTransactionsMenuScreen::eTransfert:
			system("cls");
			clsTransfertScreen::ShowTransfertScreen();
			GoBackToTransactionsMenuScreen();
			break;
		case clsTransactionsMenuScreen::eTotalBalances:
			system("cls");
			clsTotatlBalancesScreen::ShowTotalBalancesScreen();
			GoBackToTransactionsMenuScreen();
			break;
		default:
			break;
		}
	}
public :
	static void ShowTransactionsMenuScreen()
	{
		system("cls");
		//cout << "\nTransactions menu screen will be here .. ";
		clsScreen::DrawScreenHeader("T R A N S A C T I O N S   M E N U", "SCREEN");
		cout << "\n\n"   << setw(35) << "" << "*\t[1] + D E P O S I T";
		cout << "\n\n\n" << setw(35) << "" << "*\t[2] + W I T H D R A W";
		cout << "\n\n\n" << setw(35) << "" << "*\t[3] + T R A N S F E R T";
		cout << "\n\n\n" << setw(35) << "" << "*\t[4] + T O T A L   B A L A N C E S";
		cout << "\n\n\n" << setw(35) << "" << "*\t[5] + E X I T";

		cout << "\n\n" << setw(35) << "" << "************************************************************";//60

		_PerformTransactionsMenuOption((enTransactionsMenuOption)_ReadTransactioinsMenuOption());

	}
};

