#include "engine.h"
#include "settings.h"
#include "hero.h"
#include "position.h"
#include "map.h"

#include <SDL/SDL_image.h>

#include <assert.h>
#include <stdio.h>

Engine::Engine(void)
	: m_is_init(false)
	, m_is_running(false)
	, m_screen(0)
	, m_sys_font(0)
	, m_spritesheet(0)
	, m_hero(0)
	, m_map(0)
	, m_background(0) {
	m_camera.x = 0;
	m_camera.y = 0;
	m_camera.w = SCREEN_WIDTH;
	m_camera.h = SCREEN_HEIGHT;

	m_centered.x = SCREEN_WIDTH / 2;
	m_centered.y = SCREEN_HEIGHT / 2;
	m_centered.w = SCREEN_WIDTH;
	m_centered.h = SCREEN_HEIGHT;

	m_window.x = 0;
	m_window.y = 0;
	m_window.w = SCREEN_WIDTH;
	m_window.h = SCREEN_HEIGHT;
}

Engine::~Engine(void) {
	if(m_screen) SDL_FreeSurface(m_screen);
	if(m_sys_font) TTF_CloseFont(m_sys_font);
	if(m_spritesheet) SDL_FreeSurface(m_spritesheet);
	if(m_background) SDL_FreeSurface(m_background);
	if(m_hero) delete m_hero;
	if(m_map) delete m_map;
}

bool Engine::init(void) {
	if(m_is_init) {
		fprintf(stderr, "Double engine init\n");
		return false;
	}

	if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
		return false;
	}

	if(initVideo() && initFonts() && initCharacters() && initWorld())
		m_is_init = true;

	return m_is_init;
}

bool Engine::isInit(void) const {
	return m_is_init;
}

void Engine::start(void) {
	if(m_is_running) {
		fprintf(stderr, "Trying to start engine when already running.\n");
		return;
	}

	m_is_running = true;
	SDL_Event event;
	while(m_is_running) {
		while(SDL_PollEvent(&event)) {
			handleEvent(event);
		}

		m_hero->update(*this);

		m_map->draw(*this);
		m_hero->draw(*this);

		SDL_Flip(screen());
	}
}

void Engine::stop(void) {
	m_is_running = false;
}

SDL_Surface *Engine::screen(void) {
	return m_screen;
}

SDL_Rect *Engine::camera(void) {
	return &m_camera;
}

SDL_Rect *Engine::centered(void) {
	return &m_centered;
}

SDL_Rect *Engine::window(void) {
	return &m_window;
}

void Engine::setCameraPos(const Position &pos) {
	m_camera.x = pos.x();
	m_camera.y = pos.y();
}

bool Engine::initVideo(void) {
	m_screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT,
	                            16, SDL_SWSURFACE);
	if(!m_screen) {
		fprintf(stderr, "Could not init screen\n");
		return false;
	}

	return true;
}

bool Engine::initCharacters(void) {
	m_spritesheet = loadImage(SPRITESHEET);
	if(!m_spritesheet) {
		fprintf(stderr, "Could not load sprite file: %s\n", SDL_GetError());
		return false;
	}

	SDL_Rect cliprect = { 0, 32, 16, 16 };
	m_hero = new Hero(m_spritesheet, cliprect);

	return true;
}

bool Engine::initFonts(void) {
	if(TTF_Init() == -1) {
		fprintf(stderr, "Could not initialize ttf\n");
		return false;
	}

	m_sys_font = TTF_OpenFont(SYS_FONT, SYS_FONT_SIZE);
	if(!m_sys_font) {
		fprintf(stderr, "Could not open ttf font\n");
		return false;
	}

	m_sys_font_color.r = 0;
	m_sys_font_color.g = 200;
	m_sys_font_color.b = 0;

	return true;
}

bool Engine::initWorld(void) {
	m_background = loadImage("data/images/background.xcf");
	if(!m_background) {
		fprintf(stderr, "Could not load background image\n");
		return false;
	}
	m_map = new Map(1000, 1000, m_background);
	return true;
}

void Engine::handleEvent(SDL_Event &event) {
	switch(event.type) {
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym) {
				case SDLK_q:
					stop();
					break;
				case SDLK_UP:
					m_hero->setVel(m_hero->vel().x(), m_hero->vel().y() + .05);
					break;
				case SDLK_DOWN:
					m_hero->setVel(m_hero->vel().x(), m_hero->vel().y() - .05);
					break;
				case SDLK_LEFT:
					m_hero->setVel(m_hero->vel().x() + .05, m_hero->vel().y());
					break;
				case SDLK_RIGHT:
					m_hero->setVel(m_hero->vel().x() - .05, m_hero->vel().y());
					break;
			}
			break;
	}
}

SDL_Surface *Engine::loadImage(const char *path) {
	SDL_Surface *loadedImage;
	SDL_Surface *optimizedImage;

	loadedImage = IMG_Load(path);
	if(!loadedImage)
		return 0;

	optimizedImage = SDL_DisplayFormat(loadedImage);

	SDL_FreeSurface(loadedImage);
	return optimizedImage;
}

