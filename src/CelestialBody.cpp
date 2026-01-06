#include "CelestialBody.h"

CelestialBody::CelestialBody(double mass, Vector position, Vector velocity, Colour colour, int trailSize) :
    m_colour{colour},
    m_mass{mass},
    m_position{position},
	m_velocity{ velocity },
	m_trailAccumulator{0},
	m_trail(position, trailSize)
{}
