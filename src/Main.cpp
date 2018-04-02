//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Main
//

#include "HardError.hpp"
#include "HardCade.hpp"

int	main(int ac, char **av)
{
	srand(time(nullptr));
	if (ac != 2) {
		std::cerr << "Invalid usage\nTry ./arcade [LIBPATH]\n";
		return (84);
	}
	try {
		HardCade    arc(av[1]);
		arc.loadLibs();
		arc.run();
	} catch (const Error &error) {
		std::cerr << error.what() << std::endl;
		return (84);
	}
	return (0);
}