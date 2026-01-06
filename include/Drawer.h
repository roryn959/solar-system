#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "CelestialBody.h"
#include "CircularBuffer.h"
#include "Colour.h"
#include "Universe.h"


#define WINDOW_W 800
#define WINDOW_H 800

#define GRAPH_W 70
#define GRAPH_H 70

constexpr double 	X_HALFRANGE 			= (GRAPH_W ) / 2;
constexpr double 	Y_HALFRANGE 			= (GRAPH_H ) / 2;
constexpr double 	WIN_TO_GRAPH_W_FACTOR 	= WINDOW_W / GRAPH_W; 
constexpr double 	WIN_TO_GRAPH_H_FACTOR 	= WINDOW_H / GRAPH_H;

// For moon closeup, subtract 2200 from both these functions and adjust time. Change graph width and height to 0.25.
constexpr inline int graphToWindowX(double x) { return round( (x + (GRAPH_W / 2) ) * (WIN_TO_GRAPH_W_FACTOR) ); }

constexpr inline int graphToWindowY(double y) { return WINDOW_H - round( (y + (GRAPH_H / 2) ) * (WIN_TO_GRAPH_H_FACTOR) ); }

class Drawer {

public:
    Drawer(SDL_Renderer*& renderer);

	void Render(const Universe& universe);
    void Render(const CelestialBody& celestialBody);

private:
    SDL_Renderer *& m_renderer;
};