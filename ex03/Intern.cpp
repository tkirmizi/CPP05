/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:06:28 by taha              #+#    #+#             */
/*   Updated: 2025/02/14 16:01:08 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &other) {*this = other;}

Intern& Intern::operator=(const Intern &other){(void)other; return *this;}

Form *Intern::makeForm(std::string formName, std::string target)
{
	std::string formTypes[] =
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	Form *forms[] = 
	{
		new PresidentialPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target)
	};

	Form *selectedForm = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (formName == formTypes[i])
		{
			selectedForm = forms[i];
			std::cout << "Intern creates " << formName << std::endl;
		}
		else
			delete forms[i];
	}
	if (!selectedForm)
		throw std::runtime_error("Form type not found");
	return selectedForm;
}