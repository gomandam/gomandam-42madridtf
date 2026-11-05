/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 01:46:59 by gomandam          #+#    #+#             */
/*   Updated: 2026/09/05 03:34:10 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef VECT2_HPP	#define VECT2_HPP	#endif


#pragma	once
#include <iostream>

class	vect2
{
	private:
		int	_x;
		int	_y;
	public:
		vect2(int x = 0, int y = 0);

		vect2   operator+(const vect2 vect2) const;
		vect2   operator-(const vect2 vect2) const;

		vect2&	operator+=(const vect2& v);
		vect2&	operator-=(const vect2& v);

		vect2&	operator++();
		vect2&  operator--();

		vect2	operator++(int);
		vect2	operator--(int);

		int&		operator[](int i);
		const int&	operator[](int i) const;

		vect2   operator-() const;
		vect2   operator*(int n) const;
		vect2&   operator*=(int n);

		bool    operator==(const vect2& v) const;
		bool    operator!=(const vect2& v) const;

};

inline	vect2	operator*(int n, const vect2& v)
{
	return v * n;
}

inline std::ostream& operator<<(std::ostream& o, const vect2& v)
{
	return o << '{' << v[0] << ", " << v[1] << '}';
}



