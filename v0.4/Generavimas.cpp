#include "Generavimas.h"

int skaicius(int nuo, int iki)
{
	unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed1);
	std::uniform_int_distribution<int> dist(nuo, iki);
	int x = dist(generator);
	return x;
}

void random_paz(int k, data& temp)
{
	int x;
	for (int i = 0; i < k; i++)
	{
		x = skaicius(1, 10);
		temp.paz.push_back(x);
	}
}
void naujas_failas(string failo_pav, int studSk, int ndSk)
{

	auto x = std::chrono::high_resolution_clock::now();
	std::stringstream rezultatas;
	rezultatas << naujo_failo_antraste(ndSk);
	for (int i = 0; i < studSk; i++)
	{
		rezultatas << studentas(ndSk);
	}
	std::ofstream out(failo_pav);
	out << rezultatas.rdbuf();
	out.close();	
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - x;
	cout << "Failo generavimas uztruko: " << diff.count() << " s" << std::endl;
}
string naujo_failo_antraste(int ndSk)
{
	std::stringstream temp;
	temp << std::setiosflags(std::ios_base::left) << std::setw(20) << "Vardas" <<
		std::setiosflags(std::ios_base::left) << std::setw(20) << "Pavarde";
	for (int i = 0; i < ndSk; i++)
	{
		temp << std::setiosflags(std::ios_base::left) << "ND" << std::setw(5) << i + 1;
	}
	temp << std::setiosflags(std::ios_base::left) << std::setw(5) << "Egz" << std::endl;
	return temp.str();
}
string studentas(int ndSk)
{
	std::stringstream temp;
	temp << std::setiosflags(std::ios_base::left) << std::setw(20) << Vardenis() <<
		std::setiosflags(std::ios_base::left) << std::setw(20) << Pavardenis();
	for (int i = 0; i < ndSk; i++)
	{
		temp << std::setiosflags(std::ios_base::left) << std::setw(7) << skaicius(1, 10);
	}
	temp << std::setiosflags(std::ios_base::left) << std::setw(7) << skaicius(1, 10) << std::endl;
	return temp.str();
}
string Vardenis()
{
	return Vardas[skaicius(0, Vardas.size() - 1)];
}
string Pavardenis()
{
	return Pavarde[skaicius(0, Pavarde.size() - 1)];
}
