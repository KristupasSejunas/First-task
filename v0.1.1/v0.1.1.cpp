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
	double rezult = 0;
};

void ivestis(data& temp);
void isvestis(data& temp);
void antraste();
bool studentu_patikra();
double Vidurkis(int* paz);
double galutinis_vidurkis(data& temp);

int main()
{	
	data* sarasas = nullptr;
	int Kiek = 0;

	while (true)
	{
		cout << "Jei norite ivesti studento duomenis spauskite 1, jei baigete pildyti studentu sarasa spauskite 0: ";
		bool ar = studentu_patikra();
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
	antraste();
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
		std::left << std::setw(15) << std::fixed << std::setprecision(2) << galutinis_vidurkis(temp) << std::endl;
}

void antraste()
{

	cout << std::left << std::setw(15) << "Pavarde" <<
		std::left << std::setw(15) << "Vardas" <<
		std::left << std::setw(15) << "Galutinis (Vid.)" << std::endl;
	cout <<  "--------------------------------------------------" << std::endl;
}

bool studentu_patikra()
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

double galutinis_vidurkis(data& temp)
{
	return 0.4 * Vidurkis(temp.paz) + 0.6 * temp.egz;
}