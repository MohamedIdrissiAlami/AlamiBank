#pragma once
#include <iomanip>
#include "clsString.h"
#include "clsInputValidate.h";
#include "clsUtil.h"
#include "clsDate.h";
#include "Global.h"
class clsScreen
{

private:
	static  void _PrintAccessDeniedMessage()
	{
		DrawScreenHeader("ACCESS DENIED !", "CONTACT YOUR ADMIN");
		cout << "\a";
	}

protected:
	static void DrawScreenHeader(string Title ,string SubTitle="")
	{
		system("cls");
		cout <<"\n"<< setw(35) << "" << "************************************************************";//60
		cout << "\n" << setw(36) << "*" << setw(25) << "" << Title; 
		if (SubTitle != "")
			cout << "\n" << setw(36) << "*" << setw(25) << "\t" << SubTitle;
		cout <<"\n"<< setw(35) << "" << "************************************************************";//60
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermissions(Permission))
		{
			_PrintAccessDeniedMessage();
			return false;
		}
		else
			return true;
	}

};

