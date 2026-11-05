/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 20:31:37 by gomandam          #+#    #+#             */
/*   Updated: 2026/09/02 20:31:43 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
private:
    int _x;
    int _y;

public:
    vect2(int x = 0, int y = 0);

    vect2 operator+(const vect2& v) const;
    vect2 operator-(const vect2& v) const;
    vect2 operator*(int n) const;
    vect2 operator-() const;

    vect2& operator+=(const vect2& v);
    vect2& operator-=(const vect2& v);
    vect2& operator*=(int n);

    vect2& operator++();
    vect2 operator++(int);
    vect2& operator--();
    vect2 operator--(int);

    bool operator==(const vect2& v) const;
    bool operator!=(const vect2& v) const;

    int& operator[](int i);
    const int& operator[](int i) const;
};

vect2 operator*(int n, const vect2& v);
std::ostream& operator<<(std::ostream& o, const vect2& v);

#endif

