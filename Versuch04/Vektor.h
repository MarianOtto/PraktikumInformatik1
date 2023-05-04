//
// Praktikum Informatik 1 MMXXIII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <numbers>

class Vektor
{
   public:
    Vektor(double x, double y, double z);
    ~Vektor();

    void ausgabe() const;
    Vektor add(const Vektor& input) const;
    Vektor sub(const Vektor& input) const;
    void mul(const int n);
    double laenge() const;
    double skalarProd(const Vektor& input) const;
    double winkel(const Vektor& input) const;
    void rotiereUmZ(const double rad);
    
   private:
    double x;
    double y;
    double z;

};

#endif












