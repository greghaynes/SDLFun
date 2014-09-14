#ifndef SDLFUN_MAPCOHERENTNOISELAYER_H
#define SDLFUN_MAPCOHERENTNOISELAYER_H

#include <stdint.h>

#include "maplayer.h"

class MapCoherentNoiseSection;
class MapUniformNoise;

class MapCoherentNoiseLayer : public MapLayer<double> {
    public:
        MapCoherentNoiseLayer(uint64_t seed);

        double getTileValue(int x, int y);

    private:
        MapUniformNoise *map_noise_;
};

#endif
