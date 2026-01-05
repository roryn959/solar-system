#include "Universe.h"

Universe::Universe() :
    m_sun{1.0, 1, Vector{0.0, 0.0}, Vector{ 0.0, 0.0 }, COLOUR_RED }, // real radius: 0.00465
    m_earth{0.000003, 0.1, Vector{1.0, 1.0}, Vector{ 0.0, 0.0 }, COLOUR_BLUE} // real radius: 0.0000426
{
}

void Universe::ProcessTick() {
	//Vector acceleration{ -0.0005, 0.0 };
	//m_earth.SetVelocity(m_earth.GetVelocity() + acceleration);

	//std::cout << m_earth.GetVelocity()[0] << ", " << m_earth.GetVelocity()[1] << std::endl;

	m_earth.SetPosition( m_earth.GetPosition() + (m_earth.GetVelocity() * TICK_SIZE) );
}