#ifndef SDLFUN_MAPCOHERENTNOISELAYER_H
#define SDLFUN_MAPCOHERENTNOISELAYER_H

#include <stdint.h>

#include "maplayer.h"

class MapNoise;

class MapCoherentNoiseLayer : public MapLayer<double>
{
    public:
        MapCoherentNoiseLayer(uint64_t seed,
                              unsigned int amplitude,
                              unsigned int wavelength);

        double getTileValue(int x, int y);

    private:
        MapNoise *map_noise_;
        unsigned int amplitude_;
        unsigned int wavelength_;
};

#endif
