/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:56:17 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 19:11:41 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target){}
RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other){*this = other;}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other)
		this->_target = other._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor); // Call base class execute first
	std::cout << "* DRILLING NOISES *" << std::endl;

	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << std::endl;
}