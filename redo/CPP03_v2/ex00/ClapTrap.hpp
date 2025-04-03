#pragma once
#include <iostream>
#include <string>

class ClapTrap {
  private:
	std::string	_Name;
	int			_Hit_points;
	int			_Energy_points;
	int			_Attack_damage;
  public:
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(ClapTrap const & copy);
	~ClapTrap();

	ClapTrap& operator=(ClapTrap const & rhs);
	void	attack(const std::string & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName() const;
	int			getHitPoints() const;
	int			getEnergyPoints() const;
	int			getAttackDamage() const;
};