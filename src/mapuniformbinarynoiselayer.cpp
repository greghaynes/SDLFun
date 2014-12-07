#include "mapuniformbinarynoiselayer.h"
#include "rand.h"

MapUniformBinaryNoiseLayer::MapUniformBinaryNoiseLayer(uint64_t seed)
    : seed_(seed)
{
}

uint64_t MapUniformBinaryNoiseLayer::getTileValue(const Point2d<int> &point) {
    int64_t x64 = point.x, y64 = point.y;
    uint64_t res = getRand(*(uint64_t*)&x64, *(uint64_t*)&y64);
    return rand_from_seed(res ^ seed_);
}

uint64_t MapUniformBinaryNoiseLayer::getRand(uint64_t seed1, uint64_t seed2) const {
    uint64_t res = rand_from_seed(seed1);
    return res ^ rand_from_seed(seed2 ^ res);
}
