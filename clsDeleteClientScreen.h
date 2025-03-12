#pragma once
#include "clsScreen.h"
#include "clsClient.h"
class clsDeleteClientScreen:public clsScreen
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
	static void ShowDeleteClientScreen()
	{
		//cout << "\nDelete client screen will be here...";
		DrawScreenHeader("D E L E T E  C L I E N T ", "SCREEN");
		static string AccountNumber = clsInputValidate::ReadString("\n\nProvide Account Number ..");

		clsClient Client = clsClient::Find(AccountNumber);
		if (!Client.IsEmptyClientObjet())
		{
			_PrintClientCard(Client);
			if (tolower(clsInputValidate::ReadChar("\nyou are going to delete this Client!Are You Sure ? [Y/N]..")) == 'y')
			{
				Client.Delete();
				if (!Client.IsEmptyClientObjet())
				{
					cout << "\nthe client with accountnumber [" << AccountNumber << "] was deleted successfully!";
				}
				else
				{
					cout << "\nCouldn't delete this client!";
				}
			}

		}
		else
		{
			cout << "\n the client with [" << AccountNumber << "] doesn't exist!";
		}

	}
};

