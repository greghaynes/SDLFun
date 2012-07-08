#ifndef HERO_H
#define HERO_H

#include "character.h"
#include "engine.h"

class Hero 
	: public Character {

	public:
		Hero(SDL_Surface *spritesheet, const SDL_Rect &clip);

		void draw(Engine &engine);

	protected:
		void onUpdate(Engine &engine);

};

#endif

