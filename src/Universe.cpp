
#include "Universe.h"

Universe::Universe() :
	m_celestialBodies{}
{
	CelestialBody sun{ 1.0, Vector{0.0, 0.0}, Vector{ 0.0, 0.0 }, COLOUR_SUN, 2 };
	CelestialBody mercury{ 1.66e-7, Vector{ 0.307, 0.0 }, Vector{ 0.0, 12.59 }, COLOUR_MERCURY, 40 };
	CelestialBody venus{ 2.45e-6, Vector{ 0.7218, 0.0 }, Vector{ 0.0, 7.39 }, COLOUR_VENUS, 60 };
	CelestialBody earth{ 3.003e-6, Vector{ 0.983, 0.0 }, Vector{ 0, 6.39 }, COLOUR_EARTH, 90 };
	CelestialBody moon{ 3.694e-8, earth.GetPosition() + Vector{ 0.00243, 0.0 }, earth.GetVelocity() + Vector{ 0.0, 0.215 }, COLOUR_MOON, 20 };
	CelestialBody mars{ 3.213e-7, Vector{ 1.382, 0.0 }, Vector{ 0.0, 5.09 }, COLOUR_MARS, 120 };
	CelestialBody jupiter{ 9.54e-4, Vector{ 4.95, 0.0 }, Vector{ 0.0, 2.89 }, COLOUR_JUPITER, 300 };
	CelestialBody saturn{ 2.86e-4, Vector{ 8.99, 0.0 }, Vector{ 0.0, 2.13 }, COLOUR_SATURN, 470 };
	CelestialBody uranus{ 4.37e-5, Vector{ 18.31, 0.0 }, Vector{ 0.0, 1.59 }, COLOUR_URANUS, 750 };
	CelestialBody neptune{ 5.15e-5, Vector{ 29.77, 0.0 }, Vector{ 0.0, 1.14 }, COLOUR_NEPTUNE, 1100 };

	Vector total_momentum;
	total_momentum = total_momentum + earth.GetVelocity() * earth.GetMass();

	sun.SetVelocity( total_momentum * (-1 / sun.GetMass()) );

	m_celestialBodies.push_back(sun);
	m_celestialBodies.push_back(mercury);
	m_celestialBodies.push_back(venus);
	m_celestialBodies.push_back(earth);
	m_celestialBodies.push_back(moon);
	m_celestialBodies.push_back(mars);
	m_celestialBodies.push_back(jupiter);
	m_celestialBodies.push_back(saturn);
	m_celestialBodies.push_back(uranus);
	m_celestialBodies.push_back(neptune);
}

void Universe::ProcessTick() {
	for (CelestialBody& celestialBody : m_celestialBodies)
		TweakVelocity(celestialBody);

	for (CelestialBody& celestialBody : m_celestialBodies)
		TweakPosition(celestialBody);
}

const std::vector<CelestialBody>& Universe::GetCelestialBodies() const {
	return m_celestialBodies;
}

void Universe::TweakVelocity(CelestialBody& celestialBody) {
	Vector acceleration;

	for (const CelestialBody& other : m_celestialBodies) {
		if (&other == &celestialBody) continue;

		Vector difference = (other.GetPosition() - celestialBody.GetPosition());
		double distance = difference.GetMagnitude();
		Vector r_hat = difference.Normalised();
		Vector modifier = r_hat * ( (G * other.GetMass()) / (distance * distance));
		acceleration = acceleration + ( modifier );
	}

	celestialBody.SetVelocity( celestialBody.GetVelocity() + (acceleration * TICK_SIZE * TIME_SPEED) );
}

void Universe::TweakPosition(CelestialBody& celestialBody) {
	celestialBody.SetPosition( celestialBody.GetPosition() + (celestialBody.GetVelocity() * TICK_SIZE * TIME_SPEED) );
}