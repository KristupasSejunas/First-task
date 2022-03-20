#include "Generavimas.h"

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