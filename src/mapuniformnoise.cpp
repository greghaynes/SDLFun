#include "mapuniformnoise.h"
#include "rand.h"

#include <assert.h>

MapUniformNoise::MapUniformNoise(uint64_t seed)
    : seed_(seed)
{
}

uint64_t MapUniformNoise::getSeed() const {
    return seed_;
}

double MapUniformNoise::getTileValue(const Point2d<int> &point) {
    return normalized_rand_from_seed(getTileValue_(point.x, point.y));
}

uint64_t MapUniformNoise::getRand(uint64_t seed1, uint64_t seed2) const {
    uint64_t res = rand_from_seed(seed1);
    return res ^ rand_from_seed(seed2 ^ res);
}

uint64_t MapUniformNoise::getTileValue_(int x, int y) const {
    int64_t x64 = x, y64 = y;
    uint64_t res = getRand(*(uint64_t*)&x64, *(uint64_t*)&y64);
    return rand_from_seed(res ^ getSeed());
}
