#include <iostream>
#include <sstream>
#include "rational.hpp"

using namespace std;

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

inline ostream& operator<<(ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline istream& operator>>(istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	Rational sub(lhs);
	sub -= rhs;
	return sub;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational mul(lhs);
	mul *= rhs;
	return mul;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	Rational div(lhs);
	div /= rhs;
	return div;
}

bool testParse(const string& str)
{
	istringstream istrm(str);
	Rational number;
	istrm >> number;
	string answer;

	if (istrm.good())
		answer = "success";
	else
		answer = "error";

	cout << "Read " << answer << " : " << str << " -> " << number << endl;
	return istrm.good();
}

bool testSum()
{
	Rational number1{ 10, 2 };
	Rational number2{ 15, 6 };
	Rational answer{ 15, 2 };

	bool result = (answer == (number1 + number2));
	if (result)
		cout << "Test 1 passed" << endl;
	else
		cout << "Test 1 failed" << endl;

	return result;
}

bool testSub()
{
	Rational number1{ 3, 4 };
	Rational number2{ 1, 2 };
	Rational answer{ 1, 4 };

	bool result = (answer == (number1 - number2));
	if (result)
		cout << "Test 2 passed" << endl;
	else
		cout << "Test 2 failed" << endl;

	return result;
}

bool testMul()
{
	Rational number1{ 3, -4 };
	Rational number2{ 1, 2 };
	Rational answer{ -3, 8 };

	bool result = (answer == (number1 * number2));
	if (result)
		cout << "Test 3 passed" << endl;
	else
		cout << "Test 3 failed" << endl;

	return result;
}

bool testDiv()
{
	Rational number1{ 5, 4 };
	Rational number2{ 3, 2 };
	Rational answer{ 5, 6 };

	bool result = (answer == (number1 / number2));
	if (result)
		cout << "Test 4 passed" << endl;
	else
		cout << "Test 4 failed" << endl;

	return result;
}

bool testSumEq()
{

	Rational number1{ 10, 2 };
	Rational number2{ 15, 6 };
	Rational answer{ 15, 2 };

	number1 += number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test 5 passed" << endl;
	else
		cout << "Test 5 failed" << endl;

	return result;
}

bool testSubEq()
{
	Rational number1{ 1, 2 };
	Rational number2{ 3, 4 };
	Rational answer{ -1, 4 };

	number1 -= number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test 6 passed" << endl;
	else
		cout << "Test 6 failed" << endl;

	return result;
}

bool testMulEq()
{
	Rational number1{ 1, 2 };
	Rational number2{ 3, 4 };
	Rational answer{ 3, 8 };

	number1 *= number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test 7 passed" << endl;
	else
		cout << "Test 7 failed" << endl;

	return result;
}

bool testDivEq()
{
	Rational number1{ 5, 4 };
	Rational number2{ 3, 2 };
	Rational answer{ 5, 6 };

	number1 /= number2;
	bool result = (answer == number1);
	if (result)
		cout << "Test 8 passed" << endl;
	else
		cout << "Test 8 failed" << endl;

	return result;
}

int main()
{
	testSum();
	testSub();
	testMul();
	testDiv();
	testSumEq();
	testSubEq();
	testMulEq();
	testDivEq();
	testParse("{2/4}");
	testParse("{ \n2/   4}");
	testParse("{s/4}");
}