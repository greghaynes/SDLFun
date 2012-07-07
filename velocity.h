#ifndef VELOCITY_H
#define VELOCITY_H

#include "position.h"

#include <stdint.h>

class Velocity
	: public Position {
	public:
		Velocity(float x=0, float y=0);

		void updatePos(Position &pos, uint32_t ticks);
};

#endif
