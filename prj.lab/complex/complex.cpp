#include <complex/complex.h>
#include <iostream>
#include <cmath>
#include <limits>
Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{
}
Complex::Complex(const double real)
	: re(real)
	, im(0.0)
{
}
bool Complex::operator == (const Complex& rhs) const
{
	return std::abs(re - rhs.re) < k2Eps &&
		std::abs(im - rhs.im) < k2Eps;
}
bool operator == (double lhs, const Complex& rhs)
{
	return Complex(lhs) == rhs;
}
bool operator == (const Complex& lhs, double rhs)
{
	return lhs == Complex(rhs);
}
bool Complex::operator != (const Complex& rhs) const
{
	return !(*this == rhs);
}
bool operator != (double lhs, const Complex& rhs)
{
	return !(lhs == rhs);
}
bool operator != (const Complex& lhs, double rhs)
{
	return !(lhs == rhs);
}
Complex operator+(const Complex& lhs, const Complex& rhs) 
{
	Complex result(lhs);
	result += rhs;
	return result;
}
Complex operator+(double lhs, const Complex& rhs)
{
	return Complex(lhs) + rhs;
}
Complex operator+(const Complex& lhs, double rhs)
{
	Complex result(lhs);
	result += rhs;
	return result;
}
Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result -= rhs;
	return result;
}
Complex operator-(double lhs, const Complex& rhs)
{
	return Complex(lhs) - rhs;
}
Complex operator-(const Complex& lhs, double rhs)
{
	Complex result(lhs);
	result -= rhs;
	return result;
}
Complex operator*(const Complex& lhs, const Complex& rhs) 
{
	Complex result(lhs);
	result *= rhs;
	return result;
}
Complex operator*(double lhs, const Complex& rhs)
{
	return Complex(lhs) * rhs;
}
Complex operator*(const Complex& lhs, double rhs)
{
	Complex result(lhs);
	result *= rhs;
	return result;
}
Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex result(lhs);
	result /= rhs;
	return result;
}
Complex operator/(double lhs, const Complex& rhs) 
{
	return Complex(lhs) / rhs;
}
Complex operator/(const Complex& lhs, double rhs)
{
	Complex result(lhs);
	result /= rhs;
	return result;
}
Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}
Complex& Complex::operator+=(double rhs)
{
	re += rhs;
	return *this;
}
Complex& Complex::operator-=(const Complex& rhs) 
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}
Complex& Complex::operator-=(double rhs)
{
	re -= rhs;
	return *this;
}
Complex& Complex::operator*=(const Complex& rhs) 
{
	double first_real = re;
	re = re * rhs.re - im * rhs.im;
	im = im * rhs.re + first_real * rhs.im;
	return *this;
}
Complex& Complex::operator*=(double rhs)
{
	re *= rhs;
	im *= rhs;
	return *this;
}
Complex& Complex::operator/=(const Complex& rhs)
{
	double first_real = re;
	re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	im = (im * rhs.re - first_real * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	return *this;
}
Complex& Complex::operator/=(double rhs)
{
	re /= rhs;
	im /= rhs;
	return *this;
}
Complex operator-(const Complex& lhs) 
{
	Complex result(lhs);
	result *= -1;
	return result;
}
std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}
std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	return ostrm << _prefix << re << _separator << im << _postfix;
}
std::istream& Complex::readFrom(std::istream& istrm)
{
	char prefix{ '\0' };
	double _real = 0.0;
	char separator{ '\0' };
	double _img = 0.0;
	char postfix{ '\0' };
	istrm >> prefix >> _real >> separator >> _img >> postfix;
	if (istrm.good()) 
	{
		if (prefix == _prefix && separator == _separator && postfix == _postfix)
		{
			re = _real;
			im = _img;
		}
		else 
		{
			istrm.setstate(std::ios_base::failbit);
		}		
	}
	return istrm;
}
