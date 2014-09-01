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
}

