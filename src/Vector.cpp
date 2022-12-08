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

Vector Vector::operator-()
{
	Vector v(*this);
	for (int index = 0; index < m_array.size(); index++)
	{
		-(v[index]);
	}

	return v;
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
	//checks which one is bigger
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

//reuse of operator +
Vector& operator+=(Vector& v1, const Vector& v2)
{
	v1 = v1 + v2;
	return v1;
}

//reuse of operator -
Vector& operator-=(Vector& v1, const Vector&v2 )
{
	v1 = v1 - v2;
	return v1;
}


/*
Vector& Vector::operator*(int s)
{
	for (int index = 0; index < m_array.size(); index++)
	{
		m_array[index] = (m_array[index]) * s;
	}
	return *this;
}
*/

/*
Vector& Vector::operator*(Vector v, int s)
{
	return v * s;
}
*/

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

Vector operator*(const Vector& v1, int s)
{
	Vector v(v1);
	for (int index = 0; index < v1.size(); index++)
	{
		v[index] = (v1[index]) * s;
	}
	
	return v;
}

Vector& operator*=(Vector& v, int s)
{
	v = v * s;
	return v;
}

Vector operator*(int s, const Vector& v1)
{
	Vector v(v1);
	v = v1 * s;
	return v;
}

Vector& operator*=(int s, Vector&v)
{
	return v *= v * s;
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
	//check which one is longer
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
	else
	{
		for (; index < v1.size(); index++)
		{
			v3[index] = v1[index] - v2[index];
		}
		for (; index < v2.size(); index++)
		{
			v3[index] -= v2[index];
		}
	}

	return v3;
}
