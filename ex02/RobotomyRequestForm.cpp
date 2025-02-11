/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:56:17 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 18:01:39 by taha             ###   ########.fr       */
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

// void RobotomyRequestForm::execute(Bureaucrat const & executor) const;
// {
// 	if (executor.getGrade() > getGradeToExecute())
// 		throw AForm::GradeTooLowException();
// 	std::cout << "Drilling noises" << std::endl;
// }
