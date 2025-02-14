/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:26:47 by taha              #+#    #+#             */
/*   Updated: 2025/02/14 16:16:41 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n ========== Test 1 - Constructor ==========" << std::endl;
	std::cout << "Expected output : Grade too low" << std::endl;
	try
	{
		Bureaucrat bur1("Bur1", 151);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ========== Test 2 - Constructor ==========" << std::endl;
	std::cout << "Expected output : Grade too high" << std::endl;
	try 
	{
		Bureaucrat bur2("bur2", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ========== Test 3 - Increment Operator ==========" << std::endl;
	Bureaucrat bur3("Bur3", 1);
	std::cout << "Initiated grade is: " << bur3.getGrade() << std::endl;
	std::cout << "Increment operator working ..." << std::endl;
	try
	{
		bur3.incrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ========== Test 4 - Decrement Operator ==========" << std::endl;
	Bureaucrat bur4("Bur4", 150);
	std::cout << "Initiated grade is: " << bur4.getGrade() << std::endl;
	std::cout << "Decrement operator working ..." << std::endl;
	try
	{
		bur4.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n ========== Test 5 - Increment / Decrement Working Case ==========" << std::endl;
	Bureaucrat bur5("Bur5", 75);
	std::cout << "Initial grade: " << bur5.getGrade() << std::endl;
	bur5.incrementGrade();
	std::cout << "After increment: " << bur5.getGrade() << std::endl;
	bur5.incrementGrade();
	std::cout << "After increment: " << bur5.getGrade() << std::endl;
	bur5.incrementGrade();
	std::cout << "After increment: " << bur5.getGrade() << std::endl;
	bur5.decrementGrade();
	std::cout << "After decrement: " << bur5.getGrade() << std::endl;
	bur5.decrementGrade();
	std::cout << "After decrement: " << bur5.getGrade() << std::endl;
	bur5.decrementGrade();
	std::cout << "After decrement: " << bur5.getGrade() << std::endl;

	std::cout << "\n ========== Test 6 - Insertion Operations ==========" << std::endl;
	std::cout << bur3 << std::endl;
	std::cout << bur4 << std::endl;
	std::cout << bur5 << std::endl;

}