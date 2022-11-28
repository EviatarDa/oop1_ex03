#pragma once

#include"Zi.h"
#include<ostream>

Zi::Zi(int real, int img) 
	: m_real(real), m_img(img)
{
}

int Zi::real() const
{
	return m_real;
}

int Zi::imag() const
{
	return m_img;
}

int Zi::norm() const
{
	return m_real*m_real + m_img*m_img;
}

Zi Zi::conj() const
{
	return Zi(m_real, -m_img);
}

Zi& Zi::operator--()
{
	m_real--;
	m_img--;
	return *this;
}

Zi Zi::operator--(int i)
{
	Zi z1(m_real, m_img);
	--*this;
	return z1;
}

bool operator==(const Zi& z1, const Zi& z2)
{
	return (z1.real() == z2.real() && z1.imag() == z2.imag());	
}

bool operator!=(const Zi& z1, const Zi& z2)
{
	return !(z1==z2);
}

std::ostream& operator<<(std::ostream& cout, const Zi& z)
{
	return cout << z.real() << " " << z.imag() << "i\n";
}

/*
bool Zi::dividedBy(const Zi& divisor) const
{
	*this *
	return false;
}
*/

Zi operator+(const Zi& z1, const Zi& z2)
{
	return Zi(z1.real() + z2.real(), z1.imag() + z2.imag());
}

Zi operator-(const Zi& z1, const Zi& z2)
{
	return Zi(z1.real() - z2.real(), z1.imag() - z2.imag());
}

Zi operator*(const Zi& z1, const Zi& z2)
{
	return Zi(z1.real()*z2.real() - z1.imag()* z2.imag(), z1.real() * z2.imag() + z1.imag() * z2.real());
}

/*
Zi operator/(const Zi& z1, const Zi& z2)
{
	return Zi((z1*z2.conj()).real() / z2.norm() , (z1 * z2.conj()).imag() / z2.norm());
}
*/

