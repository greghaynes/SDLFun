#ifndef SDLFUN_MAPLAYER_H
#define SDLFUN_MAPLAYER_H

template <class T>
class MapLayer {
    public:
        virtual T getTileValue(int x, int y) = 0;
};

#endif
