#pragma once

#include "data.h"
#include "Validacija.h"
#include "Generavimas.h"
#include "Skaiciavimas.h"

void ivestis(data& temp);
string isvestis(data& temp);
string antrasteVidurkis();
string antrasteMediana();

void i_ekrana(list<data> sarasas, int arVM);

void buffer_skaitymas(list<data>& sarasas, string failas, bool arVM);
void buffer_rasymas(list<data>& sarasas, string failas, int arVM);
//void string_spaudinimas(string failas, std::stringstream& tekstas, bool arVM);