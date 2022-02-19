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
	int* paz = nullptr;
	double result = 0;
};

void ivestis(data& temp);
void isvestis(data& temp);
void antrasteVidurkis();
void antrasteMediana();
double Vidurkis(int* paz, int k);
void rikiavimas(int* paz, int k);
double Mediana(int* paz, int k);
void prideti_paz(int p, data& temp);

//validacija
bool desimtbale(int n);
int kintamojo_tipas();
bool vienas_nulis();

//random
int skaicius();
void random_paz(int k, data& temp);

int main()
{	
	srand(time(NULL));

	data* sarasas = nullptr;
	int Kiek = 0;

	while (true)
	{
		cout << "Jei norite ivesti studento duomenis spauskite 1, jei baigete pildyti studentu sarasa spauskite 0: ";
		bool ar = vienas_nulis();
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
	int arVM = vienas_nulis();

	for (data* i = sarasas; i < sarasas + Kiek; i++)
	{
		if (arVM == 1)
		{
			i->result = Vidurkis(i->paz, i->n);
		}
		else 
		{
			i->result = Mediana(i->paz, i->n);
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
				prideti_paz(p, temp);
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
	cout <<  "--------------------------------------------------" << std::endl;
}
void antrasteMediana()
{
	cout << std::left << std::setw(15) << "Pavarde" <<
		std::left << std::setw(15) << "Vardas" <<
		std::left << std::setw(15) << "Galutinis (Med.)" << std::endl;
	cout << "--------------------------------------------------" << std::endl;
}

double Vidurkis(int* paz, int k)
{
	double suma = 0;
	if (k == 0)
		return 0;
	for (int i = 0; i < k; i++)
	{
		suma += paz[i];
	}
	suma /= k * 1.0;
	return suma;
}
void rikiavimas(int* paz, int k)
{
	int i = 0;
	bool ar = true;
	while (ar)
	{
		ar = false;
		for (int j = k-1; j > i; j--)
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
double Mediana(int* paz, int k)
{
	if (k == 0)
	{
		return 0;
	}
	rikiavimas(paz, k);
	if (k % 2 != 0)
	{
		return paz[k/2];
	}
	else
	{
		double ats = paz[k / 2] + paz[k / 2 - 1];
		return ats / 2.0;
	}
}
void prideti_paz(int p, data& temp)
{
	temp.n++;
	int* x = new int[temp.n];
	for (int i = 0; i < temp.n-1; i++)
	{
		x[i] = temp.paz[i];
	}
	delete[] temp.paz;

	temp.paz = new int[temp.n];
	for (int i = 0; i < temp.n - 1; i++)
	{
		temp.paz[i] = x[i];
	}
	temp.paz[temp.n - 1] = p;
	delete[] x;
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
	int x = rand() % 10 + 1;
	return x;
}
void random_paz(int k, data& temp)
{
	int x;
	for (int i = 0; i < k; i++)
	{
		x = skaicius();
		prideti_paz(x, temp);
	}
}
