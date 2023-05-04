//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

long fibonacci(int n)
{
    int previousFib = 0;
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 2; i <= n; i++)
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib ;
        currentFib = newFib ;
    }
    return currentFib ;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 0; i <= 47 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;
}
