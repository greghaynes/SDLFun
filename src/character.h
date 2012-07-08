#include <SDL.h>

#include "position.h"
#include "velocity.h"
#include "timer.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Engine;

class Character {
	public:
		Character(SDL_Surface *spritesheet, const SDL_Rect &clip);
		~Character();

		const Position &pos(void) const;
		void setPos(float x, float y);
		const Velocity &vel(void) const;
		void setVel(float x, float y);

		void update(Engine &engine);
		virtual void draw(Engine &engine);

		SDL_Surface *surface(void);
		SDL_Rect *clip(void);

	protected:
		virtual void onUpdate(Engine &engine);

	private:
		Position m_pos;
		Velocity m_vel;
		SDL_Rect m_clip;
		SDL_Surface *m_spritesheet;

		Timer update_timer;
};

#endif
