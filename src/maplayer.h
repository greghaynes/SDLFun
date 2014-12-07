#ifndef SDLFUN_MAPLAYER_H
#define SDLFUN_MAPLAYER_H

#include "point2d.h"

template <class T>
class MapLayer {
    public:
        virtual T getTileValue(const Point2d<int> &point) = 0;
};

#endif
