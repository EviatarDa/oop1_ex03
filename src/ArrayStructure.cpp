#pragma once
#include "ArrayStructure.h" 



ArrayStructure::ArrayStructure(int size, const Zi& value)
	:m_size(size)
{
	m_array = new (std::nothrow) Zi[size];
	if (m_array == NULL)
	{
		std::cerr << "couldnt allocate memory\n";
		exit(EXIT_FAILURE);
	}

	for (int index = 0; index < size; ++index)
	{
		m_array[index] = value;
	}
}

ArrayStructure::ArrayStructure(int size, const Zi arr[])
	:m_size(size)
{
	m_array = new (std::nothrow) Zi[size];
	if (m_array == NULL)
	{
		std::cerr << "couldnt allocate memory\n";
		exit(EXIT_FAILURE);
	}

	for (int index = 0; index < size; ++index)
	{
		m_array[index] = arr[index];
	}
}

ArrayStructure::ArrayStructure(const ArrayStructure& Other)
	:ArrayStructure(Other.m_size, Other.m_array)
{
}

ArrayStructure::~ArrayStructure()
{
	delete[] m_array;
}

ArrayStructure& ArrayStructure::operator=(const ArrayStructure& Other)
{
	if (this != &Other)
	{
		m_size = Other.m_size;
		delete[] m_array;

		m_array = new (std::nothrow) Zi[m_size];
		if (m_array == NULL)
		{
			std::cerr << "couldnt allocate memory\n";
			exit(EXIT_FAILURE);

		}

		for (int index = 0; index < m_size; ++index)
		{
			m_array[index] = Other.m_array[index];
		}
	}
	return *this;
}

Zi& ArrayStructure::operator[](int index)
{
	return m_array[index];
}

const Zi& ArrayStructure::operator[](int index) const
{
	return m_array[index];
}

int ArrayStructure::size() const
{
	return m_size;
}

bool ArrayStructure::empty() const
{
	return (m_size > 0);
}

bool operator==(const ArrayStructure& arr1, const ArrayStructure& arr2)
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

bool operator!=(const ArrayStructure&array1 , const ArrayStructure& array2)
{
	return !(array1 == array2);
}

ArrayStructure operator+(const ArrayStructure&array1, const ArrayStructure&array2)
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

	return ArrayStructure(array1.size() + array2.size(), array3);
}

ArrayStructure& operator+=(ArrayStructure&arr1, const ArrayStructure&arr2)
{
	arr1 = arr1 + arr2;
	return arr1;
}



