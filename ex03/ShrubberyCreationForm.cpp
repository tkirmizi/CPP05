/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:38:23 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 19:32:10 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target){};

ShrubberyCreationForm::~ShrubberyCreationForm(){};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other){*this = other;}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);

	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile.is_open())
	    throw std::runtime_error("Cannot create file");
	
	outfile << "    *    \n";
	outfile << "   ***   \n";
	outfile << "  *****  \n";
	outfile << " ******* \n";
	outfile << "   |||   \n";
	outfile.close();
}