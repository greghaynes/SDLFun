#include <stdlib.h>

#include "SDL.h"

void init_video(void) {
	SDL_Surface *screen;
	screen = SDL_SetVideoMode(800, 600, 16, SDL_SWSURFACE);
	if(!screen) {
		fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
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

	SDL_Event event;
	bool do_quit = false;
	while(!do_quit) {
		SDL_WaitEvent(&event);

		switch(event.type) {
			case SDL_KEYDOWN:
				printf("The %s key was pressed!\n",
					SDL_GetKeyName(event.key.keysym.sym));
				break;
			case SDL_QUIT:
				do_quit = true;
		}
	}

	exit(0);
}

