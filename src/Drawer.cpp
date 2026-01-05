#include "Drawer.h"

Drawer::Drawer(SDL_Renderer*& renderer) :
    m_renderer{renderer}
{}

void Drawer::Render(const CelestialBody& celestialBody) {
    const Colour& colour = celestialBody.GetColour();

    SDL_SetRenderDrawColor(m_renderer, colour.m_red, colour.m_green, colour.m_blue, SDL_ALPHA_OPAQUE);

    SDL_Rect rect;
	const Vector& position = celestialBody.GetPosition();
    rect.x = graphToWindowX(position[0]);
    rect.y = graphToWindowY(position[1]);
    rect.w = 5;
    rect.h = 5;

    SDL_RenderDrawRect(m_renderer, &rect);
}