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

Vector& Vector::operator-()
{
	for (int index = 0; index < this->size(); index++)
	{
		-(this[index]);
	}
}

Vector& Vector::operator*(int s)
{
	for (int index = 0; index < this->size(); index++)
	{
		this[index] = this[index] * s;
	}
	// TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& cout, const Vector& v) 
{
	for (int index = 0; index < v.size(); index++)
	{
		cout << v[index] << ' ';
	}
	return cout;
}

int max(int x, int y)
{
	return x > y ? x : y;
}

int min(int x, int y)
{
	return x < y ? x : y;
}

Vector operator+(const Vector&v1, const Vector&v2)
{
	int MaxSize = max(v1.size(), v2.size());
	Vector v3(MaxSize);

	int index = 0;
	for (; index < min(v1.size(), v2.size()); index++)
	{
		v3[index] = v1[index] + v2[index];
	}

	if (v1.size() < v2.size())
	{
		for (; index < MaxSize; index++)
		{
			v3[index] = v2[index];
		}
	}
	else
	{
		for (; index < MaxSize; index++)
		{
			v3[index] = v1[index];
		}
	}
	return v3;
}






Vector& operator+=(Vector& v1, const Vector& v2)
{
	v1 = v1 + v2;
	return v1;
}

Vector& operator-=(Vector& v1, const Vector&v2 )
{
	v1 = v1 - v2;
	return v1;
}

Vector operator*(const Vector& v1, const Vector&v2)
{
	int MaxSize = max(v1.size(), v2.size());
	Vector v3(MaxSize);
	int index = 0;

	if (v1.size() > v2.size())
	{
		for (; index < v2.size(); index++)
		{
			v3[index] = v1[index] * v2[index];
		}
		for (; index < v1.size(); index++)
		{
			v3[index] = 0;
		}
	}
	else
	{
		for (; index < v1.size(); index++)
		{
			v3[index] = v2[index] * v1[index];
		}
		for (; index < v2.size(); index++)
		{
			v3[index] = 0;
		}
	}
	return v3;

}

Vector& operator*=(Vector&v1, const Vector&v2)
{
	v1 = v1 * v2;
	return v1;
}

bool operator==(const Vector&v1, const Vector&v2)
{
	if (v1.size() != v2.size())
		return false;
	else
	{
		for (int index = 0; index < v1.size(); index++)
			if (v1[index] != v2[index])
			{
				return false;
			}
		return true;
	}
}

bool operator!=(const Vector&v1, const Vector&v2)
{
	return !(v1 == v2);
}

Vector operator-(const Vector& v1, const Vector& v2)
{
	int MaxSize = max(v1.size(), v2.size());
	Vector v3(MaxSize);
	int index = 0;

	if (v1.size() > v2.size())
	{
		for (; index < v2.size(); index++)
		{
			v3[index] = v1[index] - v2[index];
		}
		for (; index < v1.size(); index++)
		{
			v3[index] = v1[index];
		}
	}
	else//////////////////////////////// todo check
	{
		for (; index < v1.size(); index++)
		{
			v3[index] = v2[index] - v1[index];
		}
		for (; index < v2.size(); index++)
		{
			v3[index] = v2[index];
		}
	}

	return v3;
}
