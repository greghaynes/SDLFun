#ifndef POSITION_H
#define POSITION_H

class Position {
	public:
		Position(float x=0, float y=0);

		float x(void) const;
		float y(void) const;

		void setX(float x);
		void setY(float y);

	private:
		float m_x;
		float m_y;
};

#endif

