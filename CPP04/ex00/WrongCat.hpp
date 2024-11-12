/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:09:16 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/12 16:34:25 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat();
	WrongCat(const WrongCat& copy);
	WrongCat &operator=( const WrongCat &src );
	
	~WrongCat();

	void			makeSound() const;
};
