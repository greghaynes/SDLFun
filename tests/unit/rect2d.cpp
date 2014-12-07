#define BOOST_TEST_MODULE Rect2d
#include <boost/test/unit_test.hpp>

#include "point2d.h"
#include "rect2d.h"

BOOST_AUTO_TEST_CASE(constructor_test) {
    Rect2d<int> r1(Point2d<int>(0, 0), 0, 0);

    BOOST_CHECK_EQUAL( r1.corner().x, 0 );
    BOOST_CHECK_EQUAL( r1.corner().y, 0 );
    BOOST_CHECK_EQUAL( r1.width(), 0 );
    BOOST_CHECK_EQUAL( r1.height(), 0 );
}
