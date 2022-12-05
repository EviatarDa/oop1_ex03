#pragma once
#include <"ArrayStructure.h">

class Vector
{
private:


public :
	explicit Vector(int size = 0, const Zi& init = {});
	Vector(const Zi arr[], int size);
	int size()const;


};

//operator + - 
//operator * with scalar and with vector 
//onari operator - 
//operator == !=
//operator []
//operator cout <<
