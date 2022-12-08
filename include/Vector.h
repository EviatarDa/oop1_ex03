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
	Vector operator-();



private:
	ArrayStructure m_array;

};

std::ostream& operator<<(std::ostream&, const Vector&);

Vector operator+(const Vector&, const Vector&);
Vector& operator+=(Vector&, const Vector&);

Vector operator-(const Vector&, const Vector&);
Vector& operator-=(Vector&, const Vector&);

Vector operator*(const Vector&, const Vector&);
Vector& operator*=(Vector&, const Vector&);


//scalar:
Vector operator * (const Vector&, int);
Vector& operator*=(Vector& , int );
Vector operator * ( int, const Vector&);
Vector& operator*=( int, Vector&);


bool operator==(const Vector&, const Vector&);
bool operator!=(const Vector&, const Vector&);

int max(int x, int y);
int min(int x, int y);




