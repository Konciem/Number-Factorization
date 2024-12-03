#ifndef LICZBA_HPP
#define LICZBA_HPP

class Liczba {
    int value;
public:
    Liczba(int v) : value(v) {}
    int getValue() const { return value; }
};

#endif // LICZBA_HPP
