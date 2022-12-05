#pragma once 
#include "Zi.h"
#include <new>
#include <iostream>

class ArrayStructure
{
public:
	explicit ArrayStructure(int size = 0, const Zi& value = Zi()); //c - tor explicit
	ArrayStructure(int size, const Zi arr[]);// c- tor
	ArrayStructure(const ArrayStructure& Other); // copy c-tor;
	~ArrayStructure();

	ArrayStructure& operator=(const ArrayStructure& Other);
	Zi& operator [](int index); // to change
	const Zi& operator [](int index) const ; // read only 

	int size()const;
	bool empty()const;

private:
	Zi* m_array;
	int m_size;
};

bool operator==(const ArrayStructure& , const ArrayStructure& );
bool operator!=(const ArrayStructure& , const ArrayStructure& );
ArrayStructure operator+(const ArrayStructure& , const ArrayStructure& );
ArrayStructure& operator+=(ArrayStructure& , const ArrayStructure& );



