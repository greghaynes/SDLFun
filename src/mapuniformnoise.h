#ifndef SDLFUN_MAP_UNIFORM_NOISE_H
#define SDLFUN_MAP_UNIFORM_NOISE_H

#include <stdint.h>

#include "maplayer.h"
#include "mapuniformbinarynoiselayer.h"
#include "point2d.h"

class MapUniformNoise : public MapLayer<double> {
    public:
        explicit MapUniformNoise(uint64_t seed);

        double getTileValue(const Point2d<int> &point);

    private:
        uint64_t getRand(uint64_t seed1, uint64_t seed2) const;
        double normalizeRand(uint64_t seed) const;

        MapUniformBinaryNoiseLayer binNoise_;
};

#endif
