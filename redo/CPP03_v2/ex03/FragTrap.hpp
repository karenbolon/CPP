#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {

  public:
	FragTrap();
	FragTrap(std::string Name);
	FragTrap(const FragTrap & src);

	~FragTrap();
	FragTrap& operator =(const FragTrap & src);
    void highFivesGuys(void);
};