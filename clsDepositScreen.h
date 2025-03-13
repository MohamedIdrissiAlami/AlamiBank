#pragma once
#include "clsScreen.h"
#include "clsClient.h"
class clsDepositScreen:public clsScreen
{
private:
	static void _PrintClientCard(clsClient Client)
	{
		cout << "\n\nThe following are the client info : ";
		cout << "\n- Full Name : " << Client.FullName();
		cout << "\n- Email : " << Client.Email;
		cout << "\n- Phone : " << Client.Phone;
		cout << "\n- AccountNumber : " << Client.AccountNumber;
		cout << "\n- Pincode : " << Client.PinCode;
		printf("\n- AccountBalance %.2f", Client.AccountBalance);
	}

public :
	static void ShowDepositScreen()
	{
		//cout << "\nDeposit will be here..";
		DrawScreenHeader("D E P O S I T", "SCREEN");
		string AccountNumber = clsInputValidate::ReadString("\n\nProvide Account Number ..");

		clsClient Client = clsClient::Find(AccountNumber);
		if (!Client.IsEmptyClientObjet())
		{
			_PrintClientCard(Client);
			float DepositAmount = clsInputValidate::ReadPositiveNumber<short>("\nPlease enter deposit amount : ");
			if (tolower(clsInputValidate::ReadChar("\nAre you sure ,do you want to perform this transaction [Y/N] ? ")) == 'y')
			{
				if (Client.Deposit(DepositAmount))
					cout << "\ndone successfully! new balance : " << Client.AccountBalance;
				else
					cout << "\nsomething went wrong ,please contact us to solve this issue!";
			}
			else
				cout << "\noperation canceled!";
		}
		else
		{
			cout << "\n the client with [" << AccountNumber << "] doesn't exist!";
		}

	}
};

