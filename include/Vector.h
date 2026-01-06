#pragma once

#include <cstddef>
#include <cstdlib>
#include <math.h>
#include <iostream>

class Vector {
public:
	Vector();
    Vector(double val0, double val1);
	Vector(const Vector& rhs);

	Vector 					Normalised() const;
	double 					GetMagnitude() const;

    Vector 					operator+(const Vector& rhs) const;
	Vector					operator-(const Vector& rhs) const;
    Vector 					operator*(double rhs) const;
    double 					operator[](size_t i) const;
	friend std::ostream& 	operator<<(std::ostream& os, const Vector& vector);
    

private:
    double m_val0;
    double m_val1;
};