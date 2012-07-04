#include <stdlib.h>

#include <SDL.h>
#include <SDL/SDL_image.h>

#define WIDTH 800
#define HEIGHT 600

static SDL_Surface *screen;

static int ctr_w = WIDTH / 2;
static int ctr_h = HEIGHT / 2;

struct  SDL_Point {
	int x;
	int y;
};

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

Character::Character()
	: m_base(0) {
	m_clip.x = 0;
	m_clip.y = 0;
	m_clip.w = 0;
	m_clip.h = 0;

	m_pos.x = 0;
	m_pos.y = 0;
}

Character::~Character() {
	if(m_base)
		SDL_FreeSurface(m_base);
}

void Character::loadBase(SDL_Surface *base, int x, int y,
                         int width, int height) {
	m_base = base;
	m_clip.x = x;
	m_clip.y = y;
	m_clip.w = width;
	m_clip.h = height;
}

const SDL_Point &Character::pos(void) const {
	return m_pos;
}

void  Character::setPos(int x, int y) {
	m_pos.x = x;
	m_pos.y = y;
}

void Character::apply(void) {
	SDL_Rect offset;
	offset.x = m_pos.x;
	offset.y = m_pos.y;
	SDL_BlitSurface(m_base, &m_clip, screen, &offset);
}

static Character *hero;

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
	screen = SDL_SetVideoMode(WIDTH, HEIGHT, 16, SDL_SWSURFACE);
	if(!screen) {
		fprintf(stderr, "Unable to set 800x600 video: %s\n", SDL_GetError());
		exit(1);
	}
}

void init_chars(void) {
	SDL_Surface *loaded = load_image("data/sheet_1.png");
	if(!loaded) {
		fprintf(stderr, "Could not load sprite flie: %s\n", SDL_GetError());
		exit(1);
	}

	hero = new Character();
	hero->setPos(ctr_w - 6, ctr_h);
	hero->loadBase(loaded, 2, 32, 13, 16);
}

int main(int argc, char **argv) {
	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
		exit(1);
	}
	atexit(SDL_Quit);

	init_video();
	init_chars();
	hero->apply();

	SDL_Event event;
	bool do_quit = false;
	while(!do_quit) {
		if(SDL_Flip(screen) == -1) {
			fprintf(stderr, "Could not flip screen buffer\n");
			exit(1);
		}
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

	SDL_FreeSurface(screen);
	SDL_Quit();
}

