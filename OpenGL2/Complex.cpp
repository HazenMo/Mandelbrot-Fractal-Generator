#include "Complex.h"

Complex::Complex(float real, float imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

bool Complex::zInBounds()
{
	if (real > 2 || real < -2 || imaginary > 2 || imaginary < -2) 
	{
		return false;
	}
}