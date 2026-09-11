/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2e.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:49:34 by gomandam          #+#    #+#             */
/*   Updated: 2026/09/08 18:03:31 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2(int x, int y) : _x(x), _y(y)	{ }

vect2	vect2::operator+(const vect2 v) const
{
	return vect2(_x + v._x, _y + v._y);
}

vect2	vect2::operator-(const vect2 v) const
{
	return vect2(_x - v._x, _y - v._y);
}

// ADD: vect2& return type and parameter, *this
vect2&	vect2::operator+=(const vect2& v)
{
	return (_x += v._x, _y += v._y, *this);
}

vect2&	vect2::operator-=(const vect2& v)
{
	return (_x -= v._x, _y -= v._y, *this);
}

//ADD: operator++(), ++_x/_y
vect2&	vect2::operator++()
{
	return (++_x, ++_y, *this);
}

vect2&	vect2::operator--()
{
	return (--_x, --_y, *this);
}

// ADD: int parameter (as place-holder), full implementation 
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

//DIFFERENCE: const member function
int&	vect2::operator[](int i)
{
	return i ? _y : _x;
}

const int&	vect2::operator[](int i) const
{
	return i ? _y : _x;
}

//FUNCTION DECLARATIONS: unary '-', int multi, binary arithmetic operator
vect2	vect2::operator-() const
{
	return vect2(-_x, -_y);
}

//ADD: *(int n), *n			RM:'-'
vect2	vect2::operator*(int n) const
{
	return vect2(_x * n, _y * n);
}

//ADD:data_type& . *= , *this		RM: return vect2, const
vect2&	vect2::operator*=(int n)
{
	return (_x *= n, _y *= n, *this);
}

//BOOLEAN: "!=" and "=="
bool	vect2::operator==(const vect2& v) const
{
	return _x == v._x && _y == v._y;
}

bool	vect2::operator!=(const vect2& v) const
{
	return !(*this == v);
}
