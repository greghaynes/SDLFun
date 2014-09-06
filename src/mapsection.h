#ifndef SDLFUN_MAP_SECTION_H
#define SDLFUN_MAP_SECTION_H

#include "maplayer.h"
#include "point2d.h"

template <class T>
class MapSection : public MapLayer<T> {
    public:
        MapSection(const Point2d<T> &minRange, const Point2d<T> &maxRange);

        const Point2d<T> &getMinRange() const;
        const Point2d<T> &getMaxRange() const;
        const T &getXMin() const;
        const T &getYMin() const;
        const T &getXMax() const;
        const T &getYMax() const;

    private:
        Point2d<T> minRange_;
        Point2d<T> maxRange_;
};

template <class T>
MapSection<T>::MapSection(const Point2d<T> &minRange,
                          const Point2d<T> &maxRange)
    : minRange_(minRange)
    , maxRange_(maxRange) {
}

template <class T>
const Point2d<T> &MapSection<T>::getMinRange() const {
    return minRange_;
}

template <class T>
const Point2d<T> &MapSection<T>::getMaxRange() const {
    return maxRange_;
}

template <class T>
const T &MapSection<T>::getXMin() const {
    return minRange_.getX();
}

template <class T>
const T &MapSection<T>::getYMin() const {
    return minRange_.getY();
}

template <class T>
const T &MapSection<T>::getXMax() const {
    return maxRange_.getX();
}

template <class T>
const T &MapSection<T>::getYMax() const {
    return maxRange_.getY();
}

#endif
