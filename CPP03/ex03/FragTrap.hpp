/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:38:46 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/11 12:01:10 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

/*
Without the virtual, the call of the function area() is being set once by 
the compiler as the version defined in the base class. The function call 
is fixed before the program is executed.
 
It will now only use the base case no matter how it is implemented in each of
the child classes because the function is set during the compilation of the 
program.

With virtual functions, the compiler looks at the contents of the pointer 
instead of just it's type. This way you can use the "base function/class" in 
child classes and have different outputs. This signals to the compiler that 
we don't want static linkage for this function (it can change).
*/

class FragTrap : virtual public ClapTrap{
public:
	FragTrap();
	FragTrap( std::string Name );
	FragTrap( const FragTrap& copy );

	~FragTrap();

	FragTrap &operator=( const FragTrap &src );

 	void highFivesGuys( void );

};