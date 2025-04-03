#include "Zombie.hpp"

//allocates a Zombie object using new and returns a pointer to it
Zombie* newZombie(std::string name) {
	return (new Zombie(name));
}
