#ifndef MAP_FACTORY_H
#define MAP_FACTORY_H

class Map;

class MapFactory {

    public:
        static Map *fromFile(const char *path);

};

#endif
