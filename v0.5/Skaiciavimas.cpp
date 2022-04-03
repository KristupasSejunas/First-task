#include "Skaiciavimas.h"

double Vidurkis(vector<int> paz)
{
	double suma = 0;
	if (paz.size() == 0)
		return 0;
	for (int i = 0; i < paz.size(); i++)
	{
		suma += paz[i];
	}
	suma /= paz.size() * 1.0;
	return suma;
}
double Mediana(vector<int> paz)
{
	if (paz.size() == 0)
	{
		return 0;
	}
	sort(paz.begin(), paz.end());
	if (paz.size() % 2 != 0)
	{
		return paz[paz.size() / 2];
	}
	else
	{
		double ats = paz[paz.size() / 2] + paz[paz.size() / 2 - 1];
		return ats / 2.0;
	}
}

void skaiciavimas(vector<data>& sarasas, int arVM)
{
	for (auto& el : sarasas) //is skaidriu
	{
		if (arVM == 1)
		{
			el.result = Vidurkis(el.paz);
		}
		else
		{
			el.result = Mediana(el.paz);
		}
	}
}