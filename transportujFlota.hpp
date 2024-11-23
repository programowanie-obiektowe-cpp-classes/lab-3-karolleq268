#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    Stocznia stocznia{};
    unsigned int przetransportowano = 0;
    unsigned int liczbaZaglowcow = 0;

    while(przetransportowano < towar) {
        Statek* statek = stocznia(); // tworzy losowo albo tankowiec albo zaglowiec

        przetransportowano += statek->transportuj();

        if (dynamic_cast<Zaglowiec*>(statek)) { // Sprawdza czy obiekt jest typu Zaglowiec
            liczbaZaglowcow++; 
        }
        
        delete statek;
    }

    return liczbaZaglowcow;
}
