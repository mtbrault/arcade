//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Main program
//

#ifndef HARDCADE_HPP_
# define HARDCADE_HPP_

#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include "DynLib.hpp"
#include "Loader.hpp"

class   HardCade : public Loader {
public:
    HardCade();
    ~HardCade();

    void    loadLibs(const std::string &);
    void    run();

private:
    std::vector<std::unique_ptr<DynLib::Gfx>>    libs;
    std::vector<std::unique_ptr<DynLib::Game>>   games;
};

#endif