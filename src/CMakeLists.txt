find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)

set(SdlFun_SRCS
    timer.cpp
    character.cpp
    hero.cpp
    position.cpp
    velocity.cpp
    map.cpp
    mapcoherentnoiselayer.cpp
    mapcoherentnoisesection.cpp
    mapuniformnoise.cpp
    engine.cpp
    tile.cpp)

include_directories(${SDL_INCLUDE_DIR} ${SDLIMAGE_INCLUDE_DIR} ${SDLTTF_INCLUDE_DIR})
add_library(lsdlfun ${SdlFun_SRCS})

add_executable(sdlfun main.cpp)
target_link_libraries(sdlfun lsdlfun ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${SDLTTF_LIBRARY})
