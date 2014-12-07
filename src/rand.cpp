#include "rand.h"

double normalized_rand_from_seed(uint64_t seed) {
    return seed / 1.8446744e+19L;
}

uint64_t rand_from_seed(uint64_t seed) {
    return (uint64_t)((6364136223846793005 * seed) + 1442695040888963407);
}

