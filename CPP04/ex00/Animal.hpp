/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:55:13 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/12 16:33:38 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal {
protected:
	std::string		_type;

public:
	Animal();
	Animal(const Animal& copy);
	Animal &operator=( const Animal &src );
	virtual ~Animal();

	std::string		getType() const;
	virtual void	makeSound() const;
};



