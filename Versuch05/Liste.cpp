//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back);
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
	ListenElement* cursor = front;
    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Entferne ein Listenelement am Ende der Liste.
 *
 * @return void
 */

void Liste::popBack()
{
	ListenElement* cursor = back;
    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete back;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        back = back->getPrev();
        back->setNext(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr || back == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Gibt die Daten des letzten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataBack()
{
    return back->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}

/**
 * @brief Loescht ein ausgewaehltes Element bezueglich der Matrikelnummer
 *
 * @return void
 */

void Liste::deleteElement(int matrikelNr)
{
	ListenElement* cursor = front;

	while (cursor->getData().getMatNr() != matrikelNr)
	{
		cursor = cursor->getNext();
		if(cursor == nullptr)
		{
			std::cout << "Matrikelnummer nicht gefunden!" << std::endl;
			return;
		}
	}

	if(cursor->getPrev() == nullptr)
	{
		front = cursor->getNext();
		front->setPrev(nullptr);
	}
	else
	{
		cursor->getPrev()->setNext(cursor->getNext());
	}

	if(cursor->getNext() == nullptr)
	{
		front = cursor->getPrev();
		front->setNext(nullptr);
	}
	else
	{
		cursor->getNext()->setPrev(cursor->getPrev());
	}

	std::cout << "Geloescht: ";
	cursor->getData().ausgabe();
	delete cursor;
}













