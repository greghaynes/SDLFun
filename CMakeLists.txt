cmake_minimum_required(VERSION 2.6)

PROJECT(test)
add_subdirectory(src)
add_subdirectory(tests/unit)

enable_testing()
add_test(NAME MapCoherentNoiseLayer COMMAND MapCoherentNoiseLayer)
add_test(NAME MapRandomPointSampler COMMAND MapRandomPointSampler)
add_test(NAME MapUniformNoise COMMAND MapUniformNoise)
add_test(NAME Point2d COMMAND Point2d)
add_test(NAME Rect2d COMMAND Rect2d)
