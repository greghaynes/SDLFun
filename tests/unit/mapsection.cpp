#define BOOST_TEST_MODULE MapSection
#include <boost/test/unit_test.hpp>

#include "mapsection.h"

template <class T>
class MockMapSection : public MapSection<T> {
    public:
        MockMapSection(const Point2d<int> &minRange,
                       const Point2d<int> &maxRange);
        T getTileValue(int x, int y);

        T nextTileVal;
};

template <class T>
MockMapSection<T>::MockMapSection(const Point2d<int> &minRange,
                                  const Point2d<int> &maxRange)
    : MapSection<T>(minRange, maxRange) {
}

template <class T>
T MockMapSection<T>::getTileValue(int x, int y) {
    return nextTileVal;
}

BOOST_AUTO_TEST_CASE(constructor_test) {
    Point2d<int> min, max;
    MockMapSection<double> x1(min, max);
}
