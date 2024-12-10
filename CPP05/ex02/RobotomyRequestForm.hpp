/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:52:03 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/10 12:02:44 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
private:
	const std::string _target;

public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm &operator=( const RobotomyRequestForm &src );
	~RobotomyRequestForm();

	void	execute( const Bureaucrat& executor ) const;

};