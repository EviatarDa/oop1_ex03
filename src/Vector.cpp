#pragma once
#include "Vector.h"

Vector::Vector(int size, const Zi& init)
	:m_array(size, init)
{
}

Vector::Vector( int size, const Zi arr[]) 
	:m_array(size, arr)
{
}

int Vector::size() const
{
	return m_array.size();
}

Zi& Vector::operator[](int index)
{
	return m_array[index];
}

const Zi& Vector::operator[](int index) const
{
	return m_array[index];
}

std::ostream& operator<<(std::ostream&, const Vector& v)
{
	for (int index = 0; index < v.size(); index++)
	{
		std::cout << v[index] << ' ';
	}
}
