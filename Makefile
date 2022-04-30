run: main.o generavimas.o inout.o rusiavimas.o skaici.o validacija.o
	g++ main.cpp generavimas.cpp inout.cpp rusiavimas.cpp skaic.cpp validacija.cpp -o run

Generavimas.o: generavimas.cpp
	g++ -c generavimas.cpp

Input_Output.o: inout.cpp
	g++ -c inout.cpp

Rusiavimas.o: rusiavimas.cpp
	g++ -c rusiavimas.cpp

Skaiciavimas.o: skaic.cpp
	g++ -c skaic.cpp

Validacija.o: validacija.cpp
	g++ -c validacija.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: rm *.o run