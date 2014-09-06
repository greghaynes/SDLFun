#include "mapnoise.h"
#include "mapcoherentnoiselayer.h"
#include "mapsection.h"
#include "point2d.h"

class MapCoherentNoiseSection : public MapSection<int> {
    public:
        MapCoherentNoiseSection(uint64_t seed,
                                Point2d<int> &minRange,
                                Point2d<int> &maxRange);
};

MapCoherentNoiseSection::MapCoherentNoiseSection(uint64_t seed,
    Point2d<int> &minRange,
    Point2d<int> &maxRange)
    : MapSection(minRange, maxRange) {
}

MapCoherentNoiseLayer::MapCoherentNoiseLayer(uint64_t seed)
    : map_noise_(0) {
    map_noise_ = new MapNoise(seed);
}

double MapCoherentNoiseLayer::getTileValue(int x, int y) {
}
