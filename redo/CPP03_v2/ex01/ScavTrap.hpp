#pragma once
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class	ScavTrap : public ClapTrap
{
public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(ScavTrap const & copy);
  ScavTrap& operator=(ScavTrap const & src);
  ~ScavTrap();

  void	attack(const std::string & target);
  void	guardGate();
};
