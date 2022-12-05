#pragma once 
#include <Zi.h>


class ArrayStrcuture
{
private:
	Zi* array;

public:
	explicit ArrayStrcuture(int size = 0, const Zi& value = Zi()); //c - tor explicit
	ArrayStrcuture(int size, const Zi arr[] ;// c- tor
	ArrayStrcuture(const ArrayStrcuture& Other); // copy c-tor;
	~ArrayStrcuture();

	int size();
	bool empty();


};

//operator = 
//operator == , != 
//operator  + 
// operator []

