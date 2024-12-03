#ifndef PLIKI_HPP
#define PLIKI_HPP

#include <string>
#include <list>
#include "Liczba.hpp"
#include "InterfejsListy.hpp"

class Pliki {
public:
    static std::list<Liczba> czytajLiczby(const std::string& nazwaPliku);
    static void zapiszCzynniki(const std::string& nazwaPliku, const std::list<std::pair<Liczba, InterfejsListy*>>& czynniki);
};

#endif // PLIKI_HPP
