#pragma once

#include "data.h"
#include "validacija.h"
#include "generavimas.h"
#include "skaic.h"

void ivestis(data& temp);
string isvestis(data& temp);
string antrasteVidurkis();
string antrasteMediana();

void i_ekrana(vector<data> sarasas, int arVM);
void i_ekrana(list<data> sarasas, int arVM);

void buffer_skaitymas(vector<data>& sarasas, string failas);
void buffer_rasymas(vector<data>& sarasas, string failas, int arVM);
//void string_spaudinimas(string failas, std::stringstream& tekstas, bool arVM);

void buffer_skaitymas(list<data>& sarasas, string failas, bool arVM);
void buffer_rasymas(list<data>& sarasas, string failas, int arVM);

void i_ekrana(deque<data> sarasas, int arVM);

void buffer_skaitymas(deque<data>& sarasas, string failas);
void buffer_rasymas(deque<data>& sarasas, string failas, int arVM);
