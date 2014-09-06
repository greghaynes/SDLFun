#define BOOST_TEST_MODULE MapUniformNoise
#include <boost/test/unit_test.hpp>

#include "mapuniformnoise.h"

BOOST_AUTO_TEST_CASE(constructor_test)
{
    MapUniformNoise x1(0);
    BOOST_CHECK_EQUAL( x1.getSeed(), 0 );

    MapUniformNoise x2(0xFFFFFFFFF);
    BOOST_CHECK_EQUAL( x2.getSeed(), 0xFFFFFFFFF );

    MapUniformNoise *x3 = new MapUniformNoise(0);
    BOOST_CHECK_EQUAL( x3->getSeed(), 0 );

    MapUniformNoise *x4 = new MapUniformNoise(0xABCDEF);
    BOOST_CHECK_EQUAL( x4->getSeed(), 0xABCDEF );
}

BOOST_AUTO_TEST_CASE(get_tile_value)
{
    int x = 1, y = 1;

    MapUniformNoise x1(0);
    double tile_val1 = x1.getTileValue(x, y);
    BOOST_CHECK_NE( tile_val1, 0.0L );

    MapUniformNoise *x2 = new MapUniformNoise(0);
    double tile_val2 = x2->getTileValue(x, y);
    BOOST_CHECK_NE( tile_val2, 0.0L );
    BOOST_CHECK_EQUAL( tile_val1, tile_val2);

    MapUniformNoise x3(0xFFFFFFFF);
    double tile_val3 = x3.getTileValue(x, y);
    BOOST_CHECK_NE( tile_val3, 0.0L );
    BOOST_CHECK_NE( tile_val3, tile_val2 );

    double tile_val4 = x3.getTileValue(-1, -1);
    BOOST_CHECK_NE( tile_val4, tile_val3 );
    BOOST_CHECK_NE( tile_val4, tile_val2 );

    double tile_val5 = x3.getTileValue(1, -1);
    BOOST_CHECK_NE( tile_val5, tile_val4 );
    BOOST_CHECK_NE( tile_val5, tile_val3 );
    BOOST_CHECK_NE( tile_val5, tile_val2 );

    double tile_val6 = x3.getTileValue(-1, 1);
    BOOST_CHECK_NE( tile_val6, tile_val5 );
    BOOST_CHECK_NE( tile_val6, tile_val4 );
    BOOST_CHECK_NE( tile_val6, tile_val3 );
    BOOST_CHECK_NE( tile_val6, tile_val2 );
}
