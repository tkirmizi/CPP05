/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:49:11 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 19:22:00 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
	std::cout << "\n========== Test 1 - Form Grade Requirements ===========" << std::endl;
	std::cout << "Expected output: Grade too low" << std::endl;
	try {
		ShrubberyCreationForm form1("Invalid");
		Bureaucrat bob("Bob", 150);
		bob.executeForm(form1);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== Test 2 - Unsigned Form Execution ===========" << std::endl;
	std::cout << "Expected output: Form is not signed" << std::endl;
	try {
		ShrubberyCreationForm form2("Home");
		Bureaucrat jim("Jim", 1);
		jim.executeForm(form2);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== Test 3 - Presidential Pardon Form ===========" << std::endl;
	try {
		PresidentialPardonForm form3("Criminal");
		Bureaucrat president("President", 5);
		std::cout << "Form status before signing: " << form3.getSigned() << std::endl;
		form3.beSigned(president);
		std::cout << "Form status after signing: " << form3.getSigned() << std::endl;
		president.executeForm(form3);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== Test 4 - Robotomy Request Form ===========" << std::endl;
	try {
		RobotomyRequestForm form4("Bender");
		Bureaucrat manager("Manager", 45);
		form4.beSigned(manager);
		// Test multiple robotomy attempts to see randomization
		manager.executeForm(form4);
		manager.executeForm(form4);
		manager.executeForm(form4);
	}
	catch(const std::exception& e) {
	    std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== Test 5 - Shrubbery Creation Form ===========" << std::endl;
	try {
		ShrubberyCreationForm form5("Garden");
		Bureaucrat gardener("Gardener", 137);
		form5.beSigned(gardener);
		gardener.executeForm(form5);
		std::cout << "Garden_shrubbery file was created" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== Test 6 - Form Information Display ===========" << std::endl;
	try {
		PresidentialPardonForm form6("Test");
		RobotomyRequestForm form7("Robot");
		ShrubberyCreationForm form8("Tree");
	
		std::cout << "\nPresidential Pardon Form:" << std::endl;
		std::cout << form6;
		std::cout << "\nRobotomy Request Form:" << std::endl;
		std::cout << form7;
		std::cout << "\nShrubbery Creation Form:" << std::endl;
		std::cout << form8;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== Test 7 - Grade Too Low to Sign ===========" << std::endl;
	try {
		PresidentialPardonForm form9("Criminal");
		Bureaucrat intern("Intern", 150);
		std::cout << "Trying to sign form with grade " << intern.getGrade() << std::endl;
		form9.beSigned(intern);
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}