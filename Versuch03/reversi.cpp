/**
 * Praktikum Informatik 1 MMXXIII
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
 * @mainpage Reversi
 *
 * Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
 *
 */

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"

/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
	for (int j = 0; j < GROESSE_Y; j++)
	{
		for (int i = 0; i < GROESSE_X; i++)
		{
			spielfeld[j][i] = 0;
		}
	}
	spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
	spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
	spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
	spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}

/**
 * @brief Ausgabe des Spielfelds auf der Konsole
 *
 * Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
 * Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
 *
 *  @param spielfeld  Spielfeld, das ausgeben wird
 */

void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
	std::cout << "   | ";

	//Start bei ASCII 65 = A
	for (int i = 65; i < 65 + GROESSE_X; ++i)
		std::cout << ((char) i) << " | ";

	std::cout << std::endl;

	for (int j = 0; j < GROESSE_Y; ++j)
	{
		for (int i = 0; i < GROESSE_X; ++i)
		{
			std::cout << "---+";
		}
		std::cout << "---+" << std::endl;

		std::cout << " " << j + 1 << " |";
		for (int i = 0; i < GROESSE_X; ++i)
		{
			switch (spielfeld[j][i])
			{
			case 0:
				std::cout << "   ";
				break;
			case 1:
				std::cout << " X ";
				break;
			case 2:
				std::cout << " O ";
				break;
			default:
				std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
				std::cout << "Abbruch .... " << std::endl;
				exit(0);
				break;
			}
			std::cout << "|";
		}
		;  //for i
		std::cout << std::endl;
	}  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
	int zaehlerSpieler1 = 0;
	int zaehlerSpieler2 = 0;

	for (int j = 0; j < GROESSE_Y; ++j)
	{
		for (int i = 0; i < GROESSE_X; ++i)
		{
			if (spielfeld[j][i] == 1)
			{
				++zaehlerSpieler1;
			}
			if (spielfeld[j][i] == 2)
			{
				++zaehlerSpieler2;
			}

		}
	}

	if (zaehlerSpieler1 == zaehlerSpieler2)
	{
		return 0;
	}
	if (zaehlerSpieler1 < zaehlerSpieler2)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
 *
 * @param posX Index fuer die Spalte
 * @param posY Index fuer die Zeile
 * @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
 */

bool aufSpielfeld(const int posX, const int posY)
{
	if (0 <= posX && posX < GROESSE_X && 0 <= posY && posY < GROESSE_Y)
	{
		return true;
	}
	return false;
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */

bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler, const int posX, const int posY)
{
	int gegner = 3 - aktuellerSpieler;
	int north = 0, northEast = 0, east = 0, southEast = 0, south = 0,
			southWest = 0, west = 0, northWest = 0; //               if aktuellerSpieler == 2 -> gegner = 1

	if (spielfeld[posY][posX] != 0) // ist das Feld leer?
	{
		return false;
	}

	for (int j = 1; j <= 7; j++)
	{
		for (int i = 1; i <= 7; i++)
		{
			//East
			if (aufSpielfeld(posY, posX + j) == true
					&& spielfeld[posY][posX + j] == gegner && east >= 0)
			{
				east++;
			}
			else if (aufSpielfeld(posY, posX + j) == true
					&& spielfeld[posY][posX + j] == aktuellerSpieler
					&& east >= 1)
			{
				return true;
			}
			else
			{
				east = -1;
			}

			//SouthEast
			if (i == j && aufSpielfeld(posY + i, posX + j) == true
					&& spielfeld[posY + i][posX + j] == gegner
					&& southEast >= 0)
			{
				southEast++;
			}
			else if (i == j && aufSpielfeld(posY + i, posX + j) == true
					&& spielfeld[posY + i][posX + j] == aktuellerSpieler
					&& southEast >= 1)
			{
				return true;
			}
			else if (i == j)
			{
				southEast = -1;
			}

			//South
			if (aufSpielfeld(posY + i, posX) == true
					&& spielfeld[posY + i][posX] == gegner && south >= 0)
			{
				south++;
			}
			else if (aufSpielfeld(posY + i, posX) == true
					&& spielfeld[posY + i][posX] == aktuellerSpieler
					&& south >= 1)
			{
				return true;
			}
			else
			{
				south = -1;
			}

			//SouthWest
			if (i == j && aufSpielfeld(posY + i, posX - j) == true
					&& spielfeld[posY + i][posX - j] == gegner
					&& southWest >= 0)
			{
				southWest++;
			}
			else if (i == j && aufSpielfeld(posY + i, posX - j) == true
					&& spielfeld[posY + i][posX - j] == aktuellerSpieler
					&& southWest >= 1)
			{
				return true;
			}
			else if (i == j)
			{
				southWest = -1;
			}

			//West
			if (aufSpielfeld(posY, posX - j) == true
					&& spielfeld[posY][posX - j] == gegner && west >= 0)
			{
				west++;
			}
			else if (aufSpielfeld(posY, posX - j) == true
					&& spielfeld[posY][posX - j] == aktuellerSpieler
					&& west >= 1)
			{
				return true;
			}
			else
			{
				west = -1;
			}

			//NorthWest
			if (i == j && aufSpielfeld(posY - i, posX - j) == true
					&& spielfeld[posY - i][posX - j] == gegner
					&& northWest >= 0)
			{
				northWest++;
			}
			else if (i == j && aufSpielfeld(posY - i, posX - j) == true
					&& spielfeld[posY - i][posX - j] == aktuellerSpieler
					&& northWest >= 1)
			{
				return true;
			}
			else if (i == j)
			{
				northWest = -1;
			}

			//North
			if (aufSpielfeld(posY - i, posX) == true
					&& spielfeld[posY - i][posX] == gegner && north >= 0)
			{
				north++;
			}
			else if (aufSpielfeld(posY - i, posX) == true
					&& spielfeld[posY - i][posX] == aktuellerSpieler
					&& north >= 1)
			{
				return true;
			}
			else
			{
				north = -1;
			}

			//NorthEast
			if (i == j && aufSpielfeld(posY - i, posX + j) == true
					&& spielfeld[posY - i][posX + j] == gegner
					&& northEast >= 0)
			{
				northEast++;
			}
			else if (i == j && aufSpielfeld(posY - i, posX + j) == true
					&& spielfeld[posY - i][posX + j] == aktuellerSpieler
					&& northEast >= 1)
			{
				return true;
			}
			else if (i == j)
			{
				northEast = -1;
			}

			if (north == -1 && northEast == -1 && east == -1 && southEast == -1
					&& south == -1 && southWest == -1 && west == -1
					&& northWest == -1)
			{
				return false;
			}
		}
	}
	return false;
}

/**
 * @brief Setzt Stein und dreht betroffene Steine um
 *
 * Geht moegliche Pfade bis zu einem eigenen Stein und dreht alle
 * auf dem Weg liegenden gegnerische Steine um
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */

void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler, const int posX, const int posY)
{

	int gegner = 3 - aktuellerSpieler;
	int north = 0, northEast = 0, east = 0, southEast = 0, south = 0,
			southWest = 0, west = 0, northWest = 0; //               if aktuellerSpieler == 2 -> gegner = 1
	if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY) == true)
	{
		for (int j = 1; j <= 7; j++)
		{
			for (int i = 1; i <= 7; i++)
			{
				//East
				if (aufSpielfeld(posY, posX + j) == true
						&& spielfeld[posY][posX + j] == gegner && east >= 0)
				{
					east++;
					std::cout << "E ";
				}
				else if (aufSpielfeld(posY, posX + j) == true
						&& spielfeld[posY][posX + j] == aktuellerSpieler
						&& east >= 1)
				{
					spielfeld[posY][posX] = aktuellerSpieler;
					for (int a = j; a > 0; a--)
					{
						for (int b = i; b > 0; b--)
						{
							spielfeld[posY][posX + a] = aktuellerSpieler;
						}
					}
					east = -1;
				}
				else
				{
					east = -1;
				}

				//SouthEast
				if (i == j && aufSpielfeld(posY + i, posX + j) == true
						&& spielfeld[posY + i][posX + j] == gegner
						&& southEast >= 0)
				{
					southEast++;
					std::cout << "SE ";
				}
				else if (i == j && aufSpielfeld(posY + i, posX + j) == true
						&& spielfeld[posY + i][posX + j] == aktuellerSpieler
						&& southEast >= 1)
				{
					spielfeld[posY][posX] = aktuellerSpieler;
					for (int a = j; a > 0; a--)
					{
						for (int b = i; b > 0; b--)
						{
							if (a == b)
							{
								spielfeld[posY + b][posX + a] =
										aktuellerSpieler;
							}
						}
					}
					southEast = -1;
				}
				else if (i == j)
				{
					southEast = -1;
				}

				//South
				if (aufSpielfeld(posY + i, posX) == true
						&& spielfeld[posY + i][posX] == gegner && south >= 0)
				{
					south++;
					std::cout << "S ";
				}
				else if (aufSpielfeld(posY + i, posX) == true
						&& spielfeld[posY + i][posX] == aktuellerSpieler
						&& south >= 1)
				{
					spielfeld[posY][posX] = aktuellerSpieler;
					for (int a = j; a > 0; a--)
					{
						for (int b = i; b > 0; b--)
						{
							spielfeld[posY + b][posX] = aktuellerSpieler;
						}
					}
					south = -1;
				}
				else
				{
					south = -1;
				}

				//SouthWest
				if (i == j && aufSpielfeld(posY + i, posX - j) == true
						&& spielfeld[posY + i][posX - j] == gegner
						&& southWest >= 0)
				{
					southWest++;
					std::cout << "SW ";
				}
				else if (i == j && aufSpielfeld(posY + i, posX - j) == true
						&& spielfeld[posY + i][posX - j] == aktuellerSpieler
						&& southWest >= 1)
				{
					spielfeld[posY][posX] = aktuellerSpieler;
					for (int a = j; a > 0; a--)
					{
						for (int b = i; b > 0; b--)
						{
							if (a == b)
							{
								spielfeld[posY + b][posX - a] =
										aktuellerSpieler;
							}
						}
					}
					southWest = -1;
				}
				else if (i == j)
				{
					southWest = -1;
				}

				//West
				if (aufSpielfeld(posY, posX - j) == true
						&& spielfeld[posY][posX - j] == gegner && west >= 0)
				{
					west++;
					std::cout << "W ";
				}
				else if (aufSpielfeld(posY, posX - j) == true
						&& spielfeld[posY][posX - j] == aktuellerSpieler
						&& west >= 1)
				{
					spielfeld[posY][posX] = aktuellerSpieler;
					for (int a = j; a > 0; a--)
					{
						for (int b = i; b > 0; b--)
						{
							spielfeld[posY][posX - a] = aktuellerSpieler;
						}
					}
					west = -1;
				}
				else
				{
					west = -1;
				}

				//NorthWest
				if (i == j && aufSpielfeld(posY - i, posX - j) == true
						&& spielfeld[posY - i][posX - j] == gegner
						&& northWest >= 0)
				{
					northWest++;
					std::cout << "NW ";
				}
				else if (i == j && aufSpielfeld(posY - i, posX - j) == true
						&& spielfeld[posY - i][posX - j] == aktuellerSpieler
						&& northWest >= 1)
				{
					spielfeld[posY][posX] = aktuellerSpieler;
					for (int a = j; a > 0; a--)
					{
						for (int b = i; b > 0; b--)
						{
							if (a == b)
							{
								spielfeld[posY - b][posX - a] =
										aktuellerSpieler;
							}
						}
					}
					northWest = -1;
				}
				else if (i == j)
				{
					northWest = -1;
				}

				//North
				if (aufSpielfeld(posY - i, posX) == true
						&& spielfeld[posY - i][posX] == gegner && north >= 0)
				{
					north++;
					std::cout << "N ";
				}
				else if (aufSpielfeld(posY - i, posX) == true
						&& spielfeld[posY - i][posX] == aktuellerSpieler
						&& north >= 1)
				{
					spielfeld[posY][posX] = aktuellerSpieler;
					for (int a = j; a > 0; a--)
					{
						for (int b = i; b > 0; b--)
						{
							spielfeld[posY - b][posX] = aktuellerSpieler;
						}
					}
					north = -1;
				}
				else
				{
					north = -1;
				}

				//NorthEast
				if (i == j && aufSpielfeld(posY - i, posX + j) == true
						&& spielfeld[posY - i][posX + j] == gegner
						&& northEast >= 0)
				{
					northEast++;
					std::cout << "NE ";
				}
				else if (i == j && aufSpielfeld(posY - i, posX + j) == true
						&& spielfeld[posY - i][posX + j] == aktuellerSpieler
						&& northEast >= 1)
				{
					spielfeld[posY][posX] = aktuellerSpieler;
					for (int a = j; a > 0; a--)
					{
						for (int b = i; b > 0; b--)
						{
							if (a == b)
							{
								spielfeld[posY - b][posX + a] =
										aktuellerSpieler;
							}
						}
					}
					northEast = -1;
				}
				else if (i == j)
				{
					northEast = -1;
				}

			}
		}
	}
}

/**
 * @brief Bestimmt Anzahl moeglicher Zuege
 *
 *  Iteriert über alles Spielfeld und ueberprueft mit zugGueltig,
 *  ob auf dem Feld ein Zug moeglich ist. Addiert gueltige Zuege auf.
 *
 * @param spielfeld  Spielfeld, das ausgeben wird
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return count Anzahl der Spielzuege
 *
 */

int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler)
{
	int count = 0;
	for (int i = 0; i < GROESSE_Y; i++)
	{
		for (int j = 0; j < GROESSE_X; j++)
		{
			if (zugGueltig(spielfeld, aktuellerSpieler, j, i))
			{
				count++;
			}
		}
	}
	return count;
}

/**
 * @brief Warte auf Eingabe und setzt Stein
 *
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return
 */

bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler)
{
	if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
	{
		return false;
	}

	int posX;
	int posY;
	std::string symbolSpieler;
	if (aktuellerSpieler == 1)
	{
		symbolSpieler = "X";
	}
	else
	{
		symbolSpieler = "O";
	}

	while (true)
	{
		std::string eingabe;
		std::cout << std::endl << "Du bist " << symbolSpieler
				<< ". Dein Zug (z.B. A1, a1): ";
		std::cin >> eingabe;
		posX = (int) eingabe[0] % 32 - 1;
		posY = (int) eingabe[1] - 49;

		if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
		}
	}

	zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
	std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf "
			<< (char) (posX + 65) << (posY + 1) << std::endl;

	return true;
}

/**
 * @brief Startfunktion zum spielen
 *
 * @param spielerTyp Aufteilung der Spieler (Computer/Mensch)
 */

void spielen(const int spielerTyp[2])
{
	int spielfeld[GROESSE_Y][GROESSE_X];

	//Erzeuge Startaufstellung
	initialisiereSpielfeld(spielfeld);

	int aktuellerSpieler = 1;
	zeigeSpielfeld(spielfeld);

	while(moeglicheZuege(spielfeld, aktuellerSpieler)
			|| moeglicheZuege(spielfeld, 3 - aktuellerSpieler))
	{

		if(moeglicheZuege(spielfeld, aktuellerSpieler) && spielerTyp[aktuellerSpieler - 1] == MENSCH)
		{
			menschlicherZug(spielfeld, aktuellerSpieler);
		}
		else
		{
			computerZug(spielfeld, aktuellerSpieler);
		}
		zeigeSpielfeld(spielfeld);
		if(aktuellerSpieler == 1) {aktuellerSpieler = 2;} else {aktuellerSpieler = 1;};

	}

	switch (gewinner(spielfeld))
	{
	case 1:
		std::cout << std::endl << "Spieler 1 hat gewonnen" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "Spieler 2 hat gewonnen" << std::endl;
		break;
	default:
		std::cout << std::endl << "Unentschieden" << std::endl;
	}
}

int main()
{
	if (TEST == 1)
	{
		bool gesamtErgebnis = ganzenTestAusfuehren();
		if (gesamtErgebnis == true)
		{
			std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
		}
		else
		{
			std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
			exit(1);
		}
		std::cout << std::endl << std::endl;
	}

	int spieler1, spieler2, again;
	do{
	std::cout << std::endl << "Spieler 1 (Mensch = 1/Computer = 2) : ";
	std::cin >> spieler1;
	std::cout << std::endl << "Spieler 2 (Mensch = 1/Computer = 2) : ";
	std::cin >> spieler2;
	int spielerWert = spieler1 + spieler2;
	if(spieler1 == 1 && spieler2 == 2)
	{
		spielerWert = 5;
	}

	int spielerTyp[2];

	switch(spielerWert)
	{
	case 4:
		spielerTyp[0] = COMPUTER;
		spielerTyp[1] = COMPUTER;
		break;
	case 3:
		spielerTyp[0] = COMPUTER;
		spielerTyp[1] = MENSCH;
		break;
	case 2:
		spielerTyp[0] = MENSCH;
		spielerTyp[1] = MENSCH;
		break;
	case 5:
		spielerTyp[0] = MENSCH;
		spielerTyp[1] = COMPUTER;
		break;
	default:
		spielerTyp[0] = COMPUTER;
		spielerTyp[1] = COMPUTER;
	}
	spielen(spielerTyp);

	std::cout << std::endl << "Erneut spielen? JA = 1; NEIN = 0 : ";
	std::cin >> again;
	std::cout << std::endl;
	}
	while(again == 1);

	return 0;
}
