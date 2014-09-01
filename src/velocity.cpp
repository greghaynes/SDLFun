#include "velocity.h"

Velocity::Velocity(float x, float y)
    : Position(x, y) {
}

void Velocity::updatePos(Position &pos, uint32_t ticks) {
    pos.setX(pos.x() + (x() * ticks));
    pos.setY(pos.y() + (y() * ticks));
}

