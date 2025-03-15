#pragma once
#include "clsUser.h"
#include "Global.h"
#include "clsMainMenuScreen.h"
class clsLoginScreen:clsScreen
{
	public:
		static void ShowLoginScreen()
		{
			clsScreen::DrawScreenHeader("L O G I N   S C R E E N");
			cout << "\n\nPLEASE LOGIN \n\tYOU HAVE (3) TRAILS : ";
			cout << "\n\n\tUSERNAME : ";
			string UserName = clsInputValidate::ReadString();
			cout << "\n\tPASSWORD   : ";
			string Password = clsInputValidate::ReadString();

			short Counter = 3;
			while (Counter > 1)
			{
				CurrentUser = clsUser::Find(UserName, Password);
				if (CurrentUser.IsUserExist())
				{
					//CurrentUser.RegisterLogin();
					clsMainMenuScreen::ShowMainMenuScreen();
					return;
				}
				else
				{
					cout << "\nWrong UserName/Password!";
					cout << "\nattempts left : " << --Counter;
					cout << "\n\n\tUSERNAME : ";
					UserName = clsInputValidate::ReadString();
					cout << "\n\tPASSWORD   : ";
					Password = clsInputValidate::ReadString();

				}
			}
			cout << "\n\nLOCKED AFTER 3 FAILD TRIALS ,GO BACK LATER.";
		}
	};

