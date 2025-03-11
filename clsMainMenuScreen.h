#pragma once
#include "clsScreen.h"
class clsMainMenuScreen :public clsScreen
{

public :
	static void ShowMainMenuScreen()
	{
		clsScreen::DrawScreenHeader("M A I N  M E N U","SCREEN");
		cout << "\n\n"   << setw(35) << "" << "*\tS H O W   C L I E N T   L I S T";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tA D D  N E W  C L I E N T(S)";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tF I N D  C L I E N T";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tD E L E T  C L I E N T";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tU P D A T E  C L I E N T";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tT R A N S A C T I O N S  M E N U";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tMA N A G E  U S E R S  M E N U";//60
		cout << "\n\n\n" << setw(35) << "" << "*\tC U R R E N C Y  E X C H A N G E  M E N U";//60
		cout << "\n\n" << setw(35) << "" << "************************************************************";//60



	}

};

