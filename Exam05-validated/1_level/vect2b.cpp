/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2b.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:04:56 by gomandam          #+#    #+#             */
/*   Updated: 2026/09/03 17:48:42 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vect2.hpp"

vect2::vect2(int x, int y) : _x(x), _y(y)
{
}

vect2 vect2::operator+(const vect2& v) const
{
	return	vect2(_x + v._x, _y + v._y);
}

vect2 vect2::operator-(const vect2& v) const
{
	return	vect2(_x - v._x, _y - v._y);
}

vect2& vect2::operator+=(const vect2& v)
{
	_x += v._x;
	_y += v._y;
	return (*this);
}

vect2& vect2::operator-=(const vect2& v)
{
	_x -= v._x;
	_y -= v._y;
	return (*this);
}

vect2& vect2::operator++()
{
	++_x;
	++_y;
	return (*this);
}

vect2& vect2::operator--()
{
	--_x;
	--_y;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 tmp(*this);
	++*this;
	return (tmp);
}

vect2 vect2::operator--(int)
{
	vect2 tmp(*this);
	--*this;
	return (tmp);
}

int&	vect2::operator[](int i)
{
	return i ? _y : _x;
}

const int&	vect2::operator[](int i) const
{
	return i ? _y : _x;
}

vect2	vect2::operator-() const
{
	return vect2(-_x, -_y);
}

vect2	vect2::operator*(int n) const
{
	return vect2(_x * n, _y * n);
}

vect2& vect2::operator*=(int n)
{
	_x *= n;
	_y *= n;
	return (*this);
}

bool vect2::operator==(const vect2& v) const
{
	return (_x == v._x && _y == v._y);
}

bool vect2::operator!=(const vect2& v) const
{
	return !(*this == v);
}

/** ** **/

vect2 operator*(int n, const vect2& v)
{
	return (v * n);
}

std::ostream& operator<<(std::ostream& o, const vect2& v)
{
	return (o << '{' << v[0] << ", " << v[1] << '}');
}



