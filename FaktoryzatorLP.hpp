#ifndef FAKTORYZATORLP_HPP
#define FAKTORYZATORLP_HPP

#include "Faktoryzator.hpp"

class FaktoryzatorLP : public Faktoryzator {
public:
    std::list<int> faktoryzuj(const Liczba& liczba) const override;
};

#endif // FAKTORYZATORLP_HPP
