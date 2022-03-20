#include "data.h"
#include "Validacija.h"
#include "Input_Output.h"
#include "Skaiciavimai.h"
#include "Rusiavimas.h"


int main()
{
	vector<data> sarasas;
	string failo_pav="..\\";

	string duomenys = "..\\studentai.txt";
	string rezultatai = "..\\kursiokai.txt";

	cout << "Jeigu norite generuoti faila spauskite 1, jei ne, spauskite 0: ";
	bool FGen = vienas_nulis();
	string temporary;
	if (FGen)
	{
		cin.ignore();
		cout << "Failo pavadinimas: ";
		getline(cin, temporary);
		temporary.empty() ? failo_pav = "..\\studentai.txt" : failo_pav += temporary + ".txt";
		cout << "Kiek studentu generuoti: ";
		int studSk = kintamojo_tipas();
		cout << "Kiek namu darbu generuoti: ";
		int ndSk = kintamojo_tipas();
		naujas_failas(failo_pav, studSk, ndSk);
	}

	cout << "Jei norite duomenis rasyti ranka spauskite 1, jei skaityti is failo spauskite 0: ";
	bool r = vienas_nulis();
	cout << "Jei norite galutini pazymi skaiciuoti su vidurkiu spauskite 1, jei su mediana spauskite 0: ";
	int arVM = vienas_nulis();
	cout << "Jei norite rusiuoti pagal varda spauskite 1, jeigu pagal pavarde spauskite 0: ";
	bool VP = vienas_nulis();

	if (r == false)
	{
		buffer_skaitymas(sarasas, duomenys);
		if (VP)
			sort(sarasas.begin(), sarasas.end(), pagal_varda);
		else
			sort(sarasas.begin(), sarasas.end(), pagal_pavarde);
		skaiciavimas(sarasas, arVM);
		buffer_rasymas(sarasas, rezultatai, arVM);
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

