#define BOOST_TEST_MODULE Point2d
#include <boost/test/unit_test.hpp>

#include "point2d.h"

BOOST_AUTO_TEST_CASE(constructor_test) {
    Point2d<int> p1, p2(0, 0), p3(1, 1);

    BOOST_CHECK_EQUAL( p2.x, 0 );
    BOOST_CHECK_EQUAL( p2.y, 0 );
    BOOST_CHECK_EQUAL( p3.x, 1 );
    BOOST_CHECK_EQUAL( p3.y, 1 );
}

BOOST_AUTO_TEST_CASE(assign_operator) {
    Point2d<int> p1, p2(0, 0), p3(1, 1);

    Point2d<int> *res = &(p1 = p2);
    BOOST_CHECK_EQUAL( res, &p1 );
    BOOST_CHECK_EQUAL( p1.x, p2.x );
    BOOST_CHECK_EQUAL( p1.y, p2.y );
    BOOST_CHECK_EQUAL( p2.x, 0 );
    BOOST_CHECK_EQUAL( p2.y, 0 );

    res = &(p2 = p3);
    BOOST_CHECK_EQUAL( res, &p2 );
    BOOST_CHECK_EQUAL( p2.x, p3.x );
    BOOST_CHECK_EQUAL( p2.y, p3.y );
    BOOST_CHECK_EQUAL( p2.x, 1 );
    BOOST_CHECK_EQUAL( p2.y, 1 );
}

BOOST_AUTO_TEST_CASE(equality_operator) {
    Point2d<int> p1(0, 0), p2(1, 1), p3(1, 0), p4(0, 0);

    BOOST_CHECK_EQUAL( p1 == p1, true );
    BOOST_CHECK_EQUAL( p1 == p4, true );
    BOOST_CHECK_EQUAL( p2 == p2, true );
    BOOST_CHECK_EQUAL( p1 == p2, false );
    BOOST_CHECK_EQUAL( p2 == p3, false );
    BOOST_CHECK_EQUAL( p1 == p3, false );
}
