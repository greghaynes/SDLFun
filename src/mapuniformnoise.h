#ifndef SDLFUN_MAP_UNIFORM_NOISE_H
#define SDLFUN_MAP_UNIFORM_NOISE_H

#include <stdint.h>

#include "maplayer.h"

class MapUniformNoise : public MapLayer<double> {
    public:
        explicit MapUniformNoise(uint64_t seed);

        uint64_t getSeed() const;
        double getTileValue(int x, int y);

    private:
        uint64_t getRand(uint64_t seed) const;
        double normalizeRand(uint64_t seed) const;
        uint64_t getTileValue_(int x, int y) const;

        uint64_t seed_;
};

#endif
