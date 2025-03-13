#pragma once
#include "clsScreen.h"
#include "clsClient.h"
class clsClientsListScreen:public clsScreen
{
private:
	static void _PrintClientRecord(clsClient Client)
	{
		cout << setw(10)<<"";
		cout << "| " << left << setw(19) << Client.FirstName;
		cout << "| " << left << setw(19) << Client.LastName;
		cout << "| " << left << setw(19) << Client.Email;
		cout << "| " << left << setw(10) << Client.Phone;
		cout << "| " << left << setw(15) << Client.AccountNumber;
		cout << "| " << left << setw(8) << Client.PinCode;
		cout << "| " << left << setw(15) << Client.AccountBalance << "|";
	}
public:
	static void ShowClientsListScreen()
	{
		//cout << "\nClient lists screen will be here...";
		vector<clsClient>vClients = clsClient::GetAllAvailableClients();
		DrawScreenHeader("C L I E N T (S)   L I S T","("+ to_string(vClients.size()) + ") CLIENT(S)");

		cout << "\n\n" << setw(10) << "" << "____________________________________________________________";//60
		cout << "____________________________________________________________\n";//60
		cout << setw(10)<<"";
		cout << "| " <<left<< setw(19) << "FIRST NAME";
		cout << "| " <<left<< setw(19) << "LAST NAME";
		cout << "| " <<left<< setw(19) << "EMAIL";
		cout << "| " <<left<< setw(10) << left << "PHONE";
		cout << "| " <<left<< setw(15) << left << "ACCOUNT NUMBER";
		cout << "| " <<left<< setw(8) << left << "PIN CODE";
		cout << "| " <<left<< setw(15) << left << "ACCOUNT BALANCE" << "|";
		cout << "\n" << setw(10) << "" << "____________________________________________________________";//60
		cout << "____________________________________________________________\n";//60

		if (!vClients.empty())
		{
			for (clsClient& Client : vClients)
			{
				cout << endl;
				_PrintClientRecord(Client);
			}
		}
		else
			cout << "\n" << setw(90) << right << "N O   A V A I L A B L E  C L I E N T S";

		cout << "\n" << setw(10) << "" << "____________________________________________________________";//60
		cout << "____________________________________________________________\n";//60
	}
};

