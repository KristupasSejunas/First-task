#include "Input_Output.h"

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
void skaityti(string failas, std::vector<data>& sarasas)
{
	try {
		std::ifstream in(failas);
		if (in)
		{
			int ilgis = kiek_pazymiu(in);
			while (!in.eof())
			{
				int p;
				data temp;
				in >> temp.vardas >> temp.pavarde;
				for (int i = 0; i < ilgis; i++)
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
	catch (const std::exception& e) {
		cout << e.what() << std::endl;
	}

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