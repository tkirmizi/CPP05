/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:04:12 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 16:08:29 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

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
		void signForm(Form& form);

		class	GradeTooHighException : public std::exception{
			public: const char *what() const throw();};

		class	GradeTooLowException : public std::exception{
			public: const char *what() const throw();};
};


#endif