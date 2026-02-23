#ifndef VECT2_HPP
# define VECT2_HPP

#include <iostream>

class vect2
{
	public:

	int x;
	int y;

	vect2();
	vect2(int a,  int b);
	vect2(const vect2 &other);
	vect2 &operator=(const vect2 &other);
	~vect2();

	vect2 operator+(const vect2 &other) const;
	vect2 operator-(const vect2 &other) const;

	vect2 &operator+=(const vect2 &other);
	vect2 &operator-=(const vect2 &other);

	vect2 operator*(int scalar) const;
	vect2 &operator*=(int scalar);

	bool operator==(const vect2 &other) const;
	bool operator!=(const vect2 &other) const;

	vect2 operator-() const;

	vect2 &operator++();
	vect2 operator++(int);
	vect2 &operator--();
	vect2 operator--(int);

	int &operator[](size_t index);
	const int &operator[](size_t index) const;

};

vect2 operator*(int scalar, const vect2 &v);

std::ostream &operator<<(std::ostream &os, const vect2 &obj);

#endif
