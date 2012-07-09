#ifndef ENGINE_H
#define ENGINE_H

#include "timer.h"

class Hero;
class Position;
class Map;

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

		SDL_Surface *screen(void);
		SDL_Rect *camera(void);
		SDL_Rect *centered(void);
		SDL_Rect *window(void);
		Map &map(void);

	private:
		bool initVideo(void);
		bool initCharacters(void);
		bool initFonts(void);
		bool initWorld(void);
		void handleEvent(SDL_Event &event);
		SDL_Surface *loadImage(const char *path);
		void centerCamera(void);
		void handleFps(void);

		bool m_is_init;
		bool m_is_running;
		SDL_Surface *m_screen;
		TTF_Font *m_sys_font;	
		SDL_Color m_sys_font_color;
		SDL_Surface *m_spritesheet;
		Hero *m_hero;
		SDL_Rect m_camera;
		SDL_Rect m_centered;
		SDL_Surface *m_background;
		Map *m_map;
		SDL_Rect m_window;

		// FPS
		Timer fps_timer;
		Timer fps_update;
		bool fps_show;
		int fps_cnt;
		char fps_str[10];
		SDL_Surface *fps_surface;

};

#endif

