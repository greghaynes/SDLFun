#ifndef MAP_H
#define MAP_H

#include "tile.h"

class Map {

	public:
		Map(int width, int height);
		~Map();

		int width(void) const;
		int height(void) const;
		const Tile *at(int x, int y) const;

	private:
		Tile ***m_tiles;
		int m_width;
		int m_height;

};

#endif

