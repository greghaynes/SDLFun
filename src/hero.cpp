#include "hero.h"

#include <stdio.h>

Hero::Hero(SDL_Surface *spritesheet, const SDL_Rect &clip)
    : Character(spritesheet, clip) {
}

