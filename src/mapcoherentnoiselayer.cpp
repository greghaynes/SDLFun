#include "mapcoherentnoiselayer.h"

#include "mapnoise.h"

MapCoherentNoiseLayer::MapCoherentNoiseLayer(uint64_t seed,
                                             unsigned int amplitude,
                                             unsigned int wavelength)
    : map_noise_(0)
    , amplitude_(amplitude)
    , wavelength_(wavelength)
{
    map_noise_ = new MapNoise(seed);
}

double MapCoherentNoiseLayer::getTileValue(int x, int y)
{
    int a_x = (x + wavelength_) - (x % wavelength_);
    int a_y = (y + wavelength_) - (y % wavelength_);
    double a = map_noise_->getTileValue(a_x
}  
