#pragma once

#include "data.h"
#include "Validacija.h"
#include "Generavimas.h"

void ivestis(data& temp);
string isvestis(data& temp);
string antrasteVidurkis();
string antrasteMediana();

void i_ekrana(vector<data> sarasas, int arVM);

void buffer_skaitymas(vector<data>& sarasas, string failas);
void buffer_rasymas(vector<data>& sarasas, string failas, int arVM);
//void string_spaudinimas(string failas, std::stringstream& tekstas, bool arVM);