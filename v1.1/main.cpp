#include "data.h"
#include "validacija.h"
#include "inout.h"
#include "skaic.h"
#include "rusiavimas.h"


int main()
{
	string failo_pav = "";
	bool testi = true;

	while (testi)
	{	
		auto Start = std::chrono::high_resolution_clock::now();		

		cout << "Jeigu norite vykdyti programa spauskite 1, jei ne, spauskite 0: ";
		testi = vienas_nulis();
		if (!testi)
			break;		
		cout << "Kokio tipo turetu buti sarasas? 0-vector/1-list/2-deque: ";
		int tipas = tipo_patikra();
		cout << "Kokia strategija naudoti? 0-Pirma strategija/1-Antra strategija: ";
		int strategija = vienas_nulis();
		cout << "Jeigu norite generuoti faila spauskite 1, jei ne, spauskite 0: ";
		bool FGen = vienas_nulis();
		bool r;
		int arVM;
		bool VP;

		if (FGen)
		{
			cin.ignore();
			cout << "Failo pavadinimas: ";
			getline(cin, failo_pav);
			failo_pav.empty() ? failo_pav = "studentai.txt" : failo_pav += ".txt";
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
			cin.ignore();
			cout << "Iveskite failo pavadinima: ";
			getline(cin, failo_pav);
			failo_pav.empty() ? failo_pav = "studentai.txt" : failo_pav += ".txt";
		}

		if (r == false)
		{
			cout << "Jei norite rusiuoti pagal varda spauskite 1, jeigu pagal pavarde spauskite 0: ";
			VP = vienas_nulis();

			cout << "Jei norite galutini pazymi skaiciuoti su vidurkiu spauskite 1, jei su mediana spauskite 0: ";
			arVM = vienas_nulis();
			if (tipas == 0)
			{
				vector<data> sarasas;
				buffer_skaitymas(sarasas, failo_pav);
				skaiciavimas(sarasas, arVM);
				vector<data> pirmunai;
				vector<data> nuskriaustieji;
				if(strategija)
					studentu_skirtymas(sarasas, pirmunai, nuskriaustieji);
				else
					studentu_skirtymas_1(sarasas, pirmunai, nuskriaustieji);
				if (VP)
				{
					sort(pirmunai.begin(), pirmunai.end(), pagal_varda);
					sort(nuskriaustieji.begin(), nuskriaustieji.end(), pagal_varda);
				}
				else
				{
					sort(pirmunai.begin(), pirmunai.end(), pagal_pavarde);
					sort(nuskriaustieji.begin(), nuskriaustieji.end(), pagal_pavarde);
				}

				auto rus = std::chrono::high_resolution_clock::now();
				buffer_rasymas(pirmunai, "pirmunai.txt", arVM);
				buffer_rasymas(nuskriaustieji, "nuskriaustieji.txt", arVM);
				std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - rus;
				cout << "Studentu spausdinimas i du failus uztruko: " << diff.count() << " s" << endl;
			}
			else if (tipas == 1)
			{
				list<data> sarasas;
				buffer_skaitymas(sarasas, failo_pav, arVM);

				skaiciavimas(sarasas, arVM);
				list<data> pirmunai;
				list<data> nuskriaustieji;
				if(strategija)
					studentu_skirtymas(sarasas, pirmunai, nuskriaustieji);
				else
					studentu_skirtymas_1(sarasas, pirmunai, nuskriaustieji);
				if (VP)
				{
					pirmunai.sort(pagal_varda);
					nuskriaustieji.sort(pagal_varda);
				}
				else
				{
					pirmunai.sort(pagal_pavarde);
					nuskriaustieji.sort(pagal_pavarde);
				}

				auto rus = std::chrono::high_resolution_clock::now();
				buffer_rasymas(pirmunai, "pirmunai.txt", arVM);
				buffer_rasymas(nuskriaustieji, "nuskriaustieji.txt", arVM);
				std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - rus;
				cout << "Studentu spausdinimas i du failus uztruko: " << diff.count() << " s" << endl;
			}
			else if (tipas == 2)
			{
				deque<data> sarasas;
				buffer_skaitymas(sarasas, failo_pav);

				skaiciavimas(sarasas, arVM);
				deque<data> pirmunai;
				deque<data> nuskriaustieji;
				if(strategija)
					studentu_skirtymas(sarasas, pirmunai, nuskriaustieji);
				else
					studentu_skirtymas_1(sarasas, pirmunai, nuskriaustieji);

				if (VP)
				{
					sort(pirmunai.begin(), pirmunai.end(), pagal_varda);
					sort(nuskriaustieji.begin(), nuskriaustieji.end(), pagal_varda);
				}
				else
				{
					sort(pirmunai.begin(), pirmunai.end(), pagal_pavarde);
					sort(nuskriaustieji.begin(), nuskriaustieji.end(), pagal_pavarde);
				}

				auto rus = std::chrono::high_resolution_clock::now();
				buffer_rasymas(pirmunai, "pirmunai.txt", arVM);
				buffer_rasymas(nuskriaustieji, "nuskriaustieji.txt", arVM);
				std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - rus;
				cout << "Studentu spausdinimas i du failus uztruko: " << diff.count() << " s" << endl;
			}
		}
		else
		{
			vector<data>sarasas;
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
			cout << "Jei norite rusiuoti pagal varda spauskite 1, jeigu pagal pavarde spauskite 0: ";
			VP = vienas_nulis();
			cout << "Jei norite galutini pazymi skaiciuoti su vidurkiu spauskite 1, jei su mediana spauskite 0: ";
			arVM = vienas_nulis();

			if (VP)
				sort(sarasas.begin(), sarasas.end(), pagal_varda);
			else
				sort(sarasas.begin(), sarasas.end(), pagal_pavarde);
			skaiciavimas(sarasas, arVM);
			i_ekrana(sarasas, arVM);
			sarasas.clear();
		}

		std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - Start;
		cout << "Visos programos veikimo laikas: " << diff.count() << " s" << endl;
		system("pause");
	}

}

