#pragma once

#include <cstddef>
#include <cstdlib>

class Vector {
public:
    Vector(double val0, double val1);

    Vector operator+(const Vector& rhs) const;
    Vector operator*(double rhs) const;
    double operator[](size_t i) const;
    

private:
    double m_val0;
    double m_val1;
};