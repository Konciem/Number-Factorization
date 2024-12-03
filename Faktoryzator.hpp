#ifndef FAKTORYZATOR_HPP
#define FAKTORYZATOR_HPP

#include <list>
#include "Liczba.hpp"

class Faktoryzator {
public:
    virtual ~Faktoryzator() = default;
    virtual std::list<int> faktoryzuj(const Liczba& liczba) const = 0;
};

#endif // FAKTORYZATOR_HPP
