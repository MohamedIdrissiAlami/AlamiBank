#pragma once
#include "clsScreen.h"
#include "clsClient.h"
class clsTransfertScreen:public clsScreen
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
	static void ShowTransfertScreen()
	{
		//cout << "\nTransfert screen will be here..";
		DrawScreenHeader("T R A N S F E R T", "SCREEN");
		string SourceAccountNumber = clsInputValidate::ReadString("\n\nProvide sender's Account Number ..");
		clsClient SourceClient = clsClient::Find(SourceAccountNumber);
		while (SourceClient.IsEmptyClientObjet())
		{
			cout << "\n the client with [" << SourceAccountNumber << "] is not found!,please try again ..";
			SourceClient = clsClient::Find((SourceAccountNumber = clsInputValidate::ReadString("\n\nProvide sender's Account Number ..")));
		}
		cout << "sender's info : ";
		_PrintClientCard(SourceClient);

		string DestinationAccountNumber= clsInputValidate::ReadString("\n\nProvide reciever's Account Number ..");
		clsClient DestinationClient = clsClient::Find(DestinationAccountNumber);
		while (DestinationClient.IsEmptyClientObjet())
		{
			cout << "\n the client with [" << SourceAccountNumber << "] is not found!,please try again ..";
			SourceClient = clsClient::Find((SourceAccountNumber = clsInputValidate::ReadString("\n\nProvide reciever's Account Number ..")));
		}
		cout << "\nReciever's info : ";
		_PrintClientCard(DestinationClient);

		float TransfertAmount = 0;
		while ((TransfertAmount = clsInputValidate::ReadPositiveNumber<float>("\nPlease enter transfert amount : ")) > SourceClient.AccountBalance)
		{
			cout << "\ntransfert Amount exceeds account balance ,try again : ";
		}
		if (tolower(clsInputValidate::ReadChar("\n\nAre you sure ,do you want to perform this transaction [Y/N] ? ")) == 'y')
		{
			if (SourceClient.Transfert(DestinationClient,TransfertAmount))
				cout << "\ndone successfully! ";
			else
				cout << "\nsomething went wrong ,please contact us to solve this issue!";
		}
		else
			cout << "\noperation canceled!";

	}
};

