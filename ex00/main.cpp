/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:26:47 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 12:27:30 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include <exception>
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		std::string getName(void) const;
		int			getGrade(void) const ;
		void		incrementGrade(void);
		void		decrementGrade(void);
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
		class	GradeTooHighException : public std::exception{
			public: const char *what() const throw();};
		class	GradeTooLowException : public std::exception{
			public: const char *what() const throw();};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

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
const char* Bureaucrat::GradeTooHighException::what() const throw(){return "Grade too high";}
const char* Bureaucrat::GradeTooLowException::what() const throw(){return "Grade too Low";}

int main()
{
	std::cout << "\n ========== Test 1 - Constructor ==========" << std::endl;
	std::cout << "Expected output : Grade too low" << std::endl;
	try
	{
		Bureaucrat bur1("Bur1", 151);
	}
	catch(const std::exception &e){
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