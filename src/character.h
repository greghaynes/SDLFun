#include <SDL.h>

#include "position.h"
#include "velocity.h"
#include "timer.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
	public:
		Character();
		~Character();

		void loadBase(SDL_Surface *base, int x, int y, int width, int height);
		const Position &pos(void) const;
		void setPos(float x, float y);
		const Velocity &vel(void) const;
		void setVel(float x, float y);

		void update(void);
		void draw(SDL_Surface *screen);

	private:
		Position m_pos;
		Velocity m_vel;
		SDL_Rect m_clip;
		SDL_Surface *m_base;

		Timer update_timer;
};

#endif
