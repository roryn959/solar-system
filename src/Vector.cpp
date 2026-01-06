#include "Vector.h"

Vector::Vector() :
	m_val0{ 0 },
	m_val1{ 0 }
{}

Vector::Vector(double val0, double val1) :
    m_val0{ val0 },
    m_val1{ val1 }
{}

Vector::Vector(const Vector& rhs) :
	m_val0{ rhs.m_val0 },
	m_val1{ rhs.m_val1 }
{}

Vector Vector::Normalised() const {
	double magnitude = hypot(m_val0, m_val1);
	
	return Vector{ m_val0 / magnitude, m_val1 / magnitude };
}

double Vector::GetMagnitude() const {
	return hypot(m_val0, m_val1);
}

Vector Vector::operator+(const Vector& rhs) const {
    return Vector{ m_val0 + rhs.m_val0, m_val1 + rhs.m_val1 };
}

Vector Vector::operator-(const Vector& rhs) const {
	return Vector{ m_val0 - rhs.m_val0, m_val1 - rhs.m_val1 };
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

std::ostream& operator<<(std::ostream& os, const Vector& vector) {
	os << "(" << vector.m_val0 << ", " << vector.m_val1 << ")" << std::endl;
	return os;
}