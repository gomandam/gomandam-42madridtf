/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 22:32:42 by gomandam          #+#    #+#             */
/*   Updated: 2026/08/29 02:18:12 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"
#include <iostream>
#include <iomanip>

int	main()
{
	// Configure precision for displaying doubles
	// std::cout << std::fixed << std::setprecision(2);

	// Test constructors
	vect2 a;
	vect2 b(8, 9);
	vect2 c(3, 3);

	std::cout << "Constructors:\n";
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n\n";

	// Test operator[]
	std::cout << "Access to components:\n";
	std::cout << "b[0] = " << b[0] << ", b[1] = " << b[1] << "\n";
	std::cout << "c[0] = " << c[0] << ", c[1] = " << c[1] << "\n";
	c[0] = 7;
	std::cout << "c[0] = " << c[0] << ", c[1] = " << c[1] << "\n\n";

	// Test operations with scalars
	std::cout << "Operations with scalars:\n";
	a = vect2(3, 3);
	std::cout << "a = " << a << "\n";
	std::cout << "2 * a = " << 2 * a << "\n";
	std::cout << "a * 2 = " << a * 2 << "\n";
	std::cout << "b + 2 = " << b + 2 << "\n";
	std::cout << "2 + b = " << 2 + b << "\n\n";

	// Test compound operations
	std::cout << "Compound operations:\n";
	a = vect2(1, 1);
	b = vect2(2, 2);
	a += b += c;
	std::cout << "a += b += c : a = " << a << ", b = " << b << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n";

	a = vect2(5, 5);
	std::cout << "a = " << a << "\n";
	a -= 2;
	std::cout << "a -= 2 : " << a << "\n";
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	a -= b;
	std::cout << "a -= b : " << a << "\n\n";

	// Test complex expressions
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n";
	a = b * c + 2;
	std::cout << "a = b * c + 2 : " << a << "\n";
	a = 2 + b * c;
	std::cout << "a = 2 + b * c : " << a << "\n\n";

	// Test increment/decrement operators
	std::cout << "Increment/Decrement:\n";
	a = vect2(1, 1);
	std::cout << "a = " << a << "\n";
	std::cout << "a++ = " << a++ << "\n";
	std::cout << "a = " << a << "\n";
	std::cout << "++a = " << ++a << "\n";
	std::cout << "a-- = " << a-- << "\n";
	std::cout << "a = " << a << "\n";
	std::cout << "--a = " << --a << "\n\n";

	vect2 f(2, 3);
	vect2 g(2, 3);
	// Test comparisons
	std::cout << "Comparisons:\n";
	std::cout << "b == c : " << (g == f) << "\n";
	std::cout << "b != c : " << (g != f) << "\n";

	return (0);
}
