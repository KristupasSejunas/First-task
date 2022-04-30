#include "rusiavimas.h"

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
	return a.result > b.result;
}
void studentu_skirtymas(vector<data>& sarasas, vector<data>& pirmunai, vector<data>& nuskriaustieji)
{
	sort(sarasas.begin(), sarasas.end(), pagal_pazymi);

	auto x = std::chrono::high_resolution_clock::now();
	vector<data> ::iterator it = sarasas.end();
	it--;
	for (int i = sarasas.size() - 1; i > 0; i--)
	{
		if (it->result < 5)
		{
			nuskriaustieji.push_back(*it);
			sarasas.resize(sarasas.size());
		}
		it--;
	}	
	pirmunai = sarasas;	
	sarasas.clear();
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - x;
	cout << "Studentu dalinimas uztruko: " << diff.count() << " s" << endl;

}
void studentu_skirtymas(list<data>& sarasas, list<data>& pirmunai, list<data>& nuskriaustieji)
{
	sarasas.sort(pagal_pazymi);
	auto x = std::chrono::high_resolution_clock::now();

	list<data> ::iterator it = sarasas.end();
	it--;

	for (auto i = sarasas.size() - 1; i > 0; i--)
	{
		//advance(it, i);
		if (it->result >= 5)
		{
			pirmunai.push_back(*it);
		}
		it--;
	}
	sarasas.resize(sarasas.size() - pirmunai.size());
	nuskriaustieji = sarasas;
	sarasas.clear();
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - x;
	cout << "Studentu dalinimas uztruko: " << diff.count() << " s" << endl;
}
void studentu_skirtymas(deque<data>& sarasas, deque<data>& pirmunai, deque<data>& nuskriaustieji)
{
	sort(sarasas.begin(), sarasas.end(), pagal_pazymi);
	auto x = std::chrono::high_resolution_clock::now();
	deque<data> ::iterator it = sarasas.end();
	it--;
	for (auto i = sarasas.size() - 1; i > 0; i--)
	{
		if (it->result < 5)
		{
			nuskriaustieji.push_back(*it);
			sarasas.resize(sarasas.size() - 1);
		}
		it--;
	}

	pirmunai = sarasas;
	sarasas.clear();
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - x;
	cout << "Studentu dalinimas uztruko: " << diff.count() << " s" << endl;
}
void studentu_skirtymas_1(deque<data>& sarasas, deque<data>& pirmunai, deque<data>& nuskriaustieji)
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
void studentu_skirtymas_1(list<data>& sarasas, list<data>& pirmunai, list<data>& nuskriaustieji)
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
void studentu_skirtymas_1(vector<data>& sarasas, vector<data>& pirmunai, vector<data>& nuskriaustieji)
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