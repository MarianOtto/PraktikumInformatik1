///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

char schluesselEncode[2][26] =
{
{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
{ 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A' }
};

char schluesselDecode[2][26] =
{
{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
{ 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y' }
};

string verschluesseln(char schluessel[2][26], string wort)
{
	string codeword = wort;
	for (int n = 0; n <= (int) wort.length() - 1; n++)
	{
		codeword[n] = schluessel[1][(codeword[n]) % 32 - 1];
	}
	cout << "Wort: " << wort << endl << "Codewort: " << codeword << endl
			<< endl;
	return codeword;
}

string entschluesseln(char schluessel[2][26], string codeword)
{
	string wort = codeword;
	for (int n = 0; n <= (int) codeword.length() - 1; n++)
	{
		wort[n] = schluessel[1][wort[n] % 32 - 1];
	}
	cout << "Codewort: " << codeword << endl << "Wort: " << wort << endl
			<< endl;
	return wort;
}

int main()
{
	string wort;
	cout << "Wort zum verschluesseln: ";
	cin >> wort;
	string codeword = verschluesseln(schluesselEncode, wort);
	entschluesseln(schluesselDecode, codeword);

	return 0;
}
