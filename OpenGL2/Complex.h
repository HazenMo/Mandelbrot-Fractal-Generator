#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Complex
{
private:
	float real;
	float imaginary;

public:
	Complex(float real, float imaginary);
	bool zInBounds();

	float getReal()
	{
		return real;
	}

	float getImaginary()
	{
		return imaginary;
	}
};

inline Complex operator + (Complex &lhs, Complex &rhs)
{
	return Complex(lhs.getReal() + rhs.getReal(), 
		lhs.getImaginary() + rhs.getImaginary()); 
};

inline Complex operator * (Complex& lhs, Complex& rhs)
{
	return Complex(lhs.getReal() * rhs.getReal() - lhs.getImaginary() * rhs.getImaginary(),
		lhs.getReal() * rhs.getImaginary() + lhs.getImaginary() * rhs.getReal());
};