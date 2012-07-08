#ifndef ENGINE_H
#define ENGINE_H

#include "hero.h"

#include <SDL.h>
#include <SDL/SDL_ttf.h>

class Engine {

	public:
		Engine(void);
		~Engine(void);

		bool init(void);
		bool isInit(void) const;

		void start(void);
		void stop(void);

	private:
		bool initVideo(void);
		bool initCharacters(void);
		bool initFonts(void);

		SDL_Surface *loadImage(const char *path);

		bool m_is_init;
		bool m_is_running;
		SDL_Surface *m_screen;
		TTF_Font *m_sys_font;	
		SDL_Color m_sys_font_color;
		SDL_Surface *m_spritesheet;
		Hero *m_hero;

};

#endif

