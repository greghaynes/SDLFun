#include "mapcoherentnoiselayer.h"

#include <assert.h>

#include "mapcoherentnoisesection.h"
#include "mapuniformnoise.h"
#include "mapsection.h"
#include "point2d.h"

MapCoherentNoiseLayer::MapCoherentNoiseLayer(uint64_t seed)
    : map_noise_(0) {
    map_noise_ = new MapUniformNoise(seed);
}

double MapCoherentNoiseLayer::getTileValue(int x, int y) {
    MapCoherentNoiseSection *noise_section =
        MapCoherentNoiseSection::getSection(x, y, map_noise_->getSeed());

    if(!noise_section)
        return 0;

    assert(noise_section != 0);
    return 0;
}
