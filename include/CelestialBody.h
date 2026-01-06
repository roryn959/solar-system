#pragma once

#include <SDL2/SDL.h>

#include "CircularBuffer.h"
#include "Colour.h"
#include "Vector.h"


#define TRAIL_LENGTH 100
#define TRAIL_INTERVAL 100


class CelestialBody {

public:
    CelestialBody(double mass, double radius, Vector position, Vector velocity, Colour colour);

    inline const Colour& 								GetColour() 	const 	{ return m_colour; }
    inline double 										GetMass() 		const 	{ return m_mass; }
    inline double 										GetRadius() 	const 	{ return m_radius; }
    inline const Vector&								GetPosition() 	const 	{ return m_position; }
	inline const Vector&								GetVelocity() 	const 	{ return m_velocity; }
	inline CircularBuffer<Vector, TRAIL_LENGTH>& 		GetTrail() 				{ return m_trail; }
	inline const CircularBuffer<Vector, TRAIL_LENGTH>& 	GetTrail() 		const	{ return m_trail; }

	inline void				SetColour(Colour colour) 		{ m_colour = colour; }
    inline void				SetMass(double mass) 			{ m_mass = mass; }
    inline void 			SetRadius(double radius) 		{ m_radius = radius; }

    inline void 			SetPosition(Vector position) 	{
		++m_trailAccumulator;
		if (m_trailAccumulator == TRAIL_INTERVAL) {
			m_trail.push(position);
			m_trailAccumulator = 0;
		}

		m_position = position;
	}

	inline void				SetVelocity(Vector velocity)	{ m_velocity = velocity; }

private:
    Colour  m_colour;

    double	m_mass;
    double  m_radius;
    Vector	m_position;
    Vector	m_velocity;

	int										m_trailAccumulator;
	CircularBuffer<Vector, TRAIL_LENGTH> 	m_trail;

};