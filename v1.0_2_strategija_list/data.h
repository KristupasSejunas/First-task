#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm> //sort
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <limits.h>


using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::list;

struct data {
	string vardas;
	string pavarde;
	int egz;
	vector<int> paz;
	double result = 0.0;
};
