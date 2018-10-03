#include <iostream>
#include <sstream>
#include "rational.hpp"

using namespace std;


Rational::Rational(const int numerator)
{
	setNumerator(numerator);
	setDenominator(1);
}

Rational::Rational(const int numerator, const int denominator)
{
	setNumerator(numerator);
	setDenominator(denominator);
	normalize();
}


int Rational::getNumerator()
{
	return num;
}

void Rational::setNumerator(int numerator)
{
	num = numerator;
}

int Rational::getDenominator()
{
	return den;
}

void Rational::setDenominator(int denominator)
{
	if (den != 0)
	{
		den = denominator;
	}
	else
	{
		throw std::exception("Divide by zero exception");
	}
}

bool Rational::operator==(const Rational& rhs) const
{
	return (num * rhs.den - rhs.num * den) == 0;
}

bool Rational::operator!=(const Rational& rhs) const
{
	return !operator==(rhs);
}

Rational& Rational::operator+=(const int rhs)
{
	return operator+=(Rational(rhs));
}

Rational& Rational::operator-=(const int rhs)
{
	return operator-=(Rational(rhs));
}

Rational& Rational::operator*=(const int rhs)
{
	return operator*=(Rational(rhs));
}

Rational& Rational::operator/=(const int rhs)
{
	return operator/=(Rational(rhs));
}

Rational& Rational::operator+=(const Rational& rhs)
{
	num = num * rhs.den + rhs.num * den;
	den *= rhs.den;
	normalize();
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
	num = num * rhs.den - rhs.num * den;
	den *= rhs.den;
	normalize();
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
	num *= rhs.num;
	den *= rhs.den;
	normalize();
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
	num *= rhs.den;
	den *= rhs.num;
	normalize();
	return *this;
}

ostream& Rational::writeTo(ostream& ostrm) const
{
	ostrm << leftBrace << num << separator << den << rightBrace;
	return ostrm;
}

istream& Rational::readFrom(istream& istrm)
{
	char leftBrace(0);
	int numerator(0);
	char separator(0);
	int denominator(0);
	char rightBrace(0);

	istrm >> leftBrace >> numerator >> separator >> denominator >> rightBrace;

	if (istrm.good())
	{
		if ((Rational::leftBrace == leftBrace) && (Rational::separator == separator)
			&& (Rational::rightBrace == rightBrace))
		{
			num = numerator;
			den = denominator;
		}
		else
		{
			istrm.setstate(ios_base::failbit);
		}
	}
	return istrm;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void Rational::normalize()
{
	if (num != 0 && den != 0)
	{
		int div = gcd(num, den);
		num /= div;
		den /= div;
	}

	if (den < 0)
	{
		num *= -1;
		den *= -1;
	}
}