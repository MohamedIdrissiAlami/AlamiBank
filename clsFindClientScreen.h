#pragma once
#include "clsScreen.h"
#include "clsClient.h"
class clsFindClientScreen:public clsScreen
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
public:
	static void ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen will be here..";
		DrawScreenHeader("F I N D  C L I E N T ", "SCREEN");
		static string AccountNumber= clsInputValidate::ReadString("\n\nProvide Account Number ..");

		clsClient Client = clsClient::Find(AccountNumber);
		if (!Client.IsEmptyClientObjet())
		{
			_PrintClientCard(Client);
		}
		else
		{
			cout << "\n the client with [" << AccountNumber << "] doesn't exist!";
		}
	}
};

