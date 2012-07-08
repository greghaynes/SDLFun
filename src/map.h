#ifndef MAP_H
#define MAP_H

#include "tile.h"

#include <SDL.h>

class Engine;

class Map {

	public:
		Map(int width, int height, SDL_Surface *background);
		~Map();

		int width(void) const;
		int height(void) const;
		const Tile *at(int x, int y) const;
		void draw(Engine &engine);

	private:
		Tile ***m_tiles;
		int m_width;
		int m_height;

		SDL_Surface *background;

};

#endif

