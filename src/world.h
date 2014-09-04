#ifndef SDLFUN_WORLD_H
#define SDLFUN_WORLD_H

class World {
    public:
        enum TileTypes {
            kEmpty = 0,
            kGreen = 1,
            kBlue = 2,
            kYellow = 3,
            kRed = 4
        };

        explicit World(uint64_t seed);
};

#endif
