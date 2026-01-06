
#include "Universe.h"

Universe::Universe() :
	m_celestialBodies{}
{
	CelestialBody sun{ 1.0, 0.00465, Vector{0.0, 0.0}, Vector{ 0.0, 0.0 }, COLOUR_SUN };
	CelestialBody earth{ 3.003e-6, 0.0000426, Vector{ 1.0, 0.0 }, Vector{ 0, 2 * M_PI }, COLOUR_EARTH };
	CelestialBody mars{ 3.213e-7, 0.00002, Vector{ 1.381, 0.0 }, Vector{ 0.0, 5.6 }, COLOUR_MARS };
	CelestialBody mercury{ 1.66e-7, 0.0000163, Vector{ 0.387, 0.0 }, Vector{ 0.0, 10.10 }, COLOUR_MERCURY};
	CelestialBody venus{2.45e-6, 0.0000405, Vector{ 0.723, 0.0 }, Vector{ 0.0, 7.39 }, COLOUR_VENUS};

	CelestialBody jupiter{
    9.54e-4,
    0.000467,
    Vector{ 5.204, 0.0 },
    Vector{ 0.0, 2.75 },
    COLOUR_JUPITER
};

	CelestialBody saturn{
    2.86e-4,
    0.000389,
    Vector{ 9.582, 0.0 },
    Vector{ 0.0, 2.03 },
    COLOUR_SATURN
};

CelestialBody uranus{
    4.37e-5,
    0.000169,
    Vector{ 19.201, 0.0 },
    Vector{ 0.0, 1.43 },
    COLOUR_URANUS
};

CelestialBody neptune{
    5.15e-5,
    0.000164,
    Vector{ 30.047, 0.0 },
    Vector{ 0.0, 1.14 },
    COLOUR_NEPTUNE
};

	Vector total_momentum;
	total_momentum = total_momentum + earth.GetVelocity() * earth.GetMass();

	sun.SetVelocity( total_momentum * (-1 / sun.GetMass()) );

	m_celestialBodies.push_back(sun);
	m_celestialBodies.push_back(mercury);
	m_celestialBodies.push_back(venus);
	m_celestialBodies.push_back(earth);
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