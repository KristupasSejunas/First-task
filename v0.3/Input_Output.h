#pragma once

#include "data.h"
#include "Validacija.h"
#include "Generavimas.h"

void ivestis(data& temp);
string isvestis(data& temp);
string antrasteVidurkis();
string antrasteMediana();

void skaityti(string failas, vector<data>& sarasas);
int kiek_pazymiu(std::ifstream& in);

void i_ekrana(vector<data> sarasas, int arVM);
void i_faila(vector<data> sarasas, int arVM, string failas);

void buffer_skaitymas(vector<data>& sarasas, string failas);
void buffer_rasymas(vector<data>& sarasas, string failas, int arVM);