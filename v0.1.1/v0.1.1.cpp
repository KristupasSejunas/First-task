#include <iostream>
#include <string>
#include <iomanip>


using std::cout;
using std::cin;
using std::string;


struct data {
	string vardas;
	string pavarde;
	int n = 0;
	int egz;
	int paz[3] = { 0 };
	double result = 0;
};

void ivestis(data& temp);
void isvestis(data& temp);
void antrasteVidurkis();
void antrasteMediana();
bool patikra();
double Vidurkis(int* paz);
void rikiavimas(int* paz);
double Mediana(int* paz);

int main()
{	
	data* sarasas = nullptr;
	int Kiek = 0;

	while (true)
	{
		cout << "Jei norite ivesti studento duomenis spauskite 1, jei baigete pildyti studentu sarasa spauskite 0: ";
		bool ar = patikra();
		if (ar==false)
			break;
		else
		{
			Kiek++;
			data T;
			ivestis(T);

			data* temp = new data[Kiek - 1];
			for (int i = 0; i < Kiek - 1; i++)
			{
				temp[i] = sarasas[i];
			}
			delete[] sarasas;

			sarasas = new data[Kiek];
			for (int i = 0; i < Kiek - 1; i++)
			{
				sarasas[i] = temp[i];
			}
			sarasas[Kiek - 1] = T;
			delete[] temp;
		}
	}

	cout << "Jei norite galutini pazymi skaiciuoti su vidurkiu spauskite 1, jei su mediana spauskite 0: ";
	int arVM = patikra();

	for (data* i = sarasas; i < sarasas + Kiek; i++)
	{
		if (arVM == 1)
		{
			i->result = Vidurkis(i->paz);
		}
		else 
		{
			i->result = Mediana(i->paz);
		}

	}

	if (arVM == 1)
		antrasteVidurkis();
	else
		antrasteMediana();
	for (int i = 0; i < Kiek; i++)
	{
		isvestis(sarasas[i]);
	}

	delete[] sarasas;
	system("pause");
}

void ivestis(data& temp)
{
	int n = 3;
	cout << "Iveskite studento varda: ";
	cin >> temp.vardas;
	cout << "Iveskite studento pavarde: ";
	cin >> temp.pavarde;
	for (int i = 0; i < n; i++)
	{
		cout << "Iveskite " << i + 1 << "-a(-i) namu darbu pazymi: ";
		cin >> temp.paz[i];
	}
	cout << "Iveskite egzamino ivertinima: ";
	cin >> temp.egz;
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
	cout <<  "--------------------------------------------------" << std::endl;
}
void antrasteMediana()
{
	cout << std::left << std::setw(15) << "Pavarde" <<
		std::left << std::setw(15) << "Vardas" <<
		std::left << std::setw(15) << "Galutinis (Med.)" << std::endl;
	cout << "--------------------------------------------------" << std::endl;
}

bool patikra()
{
	int x;
	cin >> x;
	return x;
}

double Vidurkis(int* paz)
{
	double suma = 0;
	for (int i = 0; i < 3; i++)
	{
		suma += paz[i];
	}
	return suma / 3.0;
}

void rikiavimas(int* paz)
{
	int i = 0;
	bool ar = true;
	while (ar)
	{
		ar = false;
		for (int j = 2; j > i; j--)
		{
			if (paz[j] <= paz[j - 1])
			{
				ar = true;
				int temp = paz[j];
				paz[j] = paz[j - 1];
				paz[j - 1] = temp;
			}
		}
		i++;
	}
}

double Mediana(int* paz)
{
	rikiavimas(paz);
	return paz[1];
}
