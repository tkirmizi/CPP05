/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:26:47 by taha              #+#    #+#             */
/*   Updated: 2025/02/11 13:59:19 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Alice("Alice", 50);
	Bureaucrat Juli("Juli", 30);
	Bureaucrat Bob("Bob", 1);

	Form tax("Tax", 40, 20);
	Form deport("Deport", 5, 1);
	
	Alice.signForm(tax);
	Juli.signForm(tax);
	Juli.signForm(deport);
	Bob.signForm(tax);
	Bob.signForm(deport);
}