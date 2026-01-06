#include "Drawer.h"

Drawer::Drawer(SDL_Renderer*& renderer) :
    m_renderer{renderer}
{}

void Drawer::Render(const Universe& universe) {
	for (const CelestialBody& celestialBody : universe.GetCelestialBodies())
		Render(celestialBody);
}

void Drawer::Render(const CelestialBody& celestialBody) {
    const Colour& colour = celestialBody.GetColour();

	const CircularBuffer<Vector, TRAIL_LENGTH>& trail = celestialBody.GetTrail();
	double opacity{ 0 };

	Vector lastPosition = *trail.begin();
	for (Vector position : trail) {
		SDL_SetRenderDrawColor(m_renderer, colour.m_red, colour.m_green, colour.m_blue, (int) opacity);
		SDL_RenderDrawLine(
			m_renderer,
			graphToWindowX(lastPosition[0]),
			graphToWindowY(lastPosition[1]),
			graphToWindowX(position[0]),
			graphToWindowY(position[1])
		);
		lastPosition = position;
		opacity += TRAIL_OPACITY_DIFF;
	}
}