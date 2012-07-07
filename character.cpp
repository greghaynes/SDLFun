#include "character.h"
#include "main.h"

Character::Character()
	: m_base(0) {
	m_clip.x = 0;
	m_clip.y = 0;
	m_clip.w = 0;
	m_clip.h = 0;

	m_pos.setX(0);
	m_pos.setY(0);
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

const Position &Character::pos(void) const {
	return m_pos;
}

void  Character::setPos(float x, float y) {
	m_pos.setX(x);
	m_pos.setY(y);
}

void Character::apply(SDL_Surface *screen) {
	SDL_Rect offset;
	offset.x = m_pos.x();
	offset.y = m_pos.y();
	SDL_BlitSurface(m_base, &m_clip, screen, &offset);
}
