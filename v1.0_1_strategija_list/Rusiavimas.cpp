#include "Rusiavimas.h"

bool pagal_varda(data a, data b)
{
	return a.vardas < b.vardas;
}
bool pagal_pavarde(data a, data b)
{
	return a.pavarde < b.pavarde;
}
bool pagal_pazymi(data a, data b)
{
	return a.result < b.result;
}
void studentu_skirtymas(list<data>& sarasas, list<data>& pirmunai, list<data>& nuskriaustieji)
{	
	auto x = std::chrono::high_resolution_clock::now();
	for (auto& s : sarasas)
	{
		if (s.result < 5)
		{
			nuskriaustieji.push_back(s);
		}
		else
		{
			pirmunai.push_back(s);
		}
	}
	sarasas.clear();
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - x;
	cout << "Studentu dalinimas uztruko: " << diff.count() << " s" << endl;
}