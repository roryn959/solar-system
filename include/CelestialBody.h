#pragma once

#include <SDL2/SDL.h>

#include "CircularBuffer.h"
#include "Colour.h"
#include "Vector.h"



class CelestialBody {

public:
    CelestialBody(double mass, Vector position, Vector velocity, Colour colour, int trailSize);

    inline const Colour& 								GetColour() 	const 	{ return m_colour; }
    inline double 										GetMass() 		const 	{ return m_mass; }
    inline const Vector&								GetPosition() 	const 	{ return m_position; }
	inline const Vector&								GetVelocity() 	const 	{ return m_velocity; }
	inline CircularBuffer<Vector>& 						GetTrail() 				{ return m_trail; }
	inline const CircularBuffer<Vector>& 				GetTrail() 		const	{ return m_trail; }

	inline void				SetColour(Colour colour) 		{ m_colour = colour; }
    inline void				SetMass(double mass) 			{ m_mass = mass; }

    inline void 			SetPosition(Vector position) 	{
		++m_trailAccumulator;
		if (m_trailAccumulator == m_trail.GetCapacity()) {
			m_trail.Push(position);
			m_trailAccumulator = 0;
		}

		m_position = position;
	}

	inline void				SetVelocity(Vector velocity)	{ m_velocity = velocity; }

private:
    Colour  m_colour;

    double	m_mass;
    Vector	m_position;
    Vector	m_velocity;

	int									m_trailAccumulator;
	CircularBuffer<Vector> 				m_trail;

};