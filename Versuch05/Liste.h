//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung
    void pushBack(Student pData);
    void popFront();
    void popBack();
    bool empty();
    Student dataFront();
    Student dataBack();
    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const;
    void deleteElement(int matrikelNr);
};

#endif /*LISTE_H_*/
