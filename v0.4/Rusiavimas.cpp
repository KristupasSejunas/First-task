#include "Rusiavimas.h"

bool pagal_varda(data a, data b)
{
	return a.vardas < b.vardas;
}
bool pagal_pavarde(data a, data b)
{
	return a.pavarde < b.pavarde;
}
void studentu_skirtymas(vector<data>& sarasas, vector<data>& pirmunai, vector<data>& nuskriaustieji)
{
	auto x = std::chrono::high_resolution_clock::now();
	int i = 1;
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
		i++;
	}
	sarasas.clear();	
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - x;
	cout << "Studentu dalinimas uztruko: " << diff.count() << " s" << endl;
}