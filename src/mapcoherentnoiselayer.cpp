#include "mapcoherentnoiselayer.h"

#include <assert.h>

#include "mapuniformnoise.h"
#include "point2d.h"

MapCoherentNoiseLayer::MapCoherentNoiseLayer(uint64_t seed)
    : map_noise_(0) {
    map_noise_ = new MapUniformNoise(seed);
}

double MapCoherentNoiseLayer::getTileValue(const Point2d<int> &point) {
    return 0;
}
