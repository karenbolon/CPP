/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:14:33 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/14 14:59:15 by kbolon           ###   ########.fr       */
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
	
size_t		rows = 5;
//const Animal* testAnimal = new Animal();//proof that it can't be instantiated
const Animal* array[rows]; 
std::cout << std::endl;

for (size_t i = 0; i < rows / 2; i++) {
	array[i] = new Cat();
	std::cout << std::endl;
}
for (size_t i = rows / 2; i < rows; i++) {
	array[i] = new Dog();
	std::cout << std::endl;
}
std::cout << std::endl;
for (size_t i = 0; i < rows; i++) {
	array[i]->getType();
	array[i]->makeSound();
	std::cout << std::endl;
}

std::cout << std::endl;
for (size_t i = 0; i < rows; i++) {
	delete array[i];
	std::cout << std::endl;
}
}