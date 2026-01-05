#pragma once

#include <SDL2/SDL.h>

#include "Colour.h"

#include "CelestialBody.h"


#define WINDOW_W 700
#define WINDOW_H 700

#define GRAPH_W 4
#define GRAPH_H 4

#define BODY_RADIUS_SCALE_FACTOR 1

constexpr double X_HALFRANGE = (GRAPH_W ) / 2;
constexpr double Y_HALFRANGE = (GRAPH_H ) / 2;
constexpr double WIN_TO_GRAPH_W_FACTOR = WINDOW_W / GRAPH_W; 
constexpr double WIN_TO_GRAPH_H_FACTOR = WINDOW_H / GRAPH_H;

constexpr inline int graphToWindowX(double x) {
    return round( (x + (GRAPH_W / 2) ) * (WIN_TO_GRAPH_W_FACTOR) );
}

constexpr inline int graphToWindowY(double y) {
    return WINDOW_H - round( (y + (GRAPH_H / 2) ) * (WIN_TO_GRAPH_H_FACTOR) );
}

class Drawer {

public:
    Drawer(SDL_Renderer*& renderer);

    void Render(const CelestialBody& CelestialBody);

private:
    SDL_Renderer *& m_renderer;
};