#define BOOST_TEST_MODULE MapCoherentNoiseLayer
#include <boost/test/unit_test.hpp>

#include "mapcoherentnoiselayer.h"


BOOST_AUTO_TEST_CASE(constructor_test)
{
    MapCoherentNoiseLayer x1(0);
    x1.getTileValue(Point2d<int>(0, 0));
}
