#include "FaktoryzatorLP.hpp"

std::list<int> FaktoryzatorLP::faktoryzuj(const Liczba& liczba) const {
    std::list<int> czynniki;
    int n = liczba.getValue();
    for (int i = 2; i <= n / i; ++i) {
        while (n % i == 0) {
            czynniki.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        czynniki.push_back(n);
    }
    return czynniki;
}
