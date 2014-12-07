#define BOOST_TEST_MODULE Rect2d
#include <boost/test/unit_test.hpp>

#include "point2d.h"
#include "rect2d.h"

BOOST_AUTO_TEST_CASE(constructor_test_int) {
    Rect2d<int> r1(Point2d<int>(0, 0), 0, 0);

    BOOST_CHECK_EQUAL( r1.corner().x, 0 );
    BOOST_CHECK_EQUAL( r1.corner().y, 0 );
    BOOST_CHECK_EQUAL( r1.width(), 0 );
    BOOST_CHECK_EQUAL( r1.height(), 0 );
}

BOOST_AUTO_TEST_CASE(is_in_section) {
    Point2d<int> corner(0, 0);
    int width = 2, height = 2;
    Rect2d<int> x1(corner, width, height);
    BOOST_CHECK_EQUAL( x1.isInside(1, 1), true );
    BOOST_CHECK_EQUAL( x1.isInside(0, 0), true );
    BOOST_CHECK_EQUAL( x1.isInside(2, 2), true );
    BOOST_CHECK_EQUAL( x1.isInside(-1, 0), false );
}
