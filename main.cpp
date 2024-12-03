#include <iostream>
#include <list>
#include <fstream>
#include "Liczba.hpp"
#include "FaktoryzatorLP.hpp"
#include "Lista.hpp"
#include "Pliki.hpp"

int main() {
    // Read numbers from file
    std::list<Liczba> liczby = Pliki::czytajLiczby("dane.txt");

    // Initialize factorizer
    FaktoryzatorLP faktoryzator;

    // Factorize numbers
    std::list<std::pair<Liczba, InterfejsListy*>> wynik;
    for (const Liczba& liczba : liczby) {
        std::list<int> czynniki = faktoryzator.faktoryzuj(liczba);
        Lista* listaCzynnikow = new Lista();
        for (int czynnik : czynniki) {
            listaCzynnikow->dodaj(czynnik);
        }
        wynik.emplace_back(liczba, listaCzynnikow);
    }

    // Save factors to CSV file
    Pliki::zapiszCzynniki("czynniki.csv", wynik);

    // Clean up
    for (auto& pair : wynik) {
        delete pair.second;
    }

    return 0;
}
