#include "Vector.h"

Vector::Vector(double val0, double val1) :
    m_val0{ val0 },
    m_val1{ val1 }
{}

Vector Vector::operator+(const Vector& rhs) const {
    return Vector{ m_val0 + rhs.m_val0, m_val1 + rhs.m_val1 };
}

Vector Vector::operator*(double rhs) const {
    return Vector{ m_val0 * rhs, m_val1 * rhs };
}

double Vector::operator[](size_t i) const {
    switch (i) {
        case 0:
            return m_val0;
        case 1:
            return m_val1;
        default:
            std::exit(1);
    }
}