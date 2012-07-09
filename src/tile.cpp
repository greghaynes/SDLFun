#include "tile.h"

#include <SDL.h>

static SDL_Surface *_tile_surface;
static SDL_Rect _tile_clips[Tile::Last];

void init_tiles(SDL_Surface *tile_surface) {
	_tile_surface = tile_surface;

	_tile_clips[Tile::StoneSquare1].x = 15;
	_tile_clips[Tile::StoneSquare1].y = 12;
	_tile_clips[Tile::StoneSquare1].w = 27;
	_tile_clips[Tile::StoneSquare1].h = 27; 
}

Tile::Tile(Tile::Type type)
	: m_type(type) {
}

SDL_Surface *Tile::surface(void) {
	return _tile_surface;
}

SDL_Rect *Tile::clip(void) {
	return &_tile_clips[m_type];
}

