/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:19:32 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 19:29:35 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	:_name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){};

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(){};

Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}
	
Form& Form::operator=(const Form &other){
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

std::string Form::getName(void) const{return _name;}
bool		Form::getSigned(void) const{return _signed;}
int			Form::getGradeToSign(void) const{return _gradeToSign;}
int			Form::getGradeToExecute(void) const{return _gradeToExecute;}

const char* Form::GradeTooHighException::what() const throw(){return "Grade too high";}
const char* Form::GradeTooLowException::what() const throw(){return "Grade too Low";}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form name: " << f.getName() << std::endl;
	os << "Signed: " << f.getSigned() << std::endl;
	os << "Grade to sign: " << f.getGradeToSign() << std::endl;
	os << "Grade to execute: " << f.getGradeToExecute() << std::endl;
	return os;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}


