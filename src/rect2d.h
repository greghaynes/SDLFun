#ifndef SDLFUN_RECT_2D_H
#define SDLFUN_RECT_2D_H

#include "point2d.h"

template <class T>
class Rect2d {
    public:
        Rect2d(const Point2d<T> &corner,
               T width, T height);

        const Point2d<T> &corner() const;
        T width() const;
        T height() const;

    private:
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
T Rect2d<T>::width() const {
    return size_.x;
}

template <class T>
T Rect2d<T>::height() const {
    return size_.y;
}

#endif
