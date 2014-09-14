#include "mapcoherentnoisesection.h"

#include <assert.h>
#include <cmath>

static const int kcoherentSectionStrideSize = 32;

MapCoherentNoiseSection *MapCoherentNoiseSection::getSection(int x, int y,
        uint64_t seed) {
    Point2d<int> minRange, maxRange;

    minRange.x = x / kcoherentSectionStrideSize;
    minRange.y = y / kcoherentSectionStrideSize;

    if(x < 0) {
        minRange.x -= 1;
        maxRange.x = minRange.x - kcoherentSectionStrideSize;
    } else
        maxRange.x = minRange.x + kcoherentSectionStrideSize;

    if(y < 0) {
        minRange.y -= 1;
        maxRange.y = minRange.y - kcoherentSectionStrideSize;
    } else
        maxRange.y = minRange.y + kcoherentSectionStrideSize;

    return new MapCoherentNoiseSection(seed, minRange, maxRange);
}


MapCoherentNoiseSection::MapCoherentNoiseSection(uint64_t seed,
    const Point2d<int> &minRange,
    const Point2d<int> &maxRange)
    : MapSection(minRange, maxRange) {
}

double MapCoherentNoiseSection::getTileValue(int x, int y) {
    assert(isInSection(x, y));

    return 0;
}

