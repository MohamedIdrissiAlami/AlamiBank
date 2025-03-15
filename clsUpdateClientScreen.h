#pragma once
#include "clsScreen.h"
class clsUpdateClientScreen :public clsScreen
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
	static void _ReadNewClientInfo(clsClient& NewClient)
	{
		NewClient.FirstName = clsInputValidate::ReadString("\nFirst Name : ");
		NewClient.LastName = clsInputValidate::ReadString("\nLast Name : ");
		NewClient.Email = clsInputValidate::ReadString("\nEmail : ");
		NewClient.Phone = clsInputValidate::ReadString("\nPhone : ");
		NewClient.PinCode = clsInputValidate::ReadString("\nPinCode : ");
	}
public:
	static void ShowUpdateClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pUpdateClient))
			return;

		//cout << "\nUpdate Client screen will be here..";
		DrawScreenHeader("U P D A T E  C L I E N T ", "SCREEN");
		string AccountNumber = clsInputValidate::ReadString("\n\nProvide Account Number ..");
		clsClient Client = clsClient::Find(AccountNumber);

		if (!Client.IsEmptyClientObjet())
		{
			_PrintClientCard(Client);
			if (tolower(clsInputValidate::ReadChar("\nyou are going to update the client above info.Are you sure? [Y/N].."))=='y')
			{
				_ReadNewClientInfo(Client);
				if (Client.Save() == clsClient::enSaveResult::eSucceded)
				{
					cout << "\nthe new client info saved successfully!";
				}
				else
				{
					cout << "\nsomething went wrong with saving this new client ,please contact us to solve this issue!";
				}
			}
			cout << "\nCanceled!";
		}
		else
		{
			cout << "\nthe client with [" << AccountNumber << "] is not found!";
		}
	}

};

