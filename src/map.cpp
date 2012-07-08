#include "map.h"

#include <string.h>

Map::Map(int width, int height, SDL_Surface *background)
	: m_width(width)
	, m_height(height)
	, background(background) {
	m_tiles = new Tile**[width];
	int i;
	for(i = 0;i<width;i++) {
		m_tiles[i] = new Tile*[height];
		memset(m_tiles[i], 0, sizeof(Tile*)*height);
	}
}
Map::~Map() {
	int i;
	for(i = 0;i < m_width;i++)
		delete m_tiles[i];
	delete m_tiles;
}


int Map::width(void) const {
	return m_width;
}

int Map::height(void) const {
	return m_height;
}

const Tile *Map::at(int x, int y) const {
	return m_tiles[x][y];
}

void Map::drawAtOffset(int x, int y, SDL_Surface *screen) {
	SDL_Rect offset;
	int off_y = (y%480) + (480 / 2);
	int off_x = x + (640 / 2);
	offset.x = off_x;
	offset.y = off_y;
	SDL_BlitSurface(background, 0, screen, &offset);
	offset.y = off_y - background->h;
	offset.x = off_x;
	SDL_BlitSurface(background, 0, screen, &offset);
	offset.y = off_y + background->h;
	offset.x = off_x;
	SDL_BlitSurface(background, 0, screen, &offset);
}

