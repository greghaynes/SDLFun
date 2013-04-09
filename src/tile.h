#ifndef TILE_H
#define TILE_H

#include <SDL.h>

void init_tiles(SDL_Surface *tile_surface);

class Tile {

	public:
		enum Type {
            Empty,
			StoneSquare1,
			Brick1,
			Last,
		};

		Tile(Type type);
		SDL_Surface *surface(void);
		SDL_Rect *clip(void);

	private:
		Type m_type;

};

#endif
