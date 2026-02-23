#include "vect2.hpp"

vect2::vect2() : x(0), y(0)
{};

vect2::vect2(int a, int b) : x(a), y(b)
{};

vect2::vect2(const vect2 &other) : x(other.x), y(other.y)
{};

vect2 &vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return (*this);
};

vect2::~vect2()
{};

vect2 vect2::operator+(const vect2 &other) const
{
	return vect2(x + other.x, y + other.y);
};

vect2 vect2::operator-(const vect2 &other) const
{
	return vect2(x - other.x, y - other.y);
};

vect2 &vect2::operator+=(const vect2 &other)
{
	x += other.x;
	y += other.y;
	return (*this);
};

vect2 &vect2::operator-=(const vect2 &other)
{
	x -= other.x;
	y -= other.y;
	return (*this);
};

vect2 vect2::operator*(int scalar) const
{
	return vect2(x * scalar, y * scalar);
}

vect2 &vect2::operator*=(int scalar)
{
	x *= scalar;
	y *= scalar;
	return (*this);
}

bool vect2::operator==(const vect2 &other) const
{
	return x == other.x && y == other.y;
}

bool vect2::operator!=(const vect2 &other) const
{
	return !(*this == other);
}

vect2 vect2::operator-() const
{
	return vect2(-x, -y);
}

vect2 &vect2::operator++()
{
	++x;
	++y;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 tmp(*this);
	++(*this);
	return (tmp);
}

vect2 &vect2::operator--()
{
	--x;
	--y;
	return (*this);
}

vect2 vect2::operator--(int)
{
	vect2 tmp(*this);
	--(*this);
	return (tmp);
}

int &vect2::operator[](size_t index)
{
	if (index == 0)
		return (x);
	return (y);
}

const int &vect2::operator[](size_t index) const
{
	if (index == 0)
		return (x);
	return (y);
}

vect2 operator*(int scalar, const vect2 &v)
{
	return vect2(v.x * scalar, v.y * scalar);
}

std::ostream &operator<<(std::ostream &os, const vect2 &obj)
{
	os << "{" << obj.x << ", " << obj.y << "}";
	return (os);
}
