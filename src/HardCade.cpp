//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Main program
//

#include "HardCade.hpp"

HardCade::HardCade()
    :Loader()
{
}

HardCade::~HardCade()
{
}

void    HardCade::loadLibs(const std::string &first) {
    std::cout << "Load\nfirst is "<< first << "\n";
}

void    HardCade::run()
{
    std::cout << "Run\n";
}