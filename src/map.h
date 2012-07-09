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
		int vertTiles(void) const;
		int horizTiles(void) const;
		const Tile *at(int x, int y) const;
		void draw(Engine &engine);

	private:
		int m_width;
		int m_height;
		int m_horiz_tiles;
		int m_vert_tiles;
		SDL_Surface *background;
		Tile ***m_tiles;

};

#endif

