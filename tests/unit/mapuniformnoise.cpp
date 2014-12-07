#define BOOST_TEST_MODULE MapUniformNoise
#include <boost/test/unit_test.hpp>

#include "mapuniformnoise.h"

BOOST_AUTO_TEST_CASE(constructor_test) {
    MapUniformNoise x1(0);

    MapUniformNoise x2(0xFFFFFFFFF);

    MapUniformNoise *x3 = new MapUniformNoise(0);
    delete x3;

    MapUniformNoise *x4 = new MapUniformNoise(0xABCDEF);
    delete x4;
}

BOOST_AUTO_TEST_CASE(get_tile_value) {
    int x = 1, y = 1;

    MapUniformNoise x1(0);
    double tile_val1 = x1.getTileValue(Point2d<int>(x, y));
    BOOST_CHECK_NE( tile_val1, 0.0L );

    MapUniformNoise *x2 = new MapUniformNoise(0);
    double tile_val2 = x2->getTileValue(Point2d<int>(x, y));
    BOOST_CHECK_NE( tile_val2, 0.0L );
    BOOST_CHECK_EQUAL( tile_val1, tile_val2);

    MapUniformNoise x3(0xFFFFFFFF);
    double tile_val3 = x3.getTileValue(Point2d<int>(x, y));
    BOOST_CHECK_NE( tile_val3, 0.0L );
    BOOST_CHECK_NE( tile_val3, tile_val2 );

    double tile_val4 = x3.getTileValue(Point2d<int>(-1, -1));
    BOOST_CHECK_NE( tile_val4, tile_val3 );
    BOOST_CHECK_NE( tile_val4, tile_val2 );

    double tile_val5 = x3.getTileValue(Point2d<int>(1, -1));
    BOOST_CHECK_NE( tile_val5, tile_val4 );
    BOOST_CHECK_NE( tile_val5, tile_val3 );
    BOOST_CHECK_NE( tile_val5, tile_val2 );

    double tile_val6 = x3.getTileValue(Point2d<int>(-1, 1));
    BOOST_CHECK_NE( tile_val6, tile_val5 );
    BOOST_CHECK_NE( tile_val6, tile_val4 );
    BOOST_CHECK_NE( tile_val6, tile_val3 );
    BOOST_CHECK_NE( tile_val6, tile_val2 );
}
