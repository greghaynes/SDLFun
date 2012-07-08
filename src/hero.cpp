#include "hero.h"

Hero::Hero()
	: Character() {
}

void Hero::draw(SDL_Surface *screen) {
	SDL_Rect offset;
	offset.x = 640 / 2;
	offset.y = 480 / 2;
	SDL_BlitSurface(surface(), clip(), screen, &offset);
}

