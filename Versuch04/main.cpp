/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <unistd.h>

#define pi 3.1415926535
#define epsilon 1 * pow(10, -17)

/**
 * @brief Gibt die groesste Entfernung eines Punktes und des Horizontes aus
 *
 *  Naehrt den Horizontvektor dem Punkt langsam an und passt
 *  die Position dynamisch an, bis 90 Grad erreicht sind
 *
 * @param height Turmhöhe
 * @param radius Erdradius
 * @return
 */

double entfernungHorizont(double height, double radius)
{
	double phi = 0.1;
	Vektor viewpoint(0, radius + height + 0.0017, 0);
	Vektor horizon(0, radius, 0);
	Vektor eyeline = horizon.sub(viewpoint);
	eyeline.ausgabe();

	int i = 1;
	int j = 0;
	int count = 0;
	unsigned int micro = 500000;
	std::cout << eyeline.skalarProd(horizon);
	while(abs(eyeline.skalarProd(horizon)) > epsilon)
	{
		phi = pow(-1, i%2) * pow(10, -1-j);
		horizon.rotiereUmZ(phi);
		eyeline = horizon.sub(viewpoint);
		if(eyeline.winkel(horizon) < 90 && (i%2) == 1)
		{
			j++;
			i++;
		}
		if(eyeline.winkel(horizon) > 90 && (i%2) == 0)
		{
			j++;
			i++;
		}
		count++;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Count: " << count << std::endl;
		std::cout << std::setprecision(9) << "Winkel: " << eyeline.winkel(horizon) << std::endl;
		std::cout << std::setprecision(9) << "Phi: " << phi << std::endl;
		std::cout << "Laenge: " << eyeline.laenge() << std::endl;
		std::cout << "i/j " << i << "/" << j << std::endl;
		Vektor eyeline = horizon.sub(viewpoint);

		usleep(micro);
	}
	std::cout << eyeline.laenge() << std::endl;
	std::cout << viewpoint.winkel(horizon);

	return phi;
}

int main()
{

	entfernungHorizont(0.557, 6371);

    return 0;

}























