#ifndef SDLFUN_MAPNOISE_H
#define SDLFUN_MAPNOISE_H

#include <stdint.h>

#include "maplayer.h"

class MapNoise : public MapLayer<double> {
    public:
        explicit MapNoise(uint64_t seed);

        double getTileValue(int x, int y);

    private:
        uint64_t getRand(uint64_t seed);
        double getNormalRand(uint64_t seed);

        uint64_t seed_;
};

#endif
