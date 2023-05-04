//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Function calculating the length of a vector
 */

double Vektor::laenge() const
{
	double length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return length;
}

/**
 * @brief Function calculating the scalar product of two vectors
 */

double Vektor::skalarProd(const Vektor& input) const
{
	double skalarProd = x * input.x + y * input.y + z * input.z;
	return skalarProd;
}

/**
 * @brief Function calculating the angle between two vectors
 */

double Vektor::winkel(const Vektor& input) const
{
	double angleRad = acos(this->skalarProd(input) / (this->laenge() * input.laenge()));
	double angleDeg = angleRad / (2 * 3.1415926535) * 360;
	return angleDeg;
}

/**
 * @brief Function rotating a vector by rad radiants
 */

void Vektor::rotiereUmZ(const double rad)
{
	double radX = (cos(rad) * x) + (sin(rad) * y);
	double radY = (cos(rad) * y) - (sin(rad) * x);
	x = radX;
	y = radY;
}

/**
 * @brief Subtrahiert zwei Vektoren
 *
 * @return Neuer Vektor
 */


Vektor Vektor::sub(const Vektor& input) const
{
	Vektor vector(x - input.x, y - input.y, z - input.z);
	return vector;
}












