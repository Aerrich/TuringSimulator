#pragma once
#include <vector>
#include <string>


class turing {

public:
	turing(std::vector<std::string> machine, std::string eingabe); //konstruktor der die eingelesenen TM zeilen als vectoreinträge und die eingabe bekommt
	std::string run(); // Startet die berechnung

private:
	int bandZeiger = 1; //Zeiger auf aktuelle position des Bandes
	int zustand = 0; //Speichert den aktuellen Zustand
	int endzustand = 0; //Speichert den Endzustand
	int anzahlRegeln = 0; //Speichert die Anzahl der Regeln
	std::vector<char> band = {}; //die Symbole auf dem Band
	std::vector<std::string> func[5]; //Regeln der Übergangsfunktion
	std::string bandOhneEingabe = "";
	void bandAusgeben(); //Gibt das aktuelle Band + infos aus
	


};

