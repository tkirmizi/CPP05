/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:32:31 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 17:33:07 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		~AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);

		std::string getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception{
			public: const char *what() const throw();};
		class GradeTooLowException : public std::exception{
			public: const char *what() const throw();};
		friend std::ostream &operator<<(std::ostream &os, const AForm &f);
};

#endif