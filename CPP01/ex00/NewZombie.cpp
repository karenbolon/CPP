/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:23:49 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/05 15:45:02 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//new creates a new Zombie object on the heap
//it calls the Zombie constructor in the name as
//part of the arguement
//the automatically allocates memory on the heap
//which allows it to exist beyond the scope of the fcn
Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
}


