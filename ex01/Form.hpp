/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:12:48 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 19:14:37 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		~Form();
		Form(const Form &other);
		Form& operator=(const Form &other);

		std::string getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception{
			public: const char *what() const throw();};
		class GradeTooLowException : public std::exception{
			public: const char *what() const throw();};
		friend std::ostream &operator<<(std::ostream &os, const Form &f);
};

#endif