find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)

set(SDLFun_SRCS
	main.cpp)

include_directories(${SDL_INCLUDE_DIR} ${SDLIMAGE_INCLUDE_DIR})

add_executable(sdlfun ${SDLFun_SRCS})

target_link_libraries(sdlfun ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY})
