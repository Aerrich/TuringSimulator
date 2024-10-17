#include "turing.h"
#include "tmReader.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
	
	//Pfad zur Datei

	std::string path = "C:/Users/erikz/Downloads/aufg5.TM";
	std::vector<std::string> tmFile = readTM(path);
	
	//Eingabe

	std::string x = "110";

	//Initialisierung der TM

	turing t = turing(tmFile, x);//argv[2]

	//Start der Berechnung

	std::string r = t.run();

	//Ausgabe des Ergebnis

	std::cout << r << std::endl;



	std::cin.get();

}