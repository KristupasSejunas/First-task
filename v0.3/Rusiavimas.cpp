#include "Rusiavimas.h"

bool pagal_varda(data a, data b)
{
	return a.vardas < b.vardas;
}
bool pagal_pavarde(data a, data b)
{
	return a.pavarde < b.pavarde;
}