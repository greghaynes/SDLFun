find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)

set(SdlFun_SRCS
    mapcoherentnoiselayer.cpp
    mapcoherentnoisesection.cpp
    maprandompointsampler.cpp
    mapuniformnoise.cpp
    rand.cpp)

include_directories(${SDL_INCLUDE_DIR} ${SDLIMAGE_INCLUDE_DIR} ${SDLTTF_INCLUDE_DIR})
add_library(lsdlfun ${SdlFun_SRCS})

add_executable(sdlfun main.cpp)
target_link_libraries(sdlfun lsdlfun ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${SDLTTF_LIBRARY})
