#ifndef SDLFUN_MAP_COHERENT_NOISE_SECTION_H
#define SDLFUN_MAP_COHERENT_NOISE_SECTION_H

#include <stdint.h>

#include "mapsection.h"
#include "point2d.h"

class MapCoherentNoiseSection : public MapSection<double> {
    public:
        static MapCoherentNoiseSection *getSection(int x, int y,
                uint64_t seed);

        MapCoherentNoiseSection(uint64_t seed,
                                const Point2d<int> &minRange,
                                const Point2d<int> &maxRange);

        double getTileValue(const Point2d<int> &point);
};

#endif
