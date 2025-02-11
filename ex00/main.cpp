/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:26:47 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 11:13:44 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include <exception>

// void testFunction(){
// 	throw std::domain_error("dumens");
// }

// int main(){
// 	try
// 	{
// 		testFunction();
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "hata yakalandi: " << e.what() << std::endl;
// 	}
// }


// class MyException : public std::exception {
// public:
//     const char* what() const noexcept override {
//         return "Özel bir hata meydana geldi!";
//     }
// };

// int main() {
//     try {
//         throw MyException();			bununda MyException e; throw e -> ayni anlamdadir
//     } catch (const std::exception& e) {
//         std::cout << "Hata yakalandı: " << e.what() << std::endl;
//     }
// }

// int main(){
// 	try {
// 		throw std::overflow_error("overflow hatasi");
// 	}
// 	catch(const std::overflow_error &e)
// 	{
// 		std::cout << "overflow error gardas" << e.what() << std::endl;
// 	}
// }

// Destructor icinde istisna firlatilmasi onerilmez
// noexcept parametresi ile istisna firlatilmaz.


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
	std::string getName( void );
	int			getGrade( void );
	void		incrementGrade( void );
	void		decrementGrade( void );
};

Bureaucrat::Bureaucrat(): _name("default"), _grade(150){};
Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150){};
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade){};
Bureaucrat::Bureaucrat(const Bureaucrat& other){*this = other;}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

std::string Bureaucrat::getName( void ){return _name;}
int			Bureaucrat::getGrade( void ){return _grade;}
void		Bureaucrat::incrementGrade( void ){_grade--;}
void		Bureaucrat::decrementGrade( void ){_grade++;}