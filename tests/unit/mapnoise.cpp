#define BOOST_TEST_MODULE MapNoise
#include <boost/test/unit_test.hpp>

#include "mapnoise.h"

BOOST_AUTO_TEST_CASE(constructor_test)
{
    MapNoise x1(0);
    BOOST_CHECK_EQUAL( x1.getSeed(), 0 );

    MapNoise x2(0xFFFFFFFFF);
    BOOST_CHECK_EQUAL( x2.getSeed(), 0xFFFFFFFFF );

    MapNoise *x3 = new MapNoise(0);
    BOOST_CHECK_EQUAL( x3->getSeed(), 0 );

    MapNoise *x4 = new MapNoise(0xABCDEF);
    BOOST_CHECK_EQUAL( x4->getSeed(), 0xABCDEF );
}
