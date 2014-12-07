find_package (Boost COMPONENTS unit_test_framework REQUIRED)

include_directories (${CMAKE_SOURCE_DIR}/src ${Boost_INCLUDE_DIRS})
add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (MapCoherentNoiseLayer mapcoherentnoiselayer.cpp)
target_link_libraries (MapCoherentNoiseLayer lsdlfun ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable (MapCoherentNoiseSection mapcoherentnoisesection.cpp)
target_link_libraries (MapCoherentNoiseSection lsdlfun ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable (MapSection mapsection.cpp)
target_link_libraries (MapSection lsdlfun ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable (MapUniformNoise mapuniformnoise.cpp)
target_link_libraries (MapUniformNoise lsdlfun ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable (Point2d point2d.cpp)
target_link_libraries (Point2d lsdlfun ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_executable (Rect2d rect2d.cpp)
target_link_libraries (Rect2d lsdlfun ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
