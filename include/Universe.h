#pragma once

#include <SDL2/SDL.h>

#include <math.h>
#include <vector>
#include <iostream>

#include "CelestialBody.h"


#define TICK_SIZE 1e-4
#define TIME_SPEED 1

constexpr double G = 4 * M_PI * M_PI;


class Universe {

public:
    Universe();

	void ProcessTick();

	const std::vector<CelestialBody>& GetCelestialBodies() const;

private:
	void TweakVelocity(CelestialBody& celestialBody);
	void TweakPosition(CelestialBody& celestialBody);

	std::vector<CelestialBody> m_celestialBodies;

};