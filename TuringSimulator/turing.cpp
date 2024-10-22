#include "turing.h"
#include <iostream>

turing::turing(std::vector<std::string> geleseneMachine, std::string eingabe)
{

	anzahlRegeln = geleseneMachine.size()-5;

	//Auslesen des Startzustandes
	
	zustand = std::stoi(geleseneMachine.at(3));

	//Auslesen des Endzustandes

	std::string bandAlph = geleseneMachine.at(2);
	std::string eingAlph = geleseneMachine.at(1);

	for (char c : bandAlph)
	{

		bool x = true;

		for (char t : eingAlph)
		{

			if (c == t)
			{

				x = false;

			}

		}

		if (x == true) bandOhneEingabe.push_back(c);

	}

	endzustand = std::stoi(geleseneMachine.at(4));

	//inizialisieren der Regeln
	for (int i = 5; i < geleseneMachine.size(); i++)
	{

		int x = 0;

		//iteration über alle 5 Werte einer Regel

		for(int j = 0; j < 5; j ++)
		{
			std::string str(1, geleseneMachine.at(i).at(x));

			//Falls zahlen größer als 9 vorkommen

			while (x + 1 < geleseneMachine.at(i).size() && geleseneMachine.at(i).at(x + 1) != ' ')
			{
				x += 1;

				str.push_back(geleseneMachine.at(i).at(x));

			}

			//Wert im jeweiligen Vector speichern
			func[j].push_back(str);
			//Beachten der leerstellen zwischen den Regeln
			x += 2;
		}
		

	}

	//inizialisieren des Bandes
	band.push_back('B');
	for (int i = 0; i < eingabe.length(); i++)
	{

		band.push_back(eingabe.at(i));

	}
	band.push_back('B');
	
}

std::string turing::run()
{
	while (zustand != endzustand)
	{
		//Ausgabe des Bandes

		bandAusgeben();

		// temp speichert den aktuellen Bandeintrag

		char temp = band.at(bandZeiger);

		//Schleifenabbruchbedingung wenn Regel gefunden wurde

		bool bo = true;

		//Iteration über alle Regeln um richtige zu finden

		for (int i = 0; i < anzahlRegeln; i++)

		{

			//Abfrage nach Abbruchbedingung

			if (bo == false) break;

			//Gucken ob Regel passt (Zustand und Bandeintrag)

			if (func[0].at(i) == std::to_string(zustand) && func[1].at(i).c_str()[0] == temp && bo == true)
			{

				//Zustand ändern

				zustand = std::stoi(func[2].at(i));

				//Bandeintrag ändern

				band.at(bandZeiger) = func[3].at(i).at(0);

				//bandZeiger verschieben

				if (func[4].at(i) == "R")
				{

					

					bandZeiger++;
					bo = false;
				}
				if (func[4].at(i) == "L")
				{
					//Überprüfen ob Band links zu kurz ist
					if(0 == bandZeiger)
					{

						band.insert(band.begin(), 'B');

					}
					
					else
					{

						bandZeiger--;


					}
						bo = false;

				}
				if (func[4].at(i) == "N")
				{	

					

					bo = false;
				}
				//Überprüfen ob Band rechts zu kurz wird
				if (band.size()-1 == bandZeiger)
				{

					band.push_back('B');

				}
			}

		}

	}
	
	bandAusgeben();
	//Ausgabe des Bandes ab dem Zeiger bis zum ersten Symbol welches nicht im Eingabealphabet ist

	std::string res = "";
	
	for (int i = bandZeiger; bandOhneEingabe.find(band.at(i)) == std::string::npos; i++)
	{

		res += band.at(i);

	}

	return res;
}


//Gibt das Band, den jetztigen Zustand und die position des Zeigers aus

void turing::bandAusgeben()
{

	for (int i = 0; i < band.size(); i++)
	{
		if (i == bandZeiger) std::cout << "[";
		if (i == bandZeiger + 1) std::cout << "]";
		std::cout << band.at(i);
		if (i == band.size() - 1 && i == bandZeiger) std::cout << "]";
	}
	std::cout << "   Zustand:" << zustand;
	std::cout << std::endl;

}


