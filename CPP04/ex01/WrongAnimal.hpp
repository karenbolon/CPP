/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:09:16 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/12 16:31:44 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <string>
#include <iostream>

class WrongAnimal{
protected:
	std::string		_type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal &operator=( const WrongAnimal &src );
	
	~WrongAnimal();
	
	std::string		getType() const;
	void			makeSound() const;
};
