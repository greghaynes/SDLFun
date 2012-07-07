#include "map.h"

#include <string.h>

Map::Map(int width, int height)
	: m_width(width)
	, m_height(height) {
	m_tiles = new Tile**[width];
	int i;
	for(i = 0;i<width;i++) {
		m_tiles[i] = new Tile*[height];
		memset(m_tiles[i], 0, sizeof(Tile*)*height);
	}
}

Map::~Map() {
	int i;
	for(i = 0;i < m_width;i++)
		delete m_tiles[i];
	delete m_tiles;
}

