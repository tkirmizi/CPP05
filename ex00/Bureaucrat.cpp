/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:04:52 by taha              #+#    #+#             */
/*   Updated: 2025/02/14 16:14:37 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Orthodox Canonical Form
Bureaucrat::Bureaucrat(): _name("default"), _grade(150){};
Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150){};
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
	{
		GradeTooHighException gthe;
		throw gthe;
	}
	if (grade > 150)
	{
		GradeTooLowException gtle;
		throw gtle;
	}
	_grade = grade;
};
Bureaucrat::Bureaucrat(const Bureaucrat& other){*this = other;}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

//Member Functions
std::string Bureaucrat::getName(void) const {return _name;}
int			Bureaucrat::getGrade(void) const {return _grade;}
void		Bureaucrat::incrementGrade(void)
{
	if ((_grade - 1) < 1)
		throw GradeTooHighException();
	_grade--;
}
void		Bureaucrat::decrementGrade(void)
{
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	_grade++;
}

// Exception Classes
const char* Bureaucrat::GradeTooHighException::what() const noexcept {return "Grade too high";}
const char* Bureaucrat::GradeTooLowException::what() const noexcept {return "Grade too Low";}

// Overload operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}