#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm> //sort
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>

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
string isvestis(data& temp);
string antrasteVidurkis();
string antrasteMediana();
double Vidurkis(vector<int> paz);
double Mediana(vector<int> paz);
void skaiciavimas(vector<data>& sarasas, int arVM);

//validacija
bool desimtbale(int n);
int kintamojo_tipas();
bool vienas_nulis();

//random
int skaicius();
void random_paz(int k, data& temp);

//darbas su failu
void skaityti(string failas, vector<data>& sarasas);
int kiek_pazymiu(std::ifstream& in);

//spausdinimas
void i_ekrana(vector<data> sarasas, int arVM);
void i_faila(vector<data> sarasas, int arVM, string failas);

//rusiavimas
bool pagal_varda(data a, data b);
bool pagal_pavarde(data a, data b);

int main()
{
	vector<data> sarasas;
	string duomenys = "..\\studentai.txt";
	string rezultatai = "..\\kursiokai.txt";

	cout << "Jei norite duomenis rasyti ranka spauskite 1, jei skaityti is failo spauskite 0: ";
	bool r = vienas_nulis();	
	cout << "Jei norite galutini pazymi skaiciuoti su vidurkiu spauskite 1, jei su mediana spauskite 0: ";
	int arVM = vienas_nulis();
	cout << "Jei norite rusiuoti pagal varda spauskite 1, jeigu pagal pavarde spauskite 0: ";
	bool VP = vienas_nulis();

	if (r == false)
	{
		skaityti(duomenys, sarasas);
		if (VP)
			sort(sarasas.begin(), sarasas.end(), pagal_varda);
		else
			sort(sarasas.begin(), sarasas.end(), pagal_pavarde);
		skaiciavimas(sarasas, arVM);
		i_faila(sarasas, arVM, rezultatai);
	}
	else
	{
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
		if (VP)
			sort(sarasas.begin(), sarasas.end(), pagal_varda);
		else
			sort(sarasas.begin(), sarasas.end(), pagal_pavarde);
		skaiciavimas(sarasas, arVM);
		i_ekrana(sarasas, arVM);
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
string isvestis(data& temp)
{
	std::stringstream x;
	double sk = 0.40 * temp.result + 0.60 * temp.egz;
	x << std::setiosflags(std::ios_base::left) << std::setw(20) << temp.vardas <<
		std::setiosflags(std::ios_base::left) << std::setw(20) << temp.pavarde <<
		std::setiosflags(std::ios_base::left) << std::setw(20) << std::fixed << std::setprecision(2) << sk << std::endl;
	return x.str();
}
string antrasteVidurkis()
{
	std::stringstream temp;
	temp << std::setiosflags(std::ios_base::left) << std::setw(20) << "Vardas" <<
		std::setiosflags(std::ios_base::left) << std::setw(20) << "Pavarde" <<
		std::setiosflags(std::ios_base::left) << std::setw(20) << "Galutinis (Vid.)" << 
		std::endl << "----------------------------------------------------------" << std::endl;
	return temp.str();
}
string antrasteMediana()
{
	std::stringstream temp;
	temp << std::setiosflags(std::ios_base::left) << std::setw(20) << "Vardas" <<
		std::setiosflags(std::ios_base::left) << std::setw(20) << "Pavarde" <<
		std::setiosflags(std::ios_base::left) << std::setw(20) << "Galutinis (Med.)" <<
		std::endl << "----------------------------------------------------------" << std::endl;
	return temp.str();
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
void skaityti(string failas, std::vector<data>& sarasas)
{
	std::ifstream in(failas);
	if (in)
	{
		int ilgis = kiek_pazymiu(in);
		while (!in.eof())
		{
			int p;
			data temp;
			in >> temp.vardas >> temp.pavarde;
			for (int i=0; i<ilgis; i++)
			{
				in >> p;
				temp.paz.push_back(p);
			}
			in >> temp.egz;
			sarasas.push_back(temp);
		}
	}
	in.close();
}
int kiek_pazymiu(std::ifstream& in)
{
	int ats = 0;
	string t;
	while ((in.peek() != '\n') && (in >> t))
		ats++;
	return ats - 3;
}
void i_ekrana(vector<data> sarasas, int arVM) 
{
	if (arVM == 1)
		cout << antrasteVidurkis();
	else
		cout << antrasteMediana();
	for (int i = 0; i < sarasas.size(); i++)
	{
		cout << isvestis(sarasas[i]);
	}
}
void i_faila(vector<data> sarasas, int arVM, string failas)
{
	std::ofstream out(failas);
	if (arVM == 1)
		out << antrasteVidurkis();
	else
		out << antrasteMediana();
	for (auto& el : sarasas)
	{
		out << isvestis(el);
	}
	out.close();
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
bool pagal_varda(data a, data b)
{
	return a.vardas < b.vardas;
}
bool pagal_pavarde(data a, data b)
{
	return a.pavarde < b.pavarde;
}