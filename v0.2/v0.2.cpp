#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm> //sort
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct data {
	string vardas;
	string pavarde;
	int egz;
	vector<int> paz;
	double result = 0;
};

void ivestis(data& temp);
void isvestis(data& temp);
void antrasteVidurkis();
void antrasteMediana();
double Vidurkis(vector<int> paz);
double Mediana(vector<int> paz);

//validacija
bool desimtbale(int n);
int kintamojo_tipas();
bool vienas_nulis();

//random
int skaicius();
void random_paz(int k, data& temp);


int main()
{

	vector<data> sarasas;

	while (true)
	{
		cout << "Jei norite ivesti studento duomenis spauskite 1, jei baigete pildyti studentu sarasa spauskite 0: ";
		bool ar = vienas_nulis();
		if (ar == false)
			break;
		else
		{
			data T;
			ivestis(T);
			sarasas.push_back(T);
		}
	}

	cout << "Jei norite galutini pazymi skaiciuoti su vidurkiu spauskite 1, jei su mediana spauskite 0: ";
	int arVM = vienas_nulis();

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

	if (arVM == 1)
		antrasteVidurkis();
	else
		antrasteMediana();
	for (int i = 0; i < sarasas.size(); i++)
	{
		isvestis(sarasas[i]);
	}

	system("pause");
}
void ivestis(data& temp)
{
	bool pasirinkimas;
	int p;
	cout << "Iveskite studento varda: ";
	cin >> temp.vardas;
	cout << "Iveskite studento pavarde: ";
	cin >> temp.pavarde;

	cout << "Jei norite namu darbu ivertinimus generuoti automatiskai spauskite 1, jei pazymius vesite ranka spauskite 0: " << std::endl;
	pasirinkimas = vienas_nulis();
	if (pasirinkimas)
	{
		cout << "Kiek ivertinimu norite sugeneruoti? " << std::endl;
		p = kintamojo_tipas();
		random_paz(p, temp);
	}
	else
	{
		cout << "Iveskite namu darbu ivertinimus (Ivedus visus duomenis spauskite 0): " << std::endl;

		while (true)
		{
			p = kintamojo_tipas();
			if (p == 0)
				break;
			else if (desimtbale(p))
			{
				temp.paz.push_back(p);
			}
		}
	}

	cout << "Jei norite egzamino ivertinima generuoti automatiskai spauskite 1, jei pazymi vesite ranka spauskite 0: " << std::endl;
	pasirinkimas = vienas_nulis();
	if (pasirinkimas)
	{
		temp.egz = skaicius();
	}
	else
	{
		cout << "Iveskite egzamino ivertinima: ";
		while (true)
		{
			p = kintamojo_tipas();
			if (desimtbale(p))
			{
				temp.egz = p;
				break;
			}
		}
	}

}
void isvestis(data& temp)
{
	cout << std::left << std::setw(15) << temp.pavarde <<
		std::left << std::setw(15) << temp.vardas <<
		std::left << std::setw(15) << std::fixed << std::setprecision(2) << 0.4 * temp.result + 0.6 * temp.egz << std::endl;
}
void antrasteVidurkis()
{

	cout << std::left << std::setw(15) << "Pavarde" <<
		std::left << std::setw(15) << "Vardas" <<
		std::left << std::setw(15) << "Galutinis (Vid.)" << std::endl;
	cout << "--------------------------------------------------" << std::endl;
}
void antrasteMediana()
{
	cout << std::left << std::setw(15) << "Pavarde" <<
		std::left << std::setw(15) << "Vardas" <<
		std::left << std::setw(15) << "Galutinis (Med.)" << std::endl;
	cout << "--------------------------------------------------" << std::endl;
}
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
int skaicius()
{
	unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed1);
	std::uniform_int_distribution<int> dist(1, 10);
	int x = dist(generator);
	return x;
}
void random_paz(int k, data& temp)
{
	int x;
	for (int i = 0; i < k; i++)
	{
		x = skaicius();
		temp.paz.push_back(x);
	}
}