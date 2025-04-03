#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap : public FragTrap, public ScavTrap {
  private:
    std::string		_Name;

  public:
	DiamondTrap();
	DiamondTrap(std::string Name);
	DiamondTrap(const DiamondTrap & copy);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap & src);
	void 	attack(const std::string & target);
	void	whoAmI();

};