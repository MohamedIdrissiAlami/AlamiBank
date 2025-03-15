#pragma once
#include "clsScreen.h"
#include "clsClient.h"
class clsAddNewClientScreen:public clsScreen
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

public: 
	static void ShowAddNewClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pAddNewClients))
			return;

		//cout << "\n Add new client screen will be here..";
		DrawScreenHeader("A D D  N E W  C L I E N T ", "SCREEN");
		string AccountNumber = clsInputValidate::ReadString("\n\nProvide Account Number ..");
		if (!clsClient::IsClientExist(AccountNumber))
		{
			clsClient NewClient = clsClient::GetAddNewClientObject(AccountNumber);
			do
			{

				_ReadNewClientInfo(NewClient);
				if (NewClient.Save() == clsClient::enSaveResult::eSucceded)
				{
					cout << "\nthe new client info saved successfully!";
				}
				else
				{
					cout << "\nsomething went wrong with saving this new client ,please contact us to solve this issue!";
					break;
				}
				
			} while (tolower(clsInputValidate::ReadChar("\nDo you wanna add more more clients ? [Y/N]..")) == 'y');

		}
		else
		{
			cout << "\nthe client with [" << AccountNumber << "] already exists!";
		}
	}
};

