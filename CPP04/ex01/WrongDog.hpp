/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:09:16 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/12 16:34:20 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {

public:
	WrongDog();
	WrongDog(const WrongDog& copy);
	WrongDog &operator=( const WrongDog &src );
	~WrongDog();

	void			makeSound() const;
};
