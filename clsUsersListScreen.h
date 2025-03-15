#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class clsUsersListScreen:public clsScreen
{

	private:
		static void _PrintUserRecord(clsUser User)
		{
			cout << setw(10) << "";
			cout << "| " << left << setw(17) << User.FirstName;
			cout << "| " << left << setw(17) << User.LastName;
			cout << "| " << left << setw(18) << User.Email;
			cout << "| " << left << setw(10) << User.Phone;
			cout << "| " << left << setw(15) << User.UserName;
			cout << "| " << left << setw(15) << User.Password;
			cout << "| " << left << setw(13) << User.Permissions << "|";
		}
	public:
		static void ShowUsersListScreen()
		{
			//cout << "\nUser lists screen will be here...";
			vector<clsUser>vUsers = clsUser::GetAllAvailableUsers();
			DrawScreenHeader("U S E R (S)   L I S T", "(" + to_string(vUsers.size()) + ") CLIENT(S)");

			cout << "\n\n" << setw(10) << "" << "____________________________________________________________";//60
			cout << "____________________________________________________________\n";//60
			cout << setw(10) << "";
			cout << "| " << left << setw(17) << "FIRST NAME";
			cout << "| " << left << setw(17) << "LAST NAME";
			cout << "| " << left << setw(18) << "EMAIL";
			cout << "| " << left << setw(10) << left << "PHONE";
			cout << "| " << left << setw(15) << left << "USERNAME";
			cout << "| " << left << setw(15) << left << "PASSWORD";
			cout << "| " << left << setw(13) << left << "PERMISSIONS" << "|";
			cout << "\n" << setw(10) << "" << "____________________________________________________________";//60
			cout << "____________________________________________________________\n";//60

			if (!vUsers.empty())
			{
				for (clsUser& User : vUsers)
				{
					cout << endl;
					_PrintUserRecord(User);
				}
			}
			else
				cout << "\n" << setw(90) << right << "N O   A V A I L A B L E  U S E R S";

			cout << "\n" << setw(10) << "" << "____________________________________________________________";//60
			cout << "____________________________________________________________\n";//60
		}
	};


