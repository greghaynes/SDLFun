#include "character.h"
#include "engine.h"
#include "map.h"

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
	if(pos().x() > engine.map().width())
		setPos(engine.map().width(), pos().y());
	else if(pos().x() < 0)
		setPos(0, pos().y());
	if(pos().y() > engine.map().height())
		setPos(pos().x(), engine.map().height());
	else if(pos().y() < 0)
		setPos(pos().x(), 0);
	onUpdate(engine);
}

void Character::draw(Engine &engine) {
	SDL_Rect offset;
	offset.x = pos().x() - engine.camera()->x - (width() / 2);
	offset.y = pos().y() - engine.camera()->y - (height() / 2);

	fprintf(stderr, "X: %f Y: %f\n", pos().x(), pos().y());

	SDL_BlitSurface(surface(), clip(), engine.screen(), &offset);
}

SDL_Surface *Character::surface(void) {
	return m_spritesheet;
}

SDL_Rect *Character::clip(void) {
	return &m_clip;
}

int Character::width(void) const {
	return m_clip.w;
}

int Character::height(void) const {
	return m_clip.h;
}

void Character::onUpdate(Engine &engine) {
}

