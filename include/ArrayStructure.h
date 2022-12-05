#pragma once 
#include "Zi.h"
#include <new>
#include <iostream>

class ArrayStrcuture
{
public:
	explicit ArrayStrcuture(int size = 0, const Zi& value = Zi()); //c - tor explicit
	ArrayStrcuture(int size, const Zi arr[]);// c- tor
	ArrayStrcuture(const ArrayStrcuture& Other); // copy c-tor;
	~ArrayStrcuture();

	ArrayStrcuture& operator=(const ArrayStrcuture& Other);
	Zi& operator [](int index); // to change
	const Zi& operator [](int index) const ; // read only 

	int size()const;
	bool empty()const;

private:
	Zi* m_array;
	int m_size;
};

bool operator==(const ArrayStrcuture& , const ArrayStrcuture& );
bool operator!=(const ArrayStrcuture& , const ArrayStrcuture& );
ArrayStrcuture operator+(const ArrayStrcuture& , const ArrayStrcuture& );
ArrayStrcuture& operator+=( ArrayStrcuture& , const ArrayStrcuture& );



