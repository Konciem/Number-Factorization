#ifndef INTERFEJSLISTY_HPP
#define INTERFEJSLISTY_HPP

class InterfejsListy {
public:
    virtual ~InterfejsListy() = default;
    virtual void dodaj(int wartosc) = 0;
    virtual void wypisz() const = 0;
    virtual int pobierz(int indeks) const = 0;
    virtual int rozmiar() const = 0;
};

#endif // INTERFEJSLISTY_HPP
