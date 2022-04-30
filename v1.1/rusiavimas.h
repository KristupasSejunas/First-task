#pragma once

#include "data.h"

bool pagal_varda(data a, data b);
bool pagal_pavarde(data a, data b);
bool pagal_pazymi(data a, data b);
void studentu_skirtymas(vector<data>& sarasas, vector<data>& pirmunai, vector<data>& nuskriaustieji);

void studentu_skirtymas(list<data>& sarasas, list<data>& pirmunai, list<data>& nuskriaustieji);
void studentu_skirtymas(deque<data>& sarasas, deque<data>& pirmunai, deque<data>& nuskriaustieji);

void studentu_skirtymas_1(vector<data>& sarasas, vector<data>& pirmunai, vector<data>& nuskriaustieji);
void studentu_skirtymas_1(list<data>& sarasas, list<data>& pirmunai, list<data>& nuskriaustieji);
void studentu_skirtymas_1(deque<data>& sarasas, deque<data>& pirmunai, deque<data>& nuskriaustieji);