#pragma once
#include "ArrayStructure.h"

class Vector
{
public :
	explicit Vector(int size = 0, const Zi& init = {});
	Vector(int size, const Zi arr[]);
	int size()const;
	Zi& operator [](int index);
	const Zi& operator [](int index) const; // read only 

private:
	ArrayStructure m_array;

};

std::ostream& operator<<(std::ostream&, const Vector&);


//operator + - 
//operator * with scalar and with vector 
//onari operator - 
//operator == !=

//operator cout <<
