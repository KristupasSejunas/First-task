#pragma once

#include "data.h"

int skaicius(int nuo, int iki);
void random_paz(int k, data& temp);
void naujas_failas(string failo_pav, int studSk, int ndSk);
string naujo_failo_antraste(int ndSk);
string studentas(int ndSk);

string Vardenis();
string Pavardenis();

const vector <string> Vardas = { "Emily","Hannah","Madison","Ashley","Sarah","Alexis","Samantha","Jessica","Elizabeth","Taylor","Lauren","Alyssa","Kayla","Abigail","Brianna","Olivia","Emma",
								"Megan","Grace","Victoria","Rachel","Anna","Sydney","Destiny","Morgan","Jennifer","Jasmine","Haley","Julia","Kaitlyn","Nicole","Amanda","Katherine","Natalie",
								"Hailey","Alexandra","Savannah","Chloe","Rebecca","Stephanie","Maria","Sophia","Mackenzie","Allison","Isabella","Mary","Amber","Danielle","Gabrielle",
								"Jordan","Brooke","Michelle","Sierra","Katelyn","Andrea","Madeline","Sara","Kimberly","Courtney","Brittany","Erin","Vanessa","Jenna","Jacqueline","Caroline",
								"Faith","Makayla","Bailey","Paige","Shelby","Melissa","Kaylee","Christina","Trinity","Mariah","Caitlin","Autumn","Marissa","Breanna","Angela","Catherine","Zoe","Briana" };

const vector <string> Pavarde = { "SMITH","JOHNSON","WILLIAMS","JONES","BROWN","DAVIS","MILLER","WILSON","MOORE","TAYLOR","ANDERSON","THOMAS","JACKSON","WHITE","HARRIS","MARTIN","THOMPSON","GARCIA","MARTINEZ",
								"ROBINSON","CLARK","RODRIGUEZ","LEWIS","LEE","WALKER","HALL","ALLEN","YOUNG","HERNANDEZ","KING","WRIGHT","LOPEZ","HILL","SCOTT","GREEN","ADAMS","BAKER","GONZALEZ","NELSON","CARTER",
								"MITCHELL","PEREZ","ROBERTS","TURNER","PHILLIPS","CAMPBELL","PARKER","EVANS","EDWARDS","COLLINS","STEWART","SANCHEZ","MORRIS","ROGERS","REED","COOK","MORGAN","BELL","MURPHY","BAILEY",
								"RIVERA","COOPER","RICHARDSON","COX","HOWARD","WARD","TORRES","PETERSON","GRAY","RAMIREZ","JAMES","WATSON","BROOKS","KELLY","SANDER","PRICE","BENNETT","WOOD","BARNE","ROSS","HENDERSON",
								"COLEMAN","JENKINS","PERRY","POWELL","LONG","PATTERSON","HUGHES","FLORES","WASHINGTON","BUTLER","SIMMONS","FOSTER","GONZALES","BRYANT","ALEXANDER","RUSSELL","GRIFFIN","DIAZ","HAYES","MYERS",
								"FORD","HAMILTON","GRAHAM","SULLIVAN","WALLAC","WOODS","COLE","WEST","JORDAN","OWENS","EYNOLDS","FISHER","ELLIS","HARRISON","GIBSON","MCDONALD","CRUZ","MARSHAL","ORTIZ","GOMEZ","MURRAY","FREEMAN",
								"WELLS","WEBB","SIMPSON","STEVENS","TUCKER","PORTER","HUNTER","HICKS","CRAWFOR","HENRY","BOYD","MASON","MORALES","KENNEDY","WARREN","DIXON","RAMOS","REYES","BURN","GORDON","SHAW","HOLMES","RICE",
								"ROBERTSON","HUNT","BLACK","DANIELS" };