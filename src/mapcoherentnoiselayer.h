#ifndef SDLFUN_MAPCOHERENTNOISELAYER_H
#define SDLFUN_MAPCOHERENTNOISELAYER_H

#include <stdint.h>

#include "maplayer.h"
#include "point2d.h"

class MapCoherentNoiseSection;
class MapUniformNoise;

class MapCoherentNoiseLayer : public MapLayer<double> {
    public:
        MapCoherentNoiseLayer(uint64_t seed);

        double getTileValue(const Point2d<int> &point);

    private:
        MapUniformNoise *map_noise_;
};

#endif
