#ifndef SDLFUN_MAPCOHERENTNOISELAYER_H
#define SDLFUN_MAPCOHERENTNOISELAYER_H

#include <stdint.h>

#include "maplayer.h"

class MapUniformNoise;

class MapCoherentNoiseLayer : public MapLayer<double>
{
    public:
        MapCoherentNoiseLayer(uint64_t seed);

        double getTileValue(int x, int y);

        MapUniformNoise *map_noise_;
};

#endif
