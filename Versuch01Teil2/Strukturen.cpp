/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;
int main()
{

	struct Person
	{
		string sVorname;
		string sNachname;
		int iGeburtsjahr;
		int iAlter;
	};

	Person nBenutzer;

	//Eingae

	cout << "Vorname: ";
	cin >> nBenutzer.sVorname;
	cout << "Nachname: ";
	cin >> nBenutzer.sNachname;
	cout << "Geburtsjahr: ";
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Alter: ";
	cin >> nBenutzer.iAlter;





	Person nKopieEinzeln;
	Person nKopieGesamt;

	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	nKopieGesamt = nBenutzer;

	//Ausgabe

	cout << endl << endl << nBenutzer.sNachname << ", " << nBenutzer.sVorname << endl;
	cout << nBenutzer.iGeburtsjahr << ", " << nBenutzer.iAlter << " Jahre alt" << endl;

	cout << endl << nKopieEinzeln.sNachname << ", " << nKopieEinzeln.sVorname << endl;
	cout << nKopieEinzeln.iGeburtsjahr << ", " << nKopieEinzeln.iAlter << " Jahre alt" << endl;

	cout << endl << nKopieGesamt.sNachname << ", " << nKopieGesamt.sVorname << endl;
	cout << nKopieGesamt.iGeburtsjahr << ", " << nKopieGesamt.iAlter << " Jahre alt" << endl;
    return 0;
}
