#pragma once

#include <SDL2/SDL.h>

#include "Colour.h"
#include "Vector.h"


class CelestialBody {

public:
    CelestialBody(double mass, double radius, Vector position, Vector velocity, Colour colour);

    inline const Colour& 	GetColour() 	const 	{ return m_colour; }
    inline double 			GetMass() 		const 	{ return m_mass; }
    inline double 			GetRadius() 	const 	{ return m_radius; }
    inline const Vector&	GetPosition() 	const 	{ return m_position; }
	inline const Vector&	GetVelocity() 	const 	{ return m_velocity; }

	inline void				SetColour(Colour colour) 		{ m_colour = colour; }
    inline void				SetMass(double mass) 			{ m_mass = mass; }
    inline void 			SetRadius(double radius) 		{ m_radius = radius; }
    inline void 			SetPosition(Vector position) 	{ m_position = position; }
	inline void				SetVelocity(Vector velocity)	{ m_velocity = velocity; }

private:
    Colour  m_colour;

    double	m_mass;
    double  m_radius;
    Vector	m_position;
    Vector	m_velocity;

};