#include "tile.h"

#include <SDL.h>

class TileType {

	public:
		TileType(SDL_Surface *surface);

		void drawAt(int x, int y);

	private:
		SDL_Surface *m_surface;

};

TileType::TileType(SDL_Surface *surface)
	: m_surface(surface) {
}

void TileType::drawAt(int x, int y) {
	
}

Tile::Tile(Tile::Type type)
	: m_type(type) {
}

