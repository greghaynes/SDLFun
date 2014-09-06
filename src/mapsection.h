#ifndef SDLFUN_MAP_SECTION_H
#define SDLFUN_MAP_SECTION_H

#include "maplayer.h"
#include "point2d.h"

template <class T>
class MapSection : public MapLayer<T> {
    public:
        MapSection(const Point2d<int> &minRange, const Point2d<int> &maxRange);

        const Point2d<int> &getMinRange() const;
        const Point2d<int> &getMaxRange() const;
        const int &getXMin() const;
        const int &getYMin() const;
        const int &getXMax() const;
        const int &getYMax() const;
        bool isInSection(int x, int y) const;

    private:
        bool isWithinRange(int val, int min, int max) const;

        Point2d<int> minRange_;
        Point2d<int> maxRange_;
};

template <class T>
MapSection<T>::MapSection(const Point2d<int> &minRange,
                          const Point2d<int> &maxRange)
    : minRange_(minRange)
    , maxRange_(maxRange) {
}

template <class T>
const Point2d<int> &MapSection<T>::getMinRange() const {
    return minRange_;
}

template <class T>
const Point2d<int> &MapSection<T>::getMaxRange() const {
    return maxRange_;
}

template <class T>
const int &MapSection<T>::getXMin() const {
    return minRange_.x();
}

template <class T>
const int &MapSection<T>::getYMin() const {
    return minRange_.y();
}

template <class T>
const int &MapSection<T>::getXMax() const {
    return maxRange_.x();
}

template <class T>
const int &MapSection<T>::getYMax() const {
    return maxRange_.y();
}

template <class T>
bool MapSection<T>::isInSection(int x, int y) const {
    return isWithinRange(x, minRange_.x, maxRange_.x) &&
           isWithinRange(y, minRange_.y, maxRange_.y);
}

template <class T>
bool MapSection<T>::isWithinRange(int val, int min, int max) const {
    return (val >= min) &&  (val <= max);
}

#endif
