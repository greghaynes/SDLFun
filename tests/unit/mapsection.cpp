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
    Point2d<int> min(0, 0), max(1, 1);
    MockMapSection<double> x1(min, max);
    BOOST_CHECK_EQUAL( x1.getMinRange() == min, true );
    BOOST_CHECK_EQUAL( x1.getMaxRange() == max, true );
    BOOST_CHECK_EQUAL( x1.getXMin(), 0 );
    BOOST_CHECK_EQUAL( x1.getYMin(), 0 );
    BOOST_CHECK_EQUAL( x1.getXMax(), 1 );
    BOOST_CHECK_EQUAL( x1.getYMax(), 1 );
}

BOOST_AUTO_TEST_CASE(is_in_section) {
    Point2d<int> min(0, 0), max(2, 2);
    MockMapSection<double> x1(min, max);
    BOOST_CHECK_EQUAL( x1.isInSection(1, 1), true );
    BOOST_CHECK_EQUAL( x1.isInSection(0, 0), true );
    BOOST_CHECK_EQUAL( x1.isInSection(2, 2), true );
    BOOST_CHECK_EQUAL( x1.isInSection(-1, 0), false );
}
