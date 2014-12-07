#include "mapuniformnoise.h"
#include "rand.h"

#include <assert.h>

MapUniformNoise::MapUniformNoise(uint64_t seed)
    : binNoise_(seed)
{
}

double MapUniformNoise::getTileValue(const Point2d<int> &point) {
    return normalized_rand_from_seed(binNoise_.getTileValue(point));
}
