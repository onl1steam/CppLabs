#include <iostream>
#include <sstream>

class Rational
{
public:
	Rational() = default;
	explicit Rational(const int numerator);
	Rational(const int numerator, const int denominator);

	int getNumerator();
	void setNumerator(int num);

	int getDenominator();
	void setDenominator(int den);

	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;

	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs);

	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs);

	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs);

	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int rhs);

	void normalize();

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrim);

	static const char leftBrace{ '{' };
	static const char separator{ '/' };
	static const char rightBrace{ '}' };
private:
	int num{ 0 };
	int den{ 1 };
};