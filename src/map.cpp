#include "map.h"
#include "engine.h"
#include "settings.h"

#include <string.h>

Map::Map(int width, int height, SDL_Surface *background)
	: m_width(width)
	, m_height(height)
	, background(background)
	, m_horiz_tiles((width / TILE_WIDTH)+1)
	, m_vert_tiles((height / TILE_HEIGHT)+1) {
	m_tiles = new Tile**[horizTiles()];
	int i;
	for(i = 0;i<horizTiles();i++) {
		m_tiles[i] = new Tile*[vertTiles()];
		memset(m_tiles[i], 0, sizeof(Tile*)*vertTiles());
	}

	m_tiles[1][5] = new Tile(Tile::StoneSquare1);
	m_tiles[2][5] = new Tile(Tile::StoneSquare1);
	m_tiles[3][5] = new Tile(Tile::StoneSquare1);
	m_tiles[4][5] = new Tile(Tile::StoneSquare1);
	m_tiles[5][5] = new Tile(Tile::StoneSquare1);

	m_tiles[10][15] = new Tile(Tile::Brick1);
	m_tiles[11][15] = new Tile(Tile::Brick1);
	m_tiles[12][15] = new Tile(Tile::Brick1);
	m_tiles[13][15] = new Tile(Tile::Brick1);
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

Tile *Map::at(int x, int y) {
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
	int tile_x = camera->x / TILE_WIDTH;
	int start_tile_y = camera->y / TILE_HEIGHT;
	int pos_x = tile_x * TILE_WIDTH;
	int start_pos_y = start_tile_y * TILE_HEIGHT;
	int tile_y, pos_y;
	Tile *t;
	while (pos_x < camera->x + camera->w) {
		pos_y = start_pos_y;
		tile_y = start_tile_y;
		while (pos_y < camera->y + camera->h) {
			t = at(tile_x, tile_y);
			if(t) {
				offset.x = pos_x - camera->x;
				offset.y = pos_y - camera->y;
				SDL_BlitSurface(t->surface(), t->clip(), engine.screen(), &offset);
			}
			pos_y += TILE_HEIGHT;
			tile_y++;
		}
		pos_x += TILE_WIDTH;
		tile_x++;
	}
}

