/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:25:00 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/04 15:35:51 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

int main(void)
{
	try {
		Bureaucrat	b("Bob", 100);

		cout << b << endl;
		b.incrementGrade();
		cout << b << endl;
		b.decrementGrade();
		cout << b << endl;
		b.incrementGrade();
		cout << b << endl;
	} catch (std::exception &e) {
		cout << "Exception caught: " << e.what() << endl;
	}
	cout << endl;
	try {
		Bureaucrat	b("Thirsty", 1);

		cout << b << endl;
		b.decrementGrade();
		cout << b << endl;
		b.decrementGrade();
		cout << b << endl;
		b.incrementGrade();
		cout << b << endl;
	} catch (std::exception &e) {
		cout << "Exception caught: " << e.what() << endl;
	}
	cout << endl;
	try {
		Bureaucrat	b("Yeyo", 1);

		cout << b << endl;
		b.incrementGrade();
		cout << b << endl;
		b.decrementGrade();
		cout << b << endl;
		b.incrementGrade();
		cout << b << endl;
	} catch (std::exception &e) {
		cout << "Exception caught: " << e.what() << endl;
	}
	cout << endl;
	try {
        Bureaucrat b("Doll", 150);
        
        cout << b << endl;
        b.incrementGrade();
        cout << b << endl;
        b.decrementGrade();
        cout << b << endl;
        b.incrementGrade();
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
	cout << endl;
	try {
        Bureaucrat b("Roll", 150);
        
        cout << b << endl;
        b.decrementGrade();
        cout << b << endl;
        b.incrementGrade();
        cout << b << endl;
        b.decrementGrade();
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
	cout << endl;
	try {
        Bureaucrat b("Nine", 151);
        
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
	cout << endl;
	try {
        Bureaucrat b("Nine", 0);
        
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
	cout << endl;
	try {
        Bureaucrat b("Nine", 15151);
        
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
	cout << endl;
	try {
        Bureaucrat b("Nine", -100);
        
        cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
	cout << endl;
	try {
        Bureaucrat b;
        
        cout << b << endl;
		b.setGrade(-10);
		cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
	cout << endl;
	try {
        Bureaucrat b;
        
        cout << b << endl;
		b.setGrade(200);
		cout << b << endl;
    } catch (std::exception &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
}