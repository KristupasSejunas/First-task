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
void studentu_skirtymas(deque<data>& sarasas, deque<data>& pirmunai, deque<data>& nuskriaustieji)
{
	sort(pirmunai.begin(), pirmunai.end(), pagal_pazymi);
	auto x = std::chrono::high_resolution_clock::now();
	deque<data> ::iterator it = sarasas.end();
	it--;
	for (auto i = sarasas.size() - 1; i > 0; i--)
	{
		if (it->result >= 5)
			pirmunai.push_back(*it);
		it--;
	}
	sarasas.resize(sarasas.size() - pirmunai.size());
	nuskriaustieji = sarasas;
	sarasas.clear();	
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - x;
	cout << "Studentu dalinimas uztruko: " << diff.count() << " s" << endl;
}