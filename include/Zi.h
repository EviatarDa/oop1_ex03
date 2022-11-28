#pragma once

#include <iosfwd>


class Zi
{
public:
	Zi(int real = 0, int img = 0);
	int real() const;
	int imag() const;
	int norm() const;
	Zi conj() const;
	//bool dividedBy(const Zi&) const;
	Zi& operator--();
	Zi operator--(int);

private:
	int m_real;
	int m_img;

};

Zi operator+(const Zi&, const Zi&);
Zi operator-(const Zi&, const Zi&);
Zi operator*(const Zi&, const Zi&);
//Zi operator/(const Zi&, const Zi&);
bool operator==(const Zi&, const Zi&);
bool operator!=(const Zi&, const Zi&);
std::ostream& operator<<(std::ostream&, const Zi&);
