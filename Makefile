run: main.o Generavimas.o Input_Output.o Rusiavimas.o Skaiciavimas.o Validacija.o
	g++ main.cpp Generavimas.cpp Input_Output.cpp Rusiavimas.cpp Skaiciavimas.cpp Validacija.cpp -o run

Generavimas.o: Generavimas.cpp
	g++ -c Generavimas.cpp

Input_Output.o: Input_Output.cpp
	g++ -c Input_Output.cpp

Rusiavimas.o: Rusiavimas.cpp
	g++ -c Rusiavimas.cpp

Skaiciavimas.o: Skaiciavimas.cpp
	g++ -c Skaiciavimas.cpp

Validacija.o: Validacija.cpp
	g++ -c Validacija.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: rm *.o run