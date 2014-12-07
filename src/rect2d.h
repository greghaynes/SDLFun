#ifndef SDLFUN_RECT_2D_H
#define SDLFUN_RECT_2D_H

#include "point2d.h"

template <class T>
class Rect2d {
    public:
        Rect2d(const Point2d<T> &corner,
               T width, T height);

        const Point2d<T> &corner() const;
        const Point2d<T> &upperCorner() const;
        T width() const;
        T height() const;
        bool isInside(const Point2d<T> &point) const;
        bool isInside(T x, T  y) const;

    private:
        bool isWithinRange(int val, int min, int max) const;

        Point2d<T> corner_;
        Point2d<T> size_;
};

template <class T>
Rect2d<T>::Rect2d(const Point2d<T> &corner,
                  T width, T height)
    : corner_(corner)
    , size_(width, height) {
}

template <class T>
const Point2d<T> &Rect2d<T>::corner() const {
    return corner_;
}

template <class T>
const Point2d<T> &Rect2d<T>::upperCorner() const {
    return Point2d<T>(corner.x + width, corner.y + height);
}

template <class T>
T Rect2d<T>::width() const {
    return size_.x;
}

template <class T>
T Rect2d<T>::height() const {
    return size_.y;
}

template <class T>
bool Rect2d<T>::isInside(const Point2d<T> &point) const {
    return isInside(point.x, point.y);
}

template <class T>
bool Rect2d<T>::isInside(T x, T y) const {
    return isWithinRange(x, corner_.x, corner_.x + width()) &&
           isWithinRange(y, corner_.y, corner_.y + height());
}

template <class T>
bool Rect2d<T>::isWithinRange(int val, int min, int max) const {
    return (val >= min) &&  (val <= max);
}

#endif
