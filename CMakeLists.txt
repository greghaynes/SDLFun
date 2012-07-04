find_package(SDL REQUIRED)

set(SDLFun_SRCS
	main.cpp)

include_directories(${SDL_INCLUDE_DIR})

add_executable(sdlfun ${SDLFun_SRCS})

target_link_libraries(sdlfun ${SDL_LIBRARY})
