#ifndef TILE_H
#define TILE_H

void init_tiles();

class Tile {

	public:
		enum Type {
			Greenery,
		};

		Tile(Type type);

	private:
		Type m_type;

};

#endif
