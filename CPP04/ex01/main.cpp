/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:14:33 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/13 18:36:20 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include <iostream>

int main() {
std::string	test = "Brain test";
size_t		i = 5;
const Animal* array[i]; 
std::cout << std::endl;

for (size_t j = 0; j < i / 2; j++) {
	array[j] = new Cat();
	std::cout << std::endl;
}
for (size_t j = 0; j < i / 2; j++) {
	array[j] = new Dog();
	std::cout << std::endl;
}
std::cout << std::endl;
for (size_t j = 0; j < i; j++) {
	array[j]->getType();
	array[j]->makeSound();
	std::cout << std::endl;
}
{
	std::cout << "\033[1;32mChecking that copies are deep copies\033[0m" << std::endl;
		
	Dog	basic;
	{
		Dog	tmp = basic;
	}
}
std::cout << std::endl;
for (size_t j = 0; j < i; j++) {
	delete array[i];
	std::cout << std::endl;
}
}