#include <SDL.h>

#include "position.h"
#include "velocity.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
	public:
		Character();
		~Character();

		void loadBase(SDL_Surface *base, int x, int y, int width, int height);
		const Position &pos(void) const;
		void setPos(float x, float y);
		void apply(SDL_Surface *screen);

	private:
		Position m_pos;
		Velocity m_vel;
		SDL_Rect m_clip;
		SDL_Surface *m_base;
};

#endif
