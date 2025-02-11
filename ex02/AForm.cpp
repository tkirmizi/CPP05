/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:33:21 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 17:33:30 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm()
	:_name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){};

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(){};

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}
	
AForm& AForm::operator=(const AForm &other){
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

std::string AForm::getName(void) const{return _name;}
bool		AForm::getSigned(void) const{return _signed;}
int			AForm::getGradeToSign(void) const{return _gradeToSign;}
int			AForm::getGradeToExecute(void) const{return _gradeToExecute;}

const char* AForm::GradeTooHighException::what() const throw(){return "Grade too high";}
const char* AForm::GradeTooLowException::what() const throw(){return "Grade too Low";}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm name: " << f.getName() << std::endl;
	os << "Signed: " << f.getSigned() << std::endl;
	os << "Grade to sign: " << f.getGradeToSign() << std::endl;
	os << "Grade to execute: " << f.getGradeToExecute() << std::endl;
	return os;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}
