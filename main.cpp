#include <stdlib.h>
#include <sstream>

#include <SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define WIDTH 800
#define HEIGHT 600
#define FRAMES_PER_SECOND 60

static SDL_Surface *screen;
static SDL_Surface *background;

static int ctr_w = WIDTH / 2;
static int ctr_h = HEIGHT / 2;

class Timer {
	public:
		Timer();

		void start();
		void stop();
		void pause();
		void unpause();
		int get_ticks();
		bool is_started();
		bool is_paused(); 

	private:
		int startTicks;
		int pausedTicks;
		bool paused;
		bool started;
};

Timer::Timer() {
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}

void Timer::start() { 
	started = true;
	paused = false;
	startTicks = SDL_GetTicks();
}

void Timer::stop() {
	started = false;
	paused = false;
}

int Timer::get_ticks() {
	if( started == true ) {
		if( paused == true ) {
			return pausedTicks;
		} else {
			return SDL_GetTicks() - startTicks;
		}
	}
	return 0;
}

void Timer::pause() {
	if( ( started == true ) && ( paused == false ) ) {
		paused = true;
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void Timer::unpause() {
	if( paused == true ) {
		paused = false;
		startTicks = SDL_GetTicks() - pausedTicks;
		pausedTicks = 0;
	}
}

bool Timer::is_started() {
	return started;
}

bool Timer::is_paused() {
	return paused;
}

static Timer fps;
static Timer fps_update;
static int fps_frame;

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

	if(TTF_Init() == -1) {
		fprintf(stderr, "Could not initialize ttf\n");
		exit(1);
	}

	init_chars();
	hero->apply();

	TTF_Font *font = NULL;
	font = TTF_OpenFont( "data/fonts/UniversElse-Regular.ttf", 28 );
	if(!font) {
		fprintf(stderr, "Could not open ttf font\n");
		exit(1);
	}

	SDL_Color textColor = { 0, 255, 255, 0 };
	char fps_msg[10];

	int last_fps = 0;

	// Main loop
	SDL_Event event;
	bool do_quit = false;
	fps_update.start();
	SDL_Surface *message;
	while(!do_quit) {
		fps.start();

		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_KEYDOWN:
					printf("The %s key was pressed!\n",
						SDL_GetKeyName(event.key.keysym.sym));
					break;
				case SDL_QUIT:
					do_quit = true;
			}
		}

		
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));

		hero->apply();

		// Print fps
		sprintf(fps_msg, "%d FPS", last_fps);
		message = TTF_RenderText_Solid(font, fps_msg, textColor);
		SDL_BlitSurface(message, 0, screen, 0);
		SDL_FreeSurface(message);

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

		if(fps.get_ticks() <= 1000 / FRAMES_PER_SECOND) {
			SDL_Delay(( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks());
		}
	}

	SDL_FreeSurface(screen);
	SDL_Quit();
}
