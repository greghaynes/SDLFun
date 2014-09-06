#include "mapcoherentnoiselayer.h"
#include "mapuniformnoise.h"
#include "mapsection.h"
#include "point2d.h"

class MapCoherentNoiseSection : public MapSection<int> {
    public:
        MapCoherentNoiseSection(uint64_t seed,
                                const Point2d<int> &minRange,
                                const Point2d<int> &maxRange);
};

MapCoherentNoiseSection::MapCoherentNoiseSection(uint64_t seed,
    const Point2d<int> &minRange,
    const Point2d<int> &maxRange)
    : MapSection(minRange, maxRange) {
}

MapCoherentNoiseLayer::MapCoherentNoiseLayer(uint64_t seed)
    : map_noise_(0) {
    map_noise_ = new MapUniformNoise(seed);
}

double MapCoherentNoiseLayer::getTileValue(int x, int y) {
}
