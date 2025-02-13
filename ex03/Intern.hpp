/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:06:06 by taha              #+#    #+#             */
/*   Updated: 2025/02/13 20:06:07 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Intern.hpp
#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);

		AForm *makeForm(std::string formName, std::string target);
};

#endif
