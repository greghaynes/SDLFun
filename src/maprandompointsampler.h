#ifndef SDL_FUN_MAP_RANDOM_POINT_SAMPLER_H
#define SDL_FUN_MAP_RANDOM_POINT_SAMPLER_H

#include "rect2d.h"

#include <stdint.h>

#include <vector>

#include "mapuniformbinarynoiselayer.h"

class MapRandomPointSampler {
    public:
        explicit MapRandomPointSampler(uint64_t seed,
                                       const Rect2d<int> &bounds);

        const Rect2d<int> &bounds() const;
        std::vector< Point2d<int> > *getPoints(int n);

    private:
        uint64_t seed_;
        Rect2d<int> bounds_;
        MapUniformBinaryNoiseLayer uniformNoise_;
};

#endif
