#include <iostream> //Ein-/Ausgabe
#include <cstdlib>	//system("...")
#include <vector>
#include <string>

std::string Weg;

struct vek  //struct für alle wichtigen Operationen im Vektor
{
	int x, y;
};

using feld_typ = std::vector<std::string>; //Alias für std::vector<std::string>

/*ADDITION VON VEK'S*/
vek operator+(vek a, vek b)   
{
	return{ a.x + b.x, a.y + b.y };
}

vek Richtung[] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };  //Die Richtungen

/*ZEICHEN AN BESTIMMTER STELLE*/
char& at(feld_typ& feld, vek pos)
{
	return feld[pos.y][pos.x];
}

/*AUSGABE DES VECTORS*/
void zeige(int höhe, int breite, const feld_typ& feld)
{
	for (int i = 0; i < höhe; i++)
	{
		for (int j = 0; j < breite; j++)
		{
			std::cout << feld[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/*ERMITTELSN DES WEGES*/
void finde_weg(feld_typ& feld, vek pos, unsigned knoten = 0)
{
	int leeresFeld = 0;
	int Breite = feld[0].length();
	int Höhe = feld.size();
	if (at(feld, pos) != ' ')
	{
		return;
	}

	std::cout << "Reihe: " << pos.y << ", Spalte: " << pos.x << '\n';
	at(feld, pos) = '0' + knoten;

	zeige(Höhe, Breite, feld);

	for (int i = 0; i < Höhe; i++)
	{
		for (int j = 0; j < Breite; j++)
		{
			if (feld[i][j] == ' ')
			{
				leeresFeld++;
			}
		}
	}
	
	if (leeresFeld == 0)
	{

		std::cout << Weg << std::endl << Weg.length() << " Felder besucht." << std::endl;
		system("Pause");
		exit(0);
	}

	for (auto richt_vek : Richtung){

		if (richt_vek.y == -1)
		{
			Weg.append("N");

		}
		if (richt_vek.y == 1)
		{
			Weg.append("S");

		}
		if (richt_vek.x == 1)
		{
			Weg.append("O");

		}
		if (richt_vek.x == -1)
		{
			Weg.append("W");

		}
		finde_weg(feld, pos + richt_vek, knoten + 1);
		Weg.pop_back();
	}

	std::cout << "Backtracking..\n";
	at(feld, pos) = ' ';
}



int main()
{
	/*VARIABLENDEKLARATION*/
	std::vector<std::string> feld =
	{  //0123456789
		"#########",  //0 
		"#       #",  //1
		"# ###   #",  //2
		"#       #",  //3
		"#########",  //4
					  //5
	};
	
	int Breite = feld[0].length();
	int Höhe = feld.size();
	int leeresFeld = 0;
	vek start_pos = { 3, 1 }; //Startpunkt, erst x dann y
	
	/*BEGINN DER ANWEISUNGEN*/
	
		finde_weg(feld, start_pos);  //Aufru

	for (int i = 0; i < Höhe; i++)
	{
		for (int j = 0; j < Breite; j++)
		{
			if (feld[i][j] == ' ')
			{
				leeresFeld++;
			}
		}
	}

	if (leeresFeld != 0)
	{
		std::cout << std::endl << "Kein Weg gefunden!" << std::endl;
	}

	system("Pause");
	return 0;
}
