#include "engine.h"
#include "settings.h"

#include <SDL/SDL_image.h>

#include <assert.h>
#include <stdio.h>

Engine::Engine(void)
	: m_is_init(false)
	, m_is_running(false)
	, m_screen(0)
	, m_sys_font(0)
	, m_spritesheet(0)
	, m_hero(0) {
}

Engine::~Engine(void) {
	if(m_screen) SDL_FreeSurface(m_screen);
	if(m_sys_font) TTF_CloseFont(m_sys_font);
	if(m_spritesheet) SDL_FreeSurface(m_spritesheet);
	if(m_hero) delete m_hero;
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

	if(initVideo() && initFonts() && initCharacters())
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
	while(m_is_running) {
			
	}
}

void Engine::stop(void) {
	m_is_running = false;
}

bool Engine::initVideo(void) {
	m_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT,
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

	m_hero = new Hero();

	return true;
}

bool Engine::initFonts(void) {
	if(TTF_Init() == -1) {
		fprintf(stderr, "Could not initialize ttf\n");
		exit(1);
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

