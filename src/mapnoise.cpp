#include "mapnoise.h"

#include <assert.h>

MapNoise::MapNoise(uint64_t seed)
    : seed_(seed)
{
}

double MapNoise::getTileValue(int x, int y) {
    uint64_t prev_seed;
    if (x == 0) {
        if (y == 0)
            return seed_;
        else {
            prev_seed = getTileValue(x, y - 1);

            if (y == -1)
                // We dont want to make a symmetrical map
                ++prev_seed;
        }
    } else if (y != 0) {
        prev_seed = getTileValue(x - 1, y);
    } else {
        assert(false);
    }

    return getNormalRand(prev_seed);
}

uint64_t MapNoise::getRand(uint64_t seed)
{
    return (uint64_t)((6364136223846793005 * seed) + 1442695040888963407);
}

double MapNoise::getNormalRand(uint64_t seed)
{
    return getRand(seed) / 1.8446744e+19L;
}
