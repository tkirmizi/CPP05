/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:04:12 by taha              #+#    #+#             */
/*   Updated: 2025/02/14 17:11:57 by tkirmizi         ###   ########.fr       */
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
		Bureaucrat& 			operator=(const Bureaucrat &other);
		friend std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);
		
		std::string 			getName(void) const;
		int						getGrade(void) const ;
		void					incrementGrade(void);
		void					decrementGrade(void);
		void					executeForm(Form const & form) const;

		class	GradeTooHighException : public std::exception{
			public: const char *what() const noexcept override;};

		class	GradeTooLowException : public std::exception{
			public: const char *what() const noexcept override;};
};


#endif