#define BOOST_TEST_MODULE MapCoherentNoiseSection
#include <boost/test/unit_test.hpp>

#include "mapcoherentnoisesection.h"

#include "point2d.h"

BOOST_AUTO_TEST_CASE(constructor_test) {
    MapCoherentNoiseSection x1(0, Point2d<int>(0, 0), Point2d<int>(1, 1));
    BOOST_CHECK_EQUAL( x1.getMinRange() == Point2d<int>(0, 0), true);
    BOOST_CHECK_EQUAL( x1.getMaxRange() == Point2d<int>(1, 1), true);
}

BOOST_AUTO_TEST_CASE(get_section) {
    MapCoherentNoiseSection *x1 = MapCoherentNoiseSection::getSection(0, 0, 0);
    BOOST_CHECK_EQUAL( x1->getMinRange() == Point2d<int>(0, 0), true);
    BOOST_CHECK_EQUAL( x1->getMaxRange() == Point2d<int>(32, 32), true);

    x1 = MapCoherentNoiseSection::getSection(-1, -1, 0);
    BOOST_CHECK_EQUAL( x1->getMinRange() == Point2d<int>(-1, -1), true);
    BOOST_CHECK_EQUAL( x1->getMaxRange() == Point2d<int>(-33, -33), true);

    x1 = MapCoherentNoiseSection::getSection(-1, 0, 0);
    BOOST_CHECK_EQUAL( x1->getMinRange() == Point2d<int>(-1, 0), true);
    BOOST_CHECK_EQUAL( x1->getMaxRange() == Point2d<int>(-33, 32), true);

    x1 = MapCoherentNoiseSection::getSection(0, -1, 0);
    BOOST_CHECK_EQUAL( x1->getMinRange() == Point2d<int>(0, -1), true);
    BOOST_CHECK_EQUAL( x1->getMaxRange() == Point2d<int>(32, -33), true);
    delete x1;
}
