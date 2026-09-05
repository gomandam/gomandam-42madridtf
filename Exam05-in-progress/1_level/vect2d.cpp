/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 01:47:18 by gomandam          #+#    #+#             */
/*   Updated: 2026/09/05 03:30:27 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2(int x, int y) : _x(x) , _y(y) { }

vect2	vect2::operator+(const vect2 v) const
{
	return vect2(_x + v._x, _y + v._y);
}

vect2	vect2::operator-(const vect2 v) const
{
	return vect2(_x - v._x, _y - v._y);
}


// BEFORE: block compound statement	NEW: comma separated expressioni
// PREVIOUSLY:
// vect2& vect2::operator+=(const vect2& v) { _x += v._x; _y += v._y; return *this; }
vect2&	vect2::operator+=(const vect2& v)
{
	return (_x += v._x, _y += v._y, *this);
}

vect2&	vect2::operator-=(const vect2& v)
{
	return (_x -= v._x, _y -= v._y, *this);
}


// BEFORE: block compound statement	NEW: comma separated expressioni
// PREVIOUSLY: vect2& vect2::operator++() { ++_x;   ++_y;   return *this; }
vect2&	vect2::operator++()
{
	return (++_x, ++_y, *this);
}

vect2&	vect2::operator--()
{
	return (--_x, --_y, *this);
}


// BEFORE: block compound statement	NEW: comma separated expressioni
// PREVIOUSLY: vect2 vect2::operator++(int) { vect2 tmp(*this); ++*this; return tmp; }
vect2	vect2::operator++(int)
{
	vect2 tmp(*this);
	return (++*this, tmp);
}

vect2	vect2::operator--(int)
{
	vect2 tmp(*this);
	return (--*this, tmp);
}


// DIFFERENCE: const member function
int&	vect2::operator[](int i)
{
	return i ? _y : _x;
}

const int&	vect2::operator[](int i) const
{
	return i ? _y : _x;
}


// OVERLOADS: unary minus, int multiplicatx, binary arithmetic operator
vect2	vect2::operator-() const
{
	return vect2(-_x, -_y);
}

// ADD: "int n", and "*n"	REMOVE: "negative"
vect2	vect2::operator*(int n) const
{
	return vect2(_x *n, _y *n);
}

// CHANGED to comma separated expression, PREVIOUSLY block compound statement
vect2&	vect2::operator*=(int n)
{
	return (_x *= n, _y *= n, *this);
}


// BOOLEAN: "!=" and "==" binary comparison operator overloads
bool	vect2::operator==(const vect2& v) const
{
	return _x == v._x && _y == v._y;
}

bool	vect2::operator!=(const vect2& v) const
{
	return !(*this == v);
}

// WORK on INLINE at ".hpp" and member function declarations
