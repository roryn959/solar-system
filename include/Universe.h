#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "CelestialBody.h"


#define TICK_SIZE 0.5


class Universe {

public:
    Universe();

	void ProcessTick();

    const CelestialBody& GetSun() const { return m_sun; }
    const CelestialBody& GetEarth() const { return m_earth; }

private:
    CelestialBody m_sun;
    CelestialBody m_earth;

};