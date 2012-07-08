#ifndef HERO_H
#define HERO_H

#include "character.h"

class Hero 
	: public Character {

	public:
		Hero();

		void draw(SDL_Surface *screen);

};

#endif

