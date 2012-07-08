#include "hero.h"

Hero::Hero(SDL_Surface *spritesheet, const SDL_Rect &clip)
	: Character(spritesheet, clip) {
}

void Hero::draw(Engine &engine) {
	SDL_BlitSurface(surface(), clip(), engine.screen(), engine.centered());
}

