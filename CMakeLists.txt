find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)

set(SDLFun_SRCS
	src/main.cpp
	src/timer.cpp
	src/character.cpp
	src/hero.cpp
	src/position.cpp
	src/velocity.cpp
	src/map.cpp
    src/mapfactory.cpp
	src/engine.cpp
	src/tile.cpp)

include_directories(${SDL_INCLUDE_DIR} ${SDLIMAGE_INCLUDE_DIR} ${SDLTTF_INCLUDE_DIR})

add_executable(sdlfun ${SDLFun_SRCS})

target_link_libraries(sdlfun ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${SDLTTF_LIBRARY})
