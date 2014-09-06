#include "mapcoherentnoiselayer.h"

#include <assert.h>
#include <cmath>

#include "mapuniformnoise.h"
#include "mapsection.h"
#include "point2d.h"

static const int kcoherentSectionStrideSize = 32;

class MapCoherentNoiseSection : public MapSection<double> {
    public:
        MapCoherentNoiseSection(uint64_t seed,
                                const Point2d<int> &minRange,
                                const Point2d<int> &maxRange);

        double getTileValue(int x, int y);
};

MapCoherentNoiseSection::MapCoherentNoiseSection(uint64_t seed,
    const Point2d<int> &minRange,
    const Point2d<int> &maxRange)
    : MapSection(minRange, maxRange) {
}

double MapCoherentNoiseSection::getTileValue(int x, int y) {
    assert(isInSection(x, y));

    return 0;
}

MapCoherentNoiseLayer::MapCoherentNoiseLayer(uint64_t seed)
    : map_noise_(0) {
    map_noise_ = new MapUniformNoise(seed);
}

MapCoherentNoiseSection *MapCoherentNoiseLayer::getCoherentNoiseSection(
        int x, int y) {
    Point2d<int> minRange, maxRange;

    minRange.x = std::abs(x / kcoherentSectionStrideSize);
    minRange.y = std::abs(y / kcoherentSectionStrideSize);

    if(x < 0)
        maxRange.x = minRange.x - kcoherentSectionStrideSize;
    else
        maxRange.x = minRange.x + kcoherentSectionStrideSize;

    if(y < 0)
        maxRange.y = minRange.y - kcoherentSectionStrideSize;
    else
        maxRange.y = minRange.y + kcoherentSectionStrideSize;

    return new MapCoherentNoiseSection(map_noise_->getSeed(),
                                       minRange, maxRange);
}

double MapCoherentNoiseLayer::getTileValue(int x, int y) {
    MapCoherentNoiseSection *noise_section = getCoherentNoiseSection(x, y);
    if(!noise_section)
        return 0;

    assert(noise_section != 0);
}
