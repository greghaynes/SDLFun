#include "mapnoise.h"

#include <assert.h>

MapNoise::MapNoise(uint64_t seed)
    : seed_(seed)
{
}

uint64_t MapNoise::getSeed() const {
    return seed_;
}

double MapNoise::getTileValue(int x, int y) {
    return normalizeRand(getTileValue_(x, y));
}

double MapNoise::getTileValue(int x, int y) const {
    return normalizeRand(getTileValue_(x, y));
}

uint64_t MapNoise::getRand(uint64_t seed) const {
    return (uint64_t)((6364136223846793005 * seed) + 1442695040888963407);
}

double MapNoise::normalizeRand(uint64_t rand) const {
    return rand / 1.8446744e+19L;
}

uint64_t MapNoise::getTileValue_(int x, int y) const {
    uint64_t prev_seed;
    if (x == 0) {
        if (y == 0)
            return getRand(seed_);
        else if (y > 0)
            prev_seed = getTileValue_(x, y - 1);
        else if (y < 0)
            prev_seed = getTileValue_(x, y + 1);

        // We dont want to make a symmetrical map
        if (y == -1)
            ++prev_seed;
    } else if (y != 0) {
        if (x > 0)
            prev_seed = getTileValue_(x - 1, y);
        else if (x < 0)
            prev_seed = getTileValue_(x + 1, y);

        if (x == -1)
            prev_seed += 2;
    }

    return getRand(prev_seed);
}
