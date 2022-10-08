#pragma once
#ifndef COMPLEX_COMPLEX_H_20220309
#define COMPLEX_COMPLEX_H_20220309
#include <iosfwd>
#include <limits>
struct Complex
{
	double re{ 0 }, im{ 0 };

	Complex() = default;
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);

	bool operator == (const Complex& rhs) const;

	bool operator != (const Complex& rhs) const;

	Complex& operator += (const Complex& rhs);
	Complex& operator += (double rhs);
	
	Complex& operator -= (const Complex& rhs);
	Complex& operator -= (double rhs);

	Complex& operator *= (const Complex& rhs);
	Complex& operator *= (double rhs);

	Complex& operator /= (const Complex& rhs);
	Complex& operator /= (double rhs);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	static constexpr double k2Eps{ 2.0 * std::numeric_limits<double>::epsilon() };

	static const char _prefix = '{', _separator = ',', _postfix = '}'; 
};
bool operator == (double lhs, const Complex& rhs);
bool operator == (const Complex& lhs, double rhs);

bool operator != (double lhs, const Complex& rhs);
bool operator != (const Complex& lhs, double rhs);

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(double lhs, const Complex& rhs);
Complex operator+(const Complex& lhs,double rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(double lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, double rhs);
Complex operator-(const Complex& lhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(double lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, double rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(double lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, double rhs);

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
std::istream& operator>>(std::istream& istrm, Complex& rhs);
#endif