#include <stdlib.h>
#include <sstream>

#include <SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "timer.h"
#include "character.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FRAMES_PER_SECOND 60

static SDL_Surface *screen;
static SDL_Surface *background;

static int ctr_w = SCREEN_WIDTH / 2;
static int ctr_h = SCREEN_HEIGHT / 2;

static Timer fps;
static Timer fps_update;
static int fps_frame;

static Character *hero;

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
}

SDL_Surface *load_image(const char *path) {
	SDL_Surface *loadedImage;
	SDL_Surface *optimizedImage;

	loadedImage = IMG_Load(path);
	if(!loadedImage)
		return 0;

	optimizedImage = SDL_DisplayFormat(loadedImage);

	SDL_FreeSurface(loadedImage);
	return optimizedImage;
}

void init_video(void) {
	if(screen)
		SDL_FreeSurface(screen);
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16, SDL_SWSURFACE);
	if(!screen) {
		fprintf(stderr, "Unable to set 800x600 video: %s\n", SDL_GetError());
		exit(1);
	}

}

void init_chars(void) {
	SDL_Surface *loaded = load_image("data/sprites/sheet_1.png");
	if(!loaded) {
		fprintf(stderr, "Could not load sprite flie: %s\n", SDL_GetError());
		exit(1);
	}

	hero = new Character();
	hero->setPos(ctr_w - 6, ctr_h);
	hero->loadBase(loaded, 2, 32, 13, 16);
}

TTF_Font *font = NULL;
SDL_Color textColor = { 0, 255, 0, 127 };

void init_fonts(void) {
	if(TTF_Init() == -1) {
		fprintf(stderr, "Could not initialize ttf\n");
		exit(1);
	}

	font = TTF_OpenFont( "data/fonts/UniversElse-Regular.ttf", 18 );
	if(!font) {
		fprintf(stderr, "Could not open ttf font\n");
		exit(1);
	}
}

int main(int argc, char **argv) {
	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
		exit(1);
	}
	atexit(SDL_Quit);

	init_video();
	init_fonts();
	init_chars();



	// Main loop
	SDL_Event event;
	bool do_quit = false;
	fps_update.start();
	SDL_Surface *message;
	bool show_fps = false;
	char fps_msg[10];
	int last_fps = 0;
	bool fps_limit = true;
	while(!do_quit) {
		fps.start();

		hero->update();

		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_KEYDOWN:
					printf("The %s key was pressed!\n",
						SDL_GetKeyName(event.key.keysym.sym));
					switch(event.key.keysym.sym) {
						case SDLK_f:
							show_fps = !show_fps;
							break;
						case SDLK_q:
							do_quit = true;
							break;
						case SDLK_UP:
							hero->setVel(hero->vel().x(), hero->vel().y() - .05);
							break;
						case SDLK_DOWN:
							hero->setVel(hero->vel().x(), hero->vel().y() + .05);
							break;
					}
					break;
				case SDL_QUIT:
					do_quit = true;
			}
		}

		
		// Print background
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));

		// Show our hero
		hero->draw(screen);

		if(show_fps) {
			// Print fps
			sprintf(fps_msg, "%d FPS", last_fps);
			message = TTF_RenderText_Solid(font, fps_msg, textColor);
			SDL_BlitSurface(message, 0, screen, 0);
			SDL_FreeSurface(message);
		}

		if(SDL_Flip(screen) == -1) {
			fprintf(stderr, "Could not flip screen buffer\n");
			exit(1);
		}

		fps_frame++;

		if(fps_update.get_ticks() >= 1000) {
			std::stringstream caption;
			caption << "Average Frames Per Second: " << fps_frame;
			SDL_WM_SetCaption( caption.str().c_str(), NULL );
			fps_update.start();
			last_fps = fps_frame;
			fps_frame = 0;
		}

		if(fps_limit && fps.get_ticks() <= 1000 / FRAMES_PER_SECOND) {
			SDL_Delay(( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks());
		}
	}

	SDL_FreeSurface(screen);
	SDL_Quit();
}

