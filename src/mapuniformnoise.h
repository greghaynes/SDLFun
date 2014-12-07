#ifndef SDLFUN_MAP_UNIFORM_NOISE_H
#define SDLFUN_MAP_UNIFORM_NOISE_H

#include <stdint.h>

#include "maplayer.h"
#include "point2d.h"

class MapUniformNoise : public MapLayer<double> {
    public:
        explicit MapUniformNoise(uint64_t seed);

        uint64_t getSeed() const;
        double getTileValue(const Point2d<int> &point);

    private:
        uint64_t getRand(uint64_t seed) const;
        uint64_t getRand(uint64_t seed1, uint64_t seed2) const;
        double normalizeRand(uint64_t seed) const;
        uint64_t getTileValue_(int x, int y) const;

        uint64_t seed_;
};

#endif
