//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int getAsciiUpper(string String)
{
	int asciiNumber = (int) String[0];
	if ((int) String[0] > 90)
	{
		asciiNumber -= 32;
	}
	return asciiNumber;
}

int main()
{
	int iErste = 1;
	int iZweite = 1;
	int iSumme, iQuotient;

	//    1.6.1.1

	cout << "Geben Sie zwei Zahlen ein" << endl << "Erste Zahl: ";
	cin >> iErste;
	cout << "Zweite Zahl: ";
	cin >> iZweite;
	cout << endl;
	iSumme = iErste + iZweite;
	iQuotient = iErste / iZweite;
	cout << iSumme << "/" << iQuotient << " (Summe/Quotient) in Int Form"
			<< endl;

	//	  1.6.1.2

	double dSumme, dQuotient;
	dSumme = iErste + iZweite;
	dQuotient = iErste / iZweite;
	cout << dSumme << "/" << dQuotient << " (Summe/Quotient) in double Form"
			<< endl;

	//1.6.1.3

	double dSummeCast, dQuotientCast;
	dSummeCast = (double) iErste + (double) iZweite;
	dQuotientCast = (double) iErste / (double) iZweite;
	cout << dSummeCast << "/" << dQuotientCast
			<< " (Summe/Quotient) in double Form casted" << endl;

	//1.6.1.4

	string sVorname, sNachname;
	string sVornameName, sNameVorname;
	cout << endl << "Vorname: ";
	cin >> sVorname;
	cout << "Nachname: ";
	cin >> sNachname;

	sVornameName += sVorname + " " + sNachname;
	sNameVorname += sNachname + ", " + sVorname;

	cout << endl << sVornameName << endl << sNameVorname << endl;

	//1.6.1.5

	{
		//a

		int iFeld[2] =
		{ 1, 2 };
		cout << endl << iFeld[0] << " Erster Eintrag von iFeld" << endl << iFeld[1]
				<< " Zweiter Eintrag von iFeld \n \n";

		//b

		int spielfeld[2][3] =
		{
		{ 1, 2, 3 },
		{ 4, 5, 6 }
		};
		cout << "Zeile 1:" << endl;
		for (int i = 0; i <= 2; i++)
		{
			cout << spielfeld[0][i] << " ";
		}
		cout << endl;

		cout << "Zeile 1:" << endl;
		for (int i = 0; i <= 2; i++)
		{
			cout << spielfeld[1][i] << " ";
		}
		cout << endl << endl;

		//c
		const int iZweite = 1;

		cout << iZweite << endl;
	}
	cout << iZweite << endl;

	//1.6.1.6

	int iName1 = (int) sVorname[0];
	int iName2 = (int) sNachname[0];

	cout << "ascii 1: " << iName1 << endl;
	cout << "ascii 2: " << iName2 << endl;

	//1.6.1.7

	cout << "Position Buchstabe 1: " << getAsciiUpper(sVorname) - 64 << endl;
	cout << "Position Buchstabe 2: " << getAsciiUpper(sNachname) - 64 << endl;

	return 0;
}
















