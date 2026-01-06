#include "CelestialBody.h"

CelestialBody::CelestialBody(double mass, double radius, Vector position, Vector velocity, Colour colour) :
    m_colour{colour},
    m_radius{radius},
    m_mass{mass},
    m_position{position},
	m_velocity{ velocity },
	m_trailAccumulator{0},
	m_trail(position)
{}
