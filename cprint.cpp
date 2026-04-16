#include <iostream>
#include <windows.h>
#include <variant>

using namespace std;

// {g 8 | 0 / y 6 | 1 / r 4 | 2}

void setColor(int textColor, int bgColor = 0)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, textColor | (bgColor << 4));
}

void cprint(variant<int, string, char, double, float> value, variant<int, string, char, double, float> tag, const int& level)
{
	switch (level)
	{
		case 0:
			visit([](const auto& v, const auto& t)
			{
				setColor(8);
				cout << v << " " << t << endl;
				setColor(0);
			}, tag, value);
			break;

		case 1:
			visit([](const auto& v, const auto& t)
			{
				setColor(6);
				cout << v << " " << t << endl;
				setColor(0);
			}, tag, value);
			break;

		case 2:
			visit([](const auto& v, const auto& t)
			{
				setColor(4);
				cout << v << " " << t << endl;
				setColor(0);
			}, tag, value);
			break;

		default:
			throw invalid_argument("Wrong argument: level");
	}
}