#include "map.h"
#include "engine.h"
#include "settings.h"

#include <string.h>

Map::Map(int width, int height, SDL_Surface *background)
	: m_width(width)
	, m_height(height)
	, background(background)
	, m_horiz_tiles(width / TILE_WIDTH)
	, m_vert_tiles(height / TILE_HEIGHT) {
	m_tiles = new Tile**[horizTiles()];
	int i;
	for(i = 0;i<horizTiles();i++) {
		m_tiles[i] = new Tile*[vertTiles()];
		memset(m_tiles[i], 0, sizeof(Tile*)*vertTiles());
	}
}
Map::~Map() {
	int i;
	for(i = 0;i < horizTiles();i++)
		delete m_tiles[i];
	delete m_tiles;
}


int Map::width(void) const {
	return m_width;
}

int Map::height(void) const {
	return m_height;
}

int Map::vertTiles(void) const {
	return m_vert_tiles;
}

int Map::horizTiles(void) const {
	return m_horiz_tiles;
}

const Tile *Map::at(int x, int y) const {
	return m_tiles[x][y];
}

void Map::draw(Engine &engine) {
	SDL_Rect *camera = engine.camera();
	int bg_x = (-camera->x) % camera->w;
	int bg_y = (-camera->y) % camera->h;

	SDL_Rect offset;
	offset.x = bg_x;
	offset.y = bg_y;
	SDL_BlitSurface(background, engine.window(), engine.screen(), &offset);

	offset.x = bg_x;
	if(camera->y < 0)
		offset.y = bg_y - background->h;
	else
		offset.y = bg_y + background->h;
	SDL_BlitSurface(background, engine.window(), engine.screen(), &offset);

	if(camera->x < 0)
		offset.x = bg_x - background->w;
	else
		offset.x = bg_x + background->w;
	offset.y = bg_y;
	SDL_BlitSurface(background, engine.window(), engine.screen(), &offset);

	if(camera->x < 0)
		offset.x = bg_x - background->w;
	else
		offset.x = bg_x + background->w;
	if(camera->y < 0)
		offset.y = bg_y - background->h;
	else
		offset.y = bg_y + background->h;
	SDL_BlitSurface(background, engine.window(), engine.screen(), &offset);

	/* Render Tiles */
}

