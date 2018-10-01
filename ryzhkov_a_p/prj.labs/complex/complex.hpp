#include <iostream>
#include <sstream>

struct Complex
{
	Complex() = default;
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);

	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const;

	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs);

	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs);

	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs);

	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrim);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};