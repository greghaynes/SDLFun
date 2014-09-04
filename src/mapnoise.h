#ifndef SDLFUN_MAPNOISE_H
#define SDLFUN_MAPNOISE_H

#include <stdint.h>

#include "maplayer.h"

class MapNoise : public MapLayer<double> {
    public:
        explicit MapNoise(uint64_t seed);

        uint64_t getSeed() const;
        double getTileValue(int x, int y);
        double getTileValue(int x, int y) const;

    private:
        uint64_t getRand(uint64_t seed) const;
        double normalizeRand(uint64_t seed) const;
        uint64_t getTileValue_(int x, int y) const;

        uint64_t seed_;
};

#endif
