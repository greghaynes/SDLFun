#include "position.h"

Position::Position(float x, float y)
	: m_x(x)
	, m_y(y) {
}

float Position::x(void) const {
	return m_x;
}

float Position::y(void) const {
	return m_y;
}

void Position::setX(float x) {
	m_x = x;
}

void Position::setY(float y) {
	m_y = y;
}

