#include "mapfactory.h"

#include "map.h"

#include <iostream>

/*! Generate a map from a flat file.
 * The map format is as follows:
 *   2 Byte Width, 2 Byte Height (In number of tiles)
 *   1 byte per tile with the corresponding tile id
 *   1 Magic Byte 0x7D
 *   Sequence of 4 byte groups containing:
 *     character skin id
 *     ai id
 *     start tile x, start tile y
 *   1 Magic Byte 0xFF
 */
Map *MapFactory::fromFile(const char *path) {
    std::ifstream  infile(path);
    if(infile.is_open()) {

    }
}

