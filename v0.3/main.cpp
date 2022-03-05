#include "data.h"
#include "Validacija.h"
#include "Input_Output.h"
#include "Skaiciavimai.h"
#include "Rusiavimas.h"


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

