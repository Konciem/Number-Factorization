#ifndef LISTA_HPP
#define LISTA_HPP

#include "InterfejsListy.hpp"

class Lista : public InterfejsListy {
    struct Wezel {
        int wartosc;
        Wezel* nastepny;
        Wezel(int w);
    };
    Wezel* glowa;
public:
    Lista();
    ~Lista();
    Lista(const Lista& inna); // Konstruktor kopiujący
    
    Lista& operator=(const Lista& inna); // Operator przypisania

    void dodaj(int wartosc) override;
    void wypisz() const override;
    int pobierz(int indeks) const override;
    int rozmiar() const override;
    Wezel* pobierzGlowe() const;
private:
    void wyczysc();
    void skopiujZ(const Lista& inna);
};

#endif // LISTA_HPP
