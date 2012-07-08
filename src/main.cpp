#include <stdlib.h>
#include <sstream>

#include <SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "timer.h"
#include "character.h"
#include "hero.h"
#include "map.h"
#include "engine.h"

static Timer fps;
static Timer fps_update;
static int fps_frame;

int main(int argc, char **argv) {
	Engine e;
	if(!e.init()) {
		fprintf(stderr, "Could not start engine, exiting.\n");
		exit(1);
	}

	e.start();
/*
	SDL_Surface *bg = load_image("data/images/background.xcf");
	Map map(1000, 1024, bg);

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
						case SDLK_LEFT:
							hero->setVel(hero->vel().x() - .05, hero->vel().y());
							break;
						case SDLK_RIGHT:
							hero->setVel(hero->vel().x() + .05, hero->vel().y());
							break;
					}
					break;
				case SDL_QUIT:
					do_quit = true;
			}
		}

		// Print background
		map.drawAtOffset(-hero->pos().x(), -hero->pos().y(), screen);

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
*/
}

