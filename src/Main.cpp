//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Main
//

#include "HardCade.hpp"

int	main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Invalid usage\nTry ./arcade [LIBPATH]\n";
        return (84);
    }
    HardCade    arc;
    arc.loadLibs(std::string(av[1]));
    arc.run();
    return (0);
}
