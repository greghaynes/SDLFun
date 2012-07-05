#include "character.h"
#include "main.h"

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
	SDL_BlitSurface(m_base, &m_clip, get_screen(), &offset);
}
