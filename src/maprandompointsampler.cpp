#include "maprandompointsampler.h"
#include "rand.h"

MapRandomPointSampler::MapRandomPointSampler(uint64_t seed,
                                             const Rect2d<int> &bounds)
    : seed_(seed)
    , bounds_(bounds)
    , uniformNoise_(seed) {
}

const Rect2d<int> &MapRandomPointSampler::bounds() const {
    return bounds_;
}

std::vector< Point2d<int> > *MapRandomPointSampler::getPoints(int n) {
    std::vector< Point2d<int> > *res = new std::vector< Point2d<int> >(n);

    uint64_t rand = 0;
    int width, height;
    for(int i = 0; i < n; ++i) {
        if(!rand)
            rand = uniformNoise_.getTileValue(bounds_.corner());
        else
            rand = rand_from_seed(rand);

        width = rand % bounds_.width();
        rand = rand_from_seed(rand);
        height = rand % bounds_.height();

        (*res)[i].x = bounds_.corner().x + width;
        (*res)[i].y = bounds_.corner().y + height;
    }
    
    return res;
}
