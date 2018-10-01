#include <iostream>
#include <sstream>
#include "complex.hpp"

using namespace std;

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);

Complex::Complex(const double real) : Complex(real, 0.0)
{

}

Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary)
{
	re = real;
	im = imaginary;
}

bool Complex::operator==(const Complex& rhs) const
{
	return (re == rhs.re) && (im == rhs.im);
}

bool Complex::operator!=(const Complex& rhs) const
{
	return !operator==(rhs);
}

Complex& Complex::operator+=(const double rhs)
{
	return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const double rhs)
{
	return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const double rhs)
{
	return operator*=(Complex(rhs));
}

Complex& Complex::operator/=(const double rhs)
{
	return operator/=(Complex(rhs));
}

Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	int tempRe = re;
	re = (re * rhs.re) - (im * rhs.im);
	im = (tempRe * rhs.im) + (im * rhs.re);
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
	int tempRe = re;
	re = ((re * rhs.re) + (im * rhs.im)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
	im = ((im * rhs.re) - (tempRe * rhs.im)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
	return *this;
}

ostream& Complex::writeTo(ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

istream& Complex::readFrom(istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(ios_base::failbit);
		}
	}
	return istrm;
}
