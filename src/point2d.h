#ifndef SDLFUN_POINT_2D
#define SDLFUN_POINT_2D

template <class T>
class Point2d {
    public:
        Point2d(T x, T y);
        Point2d(const Point2d<T> &other_point);

        const T &getX() const;
        const T &getY() const;

    private:
        T x_;
        T y_;
};


template <class T>
Point2d<T>::Point2d(T x, T y)
    : x_(x)
    , y_(y) {
}

template <class T>
Point2d<T>::Point2d(const Point2d<T> &other_point)
    : x_(other_point.getX())
    , y_(other_point.getY()) {
}

template <class T>
const T &Point2d<T>::getX() const {
    return x_;
}

template <class T>
const T &Point2d<T>::getY() const {
    return y_;
}

#endif
