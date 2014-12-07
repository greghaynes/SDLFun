#define BOOST_TEST_MODULE MapRandomPointSampler
#include <boost/test/unit_test.hpp>

#include "maprandompointsampler.h"
#include "rect2d.h"

void check_points_dont_repeat(const std::vector< Point2d<int> > &points,
                              const Point2d<int> &initial_point) {
    int prev_x = initial_point.x, prev_y = initial_point.y;
    for(std::vector< Point2d<int> >::const_iterator it = points.begin();
            it != points.end(); ++it) {
        BOOST_CHECK_NE( it->x, prev_x );
        BOOST_CHECK_NE( it->y, prev_y );
        prev_x = it->x;
        prev_y = it->y;
    }
}

void check_points_contained(const std::vector< Point2d<int> > &points,
                            const Rect2d<int> &rect) {
    for(std::vector< Point2d<int> >::const_iterator it = points.begin();
            it != points.end(); ++it)
        BOOST_CHECK( rect.isInside(*it) );
}

BOOST_AUTO_TEST_CASE(constructor_test) {
    MapRandomPointSampler sampler(0, Rect2d<int>(Point2d<int>(1, 1), 2, 2 ));

    BOOST_CHECK_EQUAL( sampler.bounds().corner().x, 1 );
    BOOST_CHECK_EQUAL( sampler.bounds().corner().y, 1 );
    BOOST_CHECK_EQUAL( sampler.bounds().width(), 2 );
    BOOST_CHECK_EQUAL( sampler.bounds().height(), 2 );
}

BOOST_AUTO_TEST_CASE(get_points_positive) {
    Rect2d<int> rect(Point2d<int>(1, 1), 100, 100);
    MapRandomPointSampler sampler(0, rect);

    std::vector< Point2d<int> > *points = sampler.getPoints(20);
    check_points_dont_repeat(*points, Point2d<int>(1, 1));
    check_points_contained(*points, rect);
    delete points;
}

BOOST_AUTO_TEST_CASE(get_points_negative) {
    Rect2d<int> rect(Point2d<int>(-102, -102), 100, 100);
    MapRandomPointSampler sampler(0, rect);

    std::vector< Point2d<int> > *points = sampler.getPoints(20);
    check_points_dont_repeat(*points, Point2d<int>(-102, -102));
    check_points_contained(*points, rect);
    delete points;
}
