/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:57:26 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/13 18:11:20 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain {
private:
	std::string	_ideas[100];
	size_t		_index;

public:
	Brain();
	Brain( const Brain& copy );
	Brain &operator=( const Brain &src );
	~Brain();

	std::string	getIdea( size_t index ) const;
	void		setIdea( std::string idea );
	
};