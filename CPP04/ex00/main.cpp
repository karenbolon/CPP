/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:14:33 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/12 16:52:46 by kbolon           ###   ########.fr       */
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
const Animal* Animal1 = new Animal();
const Animal* Dog1 = new Dog();
const Animal* Cat1 = new Cat();
const WrongAnimal* WrongAnimal1 = new WrongAnimal();
const WrongAnimal* WrongDog1 = new WrongDog();
const WrongAnimal* WrongCat1 = new WrongCat();

std::cout << "Animal type: " << Animal1->getType() << " " << std::endl;
std::cout << "Dog type: " << Dog1->getType() << " " << std::endl;
std::cout << "Cat type: " << Cat1->getType() << " " << std::endl;
std::cout << "Animal says: ";
Animal1->makeSound();
std::cout << std::endl;
std::cout << "Dog says: ";
Dog1->makeSound();
std::cout << std::endl;
std::cout << "Cat says: ";
Cat1->makeSound();
std::cout << std::endl;
delete Animal1, delete Dog1, delete Cat1;
 

std::cout << "\033[31mWrongAnimal type: " << WrongAnimal1->getType() << " " << std::endl;
std::cout << "\033[31mWrongDog type: " << WrongDog1->getType() << " " << std::endl;
std::cout << "\033[31mWrongCat type: " << WrongCat1->getType() << " " << std::endl << std::endl;
std::cout << "\033[31mWrongAnimal says: ";
WrongAnimal1->makeSound();
std::cout << std::endl;
std::cout << "\033[31mWrongDog says: "; 
WrongDog1->makeSound();
std::cout << std::endl;
std::cout << "\033[31mWrongCat says: ";
WrongCat1->makeSound();
std::cout << std::endl;

delete WrongAnimal1, delete WrongDog1, delete WrongCat1;
}