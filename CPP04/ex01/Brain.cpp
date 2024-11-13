/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:00:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/13 18:18:10 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _index( 0 ) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( const Brain& copy ) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
}

Brain& Brain::operator=( const Brain &src ) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &src) {
		for (size_t i = 0; i < 100; i++)
			_ideas[i] = src._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain deconstructor called";
}

std::string	Brain::getIdea( size_t index ) const {
	return (_ideas[index]);
}

void	Brain::setIdea( std::string idea ) {
	_ideas[_index++] = idea;
}
