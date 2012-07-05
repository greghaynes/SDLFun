#include <SDL.h>

#include "point.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
	public:
		Character();
		~Character();

		void loadBase(SDL_Surface *base, int x, int y, int width, int height);
		const SDL_Point &pos(void) const;
		void setPos(int x, int y);
		void apply(void);

	private:
		SDL_Point m_pos; // Position of bottom left corner
		SDL_Rect m_clip;
		SDL_Surface *m_base;
};

#endif
