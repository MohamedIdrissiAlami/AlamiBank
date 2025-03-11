#pragma once
#include <iomanip>
#include "clsString.h"
#include "clsInputValidate.h";
#include "clsUtil.h"
#include "clsDate.h";
class clsScreen
{
protected:
	static void DrawScreenHeader(string Title ,string SubTitle="")
	{
		cout <<"\n"<< setw(35) << "" << "************************************************************";//60
		cout << "\n" << setw(36) << "*" << setw(25) << "" << Title; ;
		cout << "\n" <<setw(36)<<"*" <<setw(25) << "\t" << SubTitle;;
		cout <<"\n"<< setw(35) << "" << "************************************************************";//60
	}
};

