/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:09:52 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/04 14:15:01 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		struct	functionList
		{
			std::string level;
			void (Harl:: *function)(void);
		};
		
	public:
		Harl(void);
		~Harl();
		void	complain(std::string level);
};

void	convertNumber(char number);

#endif
