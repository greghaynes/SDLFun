#include "mapuniformnoise.h"

#include <assert.h>

MapUniformNoise::MapUniformNoise(uint64_t seed)
    : seed_(seed)
{
}

uint64_t MapUniformNoise::getSeed() const {
    return seed_;
}

double MapUniformNoise::getTileValue(int x, int y) {
    return normalizeRand(getTileValue_(x, y));
}

uint64_t MapUniformNoise::getRand(uint64_t seed) const {
    return (uint64_t)((6364136223846793005 * seed) + 1442695040888963407);
}

uint64_t MapUniformNoise::getRand(uint64_t seed1, uint64_t seed2) const {
    uint64_t res = getRand(seed1);
    return res ^ getRand(seed2 ^ res);
}

double MapUniformNoise::normalizeRand(uint64_t rand) const {
    return rand / 1.8446744e+19L;
}

uint64_t MapUniformNoise::getTileValue_(int x, int y) const {
    int64_t x64 = x, y64 = y;
    uint64_t res = getRand(*(uint64_t*)&x64, *(uint64_t*)&y64);
    return getRand(res ^ getSeed());
}
