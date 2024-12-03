#include "Pliki.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

// Read numbers from a file
std::list<Liczba> Pliki::czytajLiczby(const std::string& nazwaPliku) {
    std::list<Liczba> liczby;
    std::ifstream file(nazwaPliku);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
        return liczby;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int value;
        if (iss >> value) {
            liczby.emplace_back(value);
        }
    }
    file.close();
    return liczby;
}

// Write factors to a file
void Pliki::zapiszCzynniki(const std::string& nazwaPliku, const std::list<std::pair<Liczba, InterfejsListy*>>& czynniki) {
    std::ofstream file(nazwaPliku);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
        return;
    }

    for (const auto& pair : czynniki) {
        file << pair.first.getValue() << ",";
        for (int i = 0; i < pair.second->rozmiar(); ++i) {
            file << pair.second->pobierz(i);
            if (i < pair.second->rozmiar() - 1) {
                file << ",";
            }
        }
        file << std::endl;
    }
    file.close();
}
