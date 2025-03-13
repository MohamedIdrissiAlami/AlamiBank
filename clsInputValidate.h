#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:

	template <typename T>
	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	template <typename T>
	static T ReadNumber(string Message="", string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number=0;
		cout << Message;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	template <typename T>
	static T ReadNumberBetween(T From, T To,string Message="", string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = 0;
		do
		{
			if (!IsNumberBetween<T>((Number= ReadNumber<T>(Message)), From, To))
				cout << ErrorMessage;
		} while (!IsNumberBetween<T>(Number, From, To));
		return Number;
	}

	template <typename T>
	static T ReadPositiveNumber(string Message = "")
	{
		T Number = 0;
		do
		{
			if ((Number = ReadNumber<T>(Message)) < 0)
				cout << "\nTry again with a positive number..";
		} while (Number<0);
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static string ReadString(string Message = "")
	{
		cout << Message;
		string S1;
		getline(cin >> ws, S1);
		return S1;
	}
	
	static char ReadChar(string Message = "")
	{
		cout << Message;
		char Ch = ' ';
		cin >> Ch;
		return Ch;
	}
};

