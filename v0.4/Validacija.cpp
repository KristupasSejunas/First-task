#include "Validacija.h"

bool desimtbale(int n)
{
	if (n >= 1 && n <= 10)
	{
		return true;
	}
	else
	{
		cout << "Skaicius turi buti nuo 1 iki 10 (imtinai)." << std::endl;
		return false;
	}
}
int kintamojo_tipas()
{
	int x;
	while (true)
	{
		cin >> x;
		if (!cin.good())
		{
			cout << "Iveskite sveikaji skaiciu." << std::endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n'); //isvalo buffer'i
		}
		else
		{
			return x;
		}
	}
}
bool vienas_nulis()
{
	int x;
	while (true)
	{
		x = kintamojo_tipas();
		if (x == 0 || x == 1)
		{
			return x;
		}
		else
		{
			cout << "Iveskite 1 arba 0" << std::endl;
		}
	}
}