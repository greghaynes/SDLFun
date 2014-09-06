cmake_minimum_required(VERSION 2.6)

PROJECT(test)
add_subdirectory(src)
add_subdirectory(tests/unit)

enable_testing()
add_test(NAME MapNoise COMMAND MapNoise)
add_test(NAME MapCoherentNoiseLayer COMMAND MapCoherentNoiseLayer)
