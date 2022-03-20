#include "Rusiavimas.h"

bool pagal_varda(data a, data b)
{
	return a.vardas < b.vardas;
}
bool pagal_pavarde(data a, data b)
{
	return a.pavarde < b.pavarde;
}
void studentu_skirtymas(vector<data>& sarasas, std::stringstream& pirmunai, std::stringstream& nuskriaustieji)
{
	auto x = std::chrono::high_resolution_clock::now();
	for (auto& s : sarasas)
	{
		if (s.result < 5)
		{
			nuskriaustieji << std::setiosflags(std::ios_base::left) << std::setw(20) << s.vardas <<
				std::setiosflags(std::ios_base::left) << std::setw(20) << s.pavarde <<
				std::setiosflags(std::ios_base::left) << std::setw(20) << s.result << std::endl;
		}
		else
		{
			pirmunai << std::setiosflags(std::ios_base::left) << std::setw(20) << s.vardas <<
				std::setiosflags(std::ios_base::left) << std::setw(20) << s.pavarde <<
				std::setiosflags(std::ios_base::left) << std::setw(20) << s.result << std::endl;
		}
	}
	sarasas.clear();	
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - x;
	cout << "Studentu dalinimas uztruko: " << diff.count() << " s" << std::endl;
}