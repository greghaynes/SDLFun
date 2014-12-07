#ifndef SDLFUN_MAP_UNIFORM_BINARY_NOISE_LAYER_H
#define SDLFUN_MAP_UNIFORM_BINARY_NOISE_LAYER_H

#include "maplayer.h"
#include "point2d.h"

#include <stdint.h>

class MapUniformBinaryNoiseLayer : public MapLayer<uint64_t> {
    public:
        MapUniformBinaryNoiseLayer(uint64_t seed);

        uint64_t getTileValue(const Point2d<int> &point);
    
    private:
        uint64_t getRand(uint64_t seed1, uint64_t seed2) const;

        uint64_t seed_;
};

#endif
