#define BOOST_TEST_MODULE MapRandomPointSampler
#include <boost/test/unit_test.hpp>

#include "maprandompointsampler.h"

BOOST_AUTO_TEST_CASE(constructor_test) {
    MapRandomPointSampler sampler(0, Rect2d<int>(Point2d<int>(), 0, 0 ));
}
