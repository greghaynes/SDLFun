#define BOOST_TEST_MODULE MapRandomPointSampler
#include <boost/test/unit_test.hpp>

#include <iostream>

#include "maprandompointsampler.h"

void check_points_dont_repeat(const std::vector< Point2d<int> > &points,
                              const Point2d<int> &initial_point) {
    int prev_x = initial_point.x, prev_y = initial_point.y;
    for(std::vector< Point2d<int> >::const_iterator it = points.begin();
            it != points.end(); ++it) {
        BOOST_CHECK_NE( it->x, prev_x );
        BOOST_CHECK_NE( it->y, prev_y );
    }
}

BOOST_AUTO_TEST_CASE(constructor_test) {
    MapRandomPointSampler sampler(0, Rect2d<int>(Point2d<int>(1, 1), 2, 2 ));

    BOOST_CHECK_EQUAL( sampler.bounds().corner().x, 1 );
    BOOST_CHECK_EQUAL( sampler.bounds().corner().y, 1 );
    BOOST_CHECK_EQUAL( sampler.bounds().width(), 2 );
    BOOST_CHECK_EQUAL( sampler.bounds().height(), 2 );
}

BOOST_AUTO_TEST_CASE(get_points_positive) {
    MapRandomPointSampler sampler(
            0,
            Rect2d<int>(Point2d<int>(1, 1), 100, 100));

    std::vector< Point2d<int> > *points = sampler.getPoints(20);
    check_points_dont_repeat(*points, Point2d<int>(1, 1));
    delete points;
}

BOOST_AUTO_TEST_CASE(get_points_negative) {
    MapRandomPointSampler sampler(
            0,
            Rect2d<int>(Point2d<int>(-101, -101), 100, 100));

    std::vector< Point2d<int> > *points = sampler.getPoints(20);
    check_points_dont_repeat(*points, Point2d<int>(1, 1));
    delete points;
}
