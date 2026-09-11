
#pragma once
#include <iostream>

class	vect2
{	private: int _x; int _y;
	public:
	vect2(int x = 0, int y = 0);
		vect2   operator+(const vect2 v) const;
		vect2	operator-(const vect2 v) const;
	vect2&  operator+=(const vect2& v);
	vect2&  operator-=(const vect2& v);
		vect2&	operator++();
		vect2&	operator--();
	vect2   operator++(int);
	vect2   operator--(int);
		int&	operator[](int i);
		const int&	operator[](int i) const;
	vect2	operator-() const;
	vect2 	operator*(int n) const;
	vect2&	operator*=(int n);
		bool	operator==(const vect2& v) const;
		bool	operator!=(const vect2& v) const;
};

inline vect2 operator*(int n, const vect2& v)	{	return v*n;	}

inline std::ostream& operator<<(std::ostream& o, const vect2& v)
	{	return o << '{' << v[0] << ", "  << v[1] << '}';	}
