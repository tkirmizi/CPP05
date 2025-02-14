/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:49:11 by taha              #+#    #+#             */
/*   Updated: 2025/02/14 16:01:08 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


// int main()
// {
// 	std::cout << "\n========== Test 1 - Creating Presidential Pardon Form ===========" << std::endl;
// 	try {
// 		Intern intern;
// 		Bureaucrat president("President", 5);
// 		Form* form = intern.makeForm("presidential pardon", "Criminal");
	
// 		std::cout << "\nForm details:" << std::endl;
// 		std::cout << *form;
	
// 		form->beSigned(president);
// 		president.executeForm(*form);
	
// 		delete form;
// 	}
// 	catch(const std::exception& e) {
// 	    std::cout << e.what() << std::endl;
// 	}

// 	std::cout << "\n========== Test 2 - Creating Robotomy Request Form ===========" << std::endl;
// 	try {
// 		Intern intern;
// 		Bureaucrat manager("Manager", 45);
// 		Form* form = intern.makeForm("robotomy request", "Bender");
	
// 		form->beSigned(manager);
// 		manager.executeForm(*form);
// 		manager.executeForm(*form);
	
// 		delete form;
// 	}
// 	catch(const std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << "\n========== Test 3 - Creating Shrubbery Creation Form ===========" << std::endl;
// 	try {
// 		Intern intern;
// 		Bureaucrat gardener("Gardener", 137);
// 		Form* form = intern.makeForm("shrubbery creation", "Garden");
	
// 		form->beSigned(gardener);
// 		gardener.executeForm(*form);
	
// 		delete form;
// 	}
// 	catch(const std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << "\n========== Test 4 - Trying to Create Invalid Form ===========" << std::endl;
// 	try {
// 		Intern intern;
// 		Form* form = intern.makeForm("invalid form", "Target");
	
// 		if (form) // This should not execute
// 			delete form;
// 	}
// 	catch(const std::exception& e) {
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}

// 	std::cout << "\n========== Test 5 - Multiple Forms Creation ===========" << std::endl;
// 	try {
// 		Intern intern;
// 		Bureaucrat boss("Boss", 1);
	
// 		Form* form1 = intern.makeForm("presidential pardon", "Criminal1");
// 		Form* form2 = intern.makeForm("robotomy request", "Bender2");
// 		Form* form3 = intern.makeForm("shrubbery creation", "Garden3");
	
// 		std::cout << "\nForm 1 details:" << std::endl;
// 		std::cout << *form1;
// 		std::cout << "\nForm 2 details:" << std::endl;
// 		std::cout << *form2;
// 		std::cout << "\nForm 3 details:" << std::endl;
// 		std::cout << *form3;
	
// 		delete form1;
// 		delete form2;
// 		delete form3;
// 	}
// 	catch(const std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}

//     return 0;
// }

int main()
{
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}