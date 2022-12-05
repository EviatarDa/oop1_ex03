#pragma once
#include "ArrayStructure.h"



ArrayStrcuture::ArrayStrcuture(int size, const Zi& value = Zi()):
	m_size(size)
{
	m_array = new (std::nothrow) Zi[size];
	if (m_array == NULL)
	{
		std::cerr << "couldnt allocate memory\n";
	}

	for (int index = 0; index < size; ++index)
	{
		m_array[index] = value;
	}
}

ArrayStrcuture::ArrayStrcuture(int size, const Zi arr[]):
	m_size(size)
{
	m_array = new (std::nothrow) Zi[size];
	if (m_array == NULL)
	{
		std::cerr << "couldnt allocate memory\n";
	}

	for (int index = 0; index < size; ++index)
	{
		m_array[index] = arr[index];
	}
}

ArrayStrcuture::ArrayStrcuture(const ArrayStrcuture& Other):
	ArrayStrcuture(Other.m_size, Other.m_array)
{
}

ArrayStrcuture::~ArrayStrcuture()
{
	delete[] m_array;
}

ArrayStrcuture& ArrayStrcuture::operator=(const ArrayStrcuture& Other)
{
	if (this != &Other)
	{
		m_size = Other.m_size;
		delete[] Other.m_array;

		m_array = new (std::nothrow) Zi[m_size];
		if (m_array == NULL)
		{
			std::cerr << "couldnt allocate memory\n";
		}

		for (int index = 0; index < m_size; ++index)
		{
			m_array[index] = Other.m_array[index];
		}

	}
}

Zi& ArrayStrcuture::operator[](int index)
{
	return m_array[index];
}

const Zi& ArrayStrcuture::operator[](int index) const
{
	return m_array[index];
}

int ArrayStrcuture::size() const
{
	return m_size;
}

bool ArrayStrcuture::empty() const 
{
	return (m_size > 0);
}

bool operator==(const ArrayStrcuture& arr1, const ArrayStrcuture& arr2)
{
	if (arr1.size() != arr2.size())
		return false;
	else
	{
		for (int index =0 ; index < arr1.size() ; index++)
		if ( arr1[index] != arr2[index] )
		{
			return false;
		}
		return true;
	}
}

bool operator!=(const ArrayStrcuture&array1 , const ArrayStrcuture& array2)
{
	return !(array1 == array2);
}

ArrayStrcuture operator+(const ArrayStrcuture&array1, const ArrayStrcuture&array2)
{
	Zi* array3 = new (std::nothrow) Zi[array1.size() + array2.size()];
	int index = 0;
	for (; index < array1.size(); index++)
	{
		array3[index] = array1[index];
	}
	for (int index2 = 0; index < array2.size(); index2++, index++)
	{
		array3[index] = array2[index2];
	}

	return ArrayStrcuture(array1.size() + array2.size(), array3);
}

ArrayStrcuture& operator+=(ArrayStrcuture&arr1, const ArrayStrcuture&arr2)
{
	arr1 = arr1 + arr2;
	return arr1;
}



