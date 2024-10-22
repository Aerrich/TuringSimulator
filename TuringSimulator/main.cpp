#include "turing.h"
#include "tmReader.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
	
	//Pfad zur Datei
	
	std::string path = argv[1];
	//std::string path = "C:/Users/erikz/Desktop/Abgabe1/einsPunktFünf.TM";
	std::vector<std::string> tmFile = readTM(path);
	
	//Eingabe

	std::string eingabe = argv[2];
	//std::string eingabe = "110101011001";

	//Initialisierung der TM

	turing t = turing(tmFile, eingabe);

	//Start der Berechnung

	std::string r = t.run();

	//Ausgabe des Ergebnis

	std::cout << r << std::endl;

}