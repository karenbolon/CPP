#include "Zombie.hpp"


int	main() {
	Zombie	ted("Ted");
	ted.announce();
	std::cout << std::endl;

	Zombie* instance = newZombie("Betty");
	instance->announce();

	std::cout << std::endl;
	randomChump("Rambo");
	std::cout << std::endl;

	delete instance;
	std::cout << std::endl;

}