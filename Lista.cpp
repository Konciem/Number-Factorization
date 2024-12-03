#include "Lista.hpp"
#include <iostream>
#include <stdexcept>

// Konstruktor węzła
Lista::Wezel::Wezel(int w) : wartosc(w), nastepny(nullptr) {}

// Konstruktor listy
Lista::Lista() : glowa(nullptr) {}

// Destruktor
Lista::~Lista() {
    wyczysc();
}

// Konstruktor kopiujący
Lista::Lista(const Lista& inna) : glowa(nullptr) {
    skopiujZ(inna);
}

// Operator przypisania i przciozenia 
Lista& Lista::operator=(const Lista& inna) {
    if (this == &inna) return *this; // Ochrona przed samoprzydziałem
    wyczysc();
    skopiujZ(inna);
    return *this;
}

// Metoda do czyszczenia listy
void Lista::wyczysc() {
    Wezel* obecny = glowa;
    while (obecny) {
        Wezel* nastepny = obecny->nastepny;
        delete obecny;
        obecny = nastepny;
    }
    glowa = nullptr;
}

// Metoda do kopiowania listy
void Lista::skopiujZ(const Lista& inna) {
    if (inna.glowa == nullptr) {
        glowa = nullptr;
        return;
    }
    glowa = new Wezel(inna.glowa->wartosc);
    Wezel* obecny = glowa;
    Wezel* innyObecny = inna.glowa->nastepny;
    while (innyObecny) {
        obecny->nastepny = new Wezel(innyObecny->wartosc);
        obecny = obecny->nastepny;
        innyObecny = innyObecny->nastepny;
    }
}

// Metoda do dodawania elementu do listy
void Lista::dodaj(int wartosc) {
    Wezel* nowyWezel = new Wezel(wartosc);
    if (!glowa) {
        glowa = nowyWezel;
    } else {
        Wezel* temp = glowa;
        while (temp->nastepny) {
            temp = temp->nastepny;
        }
        temp->nastepny = nowyWezel;
    }
}

// Metoda do wypisywania listy
void Lista::wypisz() const {
    Wezel* temp = glowa;
    while (temp) {
        std::cout << temp->wartosc << " ";
        temp = temp->nastepny;
    }
    std::cout << std::endl;
}

// Metoda do uzyskiwania wartości elementu na danej pozycji
int Lista::pobierz(int indeks) const {
    Wezel* temp = glowa;
    int licznik = 0;
    while (temp) {
        if (licznik == indeks) return temp->wartosc;
        licznik++;
        temp = temp->nastepny;
    }
    throw std::out_of_range("Indeks poza zakresem");
}

// Metoda do uzyskiwania rozmiaru listy
int Lista::rozmiar() const {
    int licznik = 0;
    Wezel* temp = glowa;
    while (temp) {
        licznik++;
        temp = temp->nastepny;
    }
    return licznik;
}

// Metoda do uzyskania wskaźnika na głowę
Lista::Wezel* Lista::pobierzGlowe() const {
    return glowa;
}
