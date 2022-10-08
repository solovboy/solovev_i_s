#pragma once
#ifndef RATIONAL_RATIONAL_H_20220309
#define RATIONAL_RATIONAL_H_20220309
#include <iosfwd>

class Rational
{
public:


	Rational() = default;
	Rational(int num);
	Rational(const int num, const int denom);

	bool operator == (const Rational& rhs) const;

	bool operator != (const Rational& rhs) const;

	bool operator > (const Rational& rhs) const;

	bool operator < (const Rational& rhs) const;

	bool operator >= (const Rational& rhs) const;

	bool operator <= (const Rational& rhs) const;

	Rational& operator += (const Rational& rhs);

	Rational& operator -= (const Rational& rhs);

	Rational& operator *= (const Rational& rhs);

	Rational& operator /= (const Rational& rhs);

	Rational& operator ++ ();
	Rational& operator -- ();

	Rational operator ++ (int);
	Rational operator -- (int);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

private:

	int numerator{ 0 }, denominator{ 1 };

	static const char slash = '/';

	void set(int num, int denom);

};
Rational operator+(const Rational& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs);

Rational operator*(const Rational& lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);


std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);
#endif