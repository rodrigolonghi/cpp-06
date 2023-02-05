#include "Conversion.hpp"

int	main(int argc, char *argv[]) {
	if (argc > 2) {
		std::cout << "Too many arguments passed! Try just one.\n";
		return (1);
	}
	if (argc < 2) {
		std::cout << "You need to pass one argument! Try again.\n";
		return (1);
	}

	Conversion	c(argv[1]);
	std::cout << c;

	return (0);
}
