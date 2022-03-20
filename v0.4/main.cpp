#include "data.h"
#include "Validacija.h"
#include "Input_Output.h"
#include "Skaiciavimas.h"
#include "Rusiavimas.h"


int main()
{
	auto Start = std::chrono::high_resolution_clock::now();
	vector<data> sarasas;
	string failo_pav="";

	cout << "Jeigu norite generuoti faila spauskite 1, jei ne, spauskite 0: ";
	bool FGen = vienas_nulis();
	bool r;
	cout << "Jei norite galutini pazymi skaiciuoti su vidurkiu spauskite 1, jei su mediana spauskite 0: ";
	int arVM = vienas_nulis();
	cout << "Jei norite rusiuoti pagal varda spauskite 1, jeigu pagal pavarde spauskite 0: ";
	bool VP = vienas_nulis();

	if (FGen)
	{
		cin.ignore();
		cout << "Failo pavadinimas: ";
		getline(cin, failo_pav);
		if (failo_pav.empty())
			failo_pav = "studentai.txt";
		cout << "Kiek studentu generuoti: ";
		int studSk = kintamojo_tipas();
		cout << "Kiek namu darbu generuoti: ";
		int ndSk = kintamojo_tipas();
		naujas_failas(failo_pav, studSk, ndSk);
		r = false;
	}
	else
	{
		cout << "Jei norite duomenis rasyti ranka spauskite 1, jei skaityti is failo spauskite 0: ";
		r = vienas_nulis();
		failo_pav = "studentai.txt";
	}


	if (r == false)
	{
		buffer_skaitymas(sarasas, failo_pav);
		if (VP)
			sort(sarasas.begin(), sarasas.end(), pagal_varda);
		else
			sort(sarasas.begin(), sarasas.end(), pagal_pavarde);
		skaiciavimas(sarasas, arVM);
		std::stringstream pirmunai;
		std::stringstream nuskriaustieji;
		studentu_skirtymas(sarasas, pirmunai, nuskriaustieji);

		auto rus = std::chrono::high_resolution_clock::now();
		string_spaudinimas("pirmunai.txt", pirmunai, arVM);
		string_spaudinimas("nuskriaustieji.txt", nuskriaustieji, arVM);
		std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - rus;
		cout << "Spausdinimas i du failus uztruko: " << diff.count() << " s" << std::endl;

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
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - Start;
	cout << "Visos programos veikimo laikas: " << diff.count() << " s" << std::endl;;

	system("pause");
}

