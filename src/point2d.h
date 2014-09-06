#ifndef SDLFUN_POINT_2D
#define SDLFUN_POINT_2D

template <class T>
class Point2d {
    public:
        Point2d();
        Point2d(T x, T y);

        Point2d<T> &operator= (const Point2d<T> &other);

        T x;
        T y;
};

template <class T>
Point2d<T>::Point2d() {
}

template <class T>
Point2d<T>::Point2d(T x, T y)
    : x(x)
    , y(y) {
}

template <class T>
Point2d<T> &Point2d<T>::operator= (const Point2d<T> &other) {
    x = other.x;
    y = other.y;
    return this;
}

#endif
