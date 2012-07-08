#include "character.h"
#include "engine.h"

Character::Character(SDL_Surface *spritesheet, const SDL_Rect &clip)
	: m_spritesheet(spritesheet) {
	m_clip.x = clip.x;
	m_clip.y = clip.y;
	m_clip.w = clip.w;
	m_clip.h = clip.h;
}

Character::~Character() {
}

const Position &Character::pos(void) const {
	return m_pos;
}

void Character::setPos(float x, float y) {
	m_pos.setX(x);
	m_pos.setY(y);
}

const Velocity &Character::vel(void) const {
	return m_vel;
}

void Character::setVel(float x, float y) {
	m_vel.setX(x);
	m_vel.setY(y);
}

void Character::update(Engine &engine) {
	m_vel.updatePos(m_pos, update_timer.get_ticks());
	update_timer.start();
	onUpdate(engine);
}

void Character::draw(Engine &engine) {
	SDL_Rect offset;
	offset.x = pos().x() - engine.camera()->x;
	offset.y = pos().y() - engine.camera()->y;

	SDL_BlitSurface(surface(), clip(), engine.screen(), &offset);
}

SDL_Surface *Character::surface(void) {
	return m_spritesheet;
}

SDL_Rect *Character::clip(void) {
	return &m_clip;
}

void Character::onUpdate(Engine &engine) {
}

