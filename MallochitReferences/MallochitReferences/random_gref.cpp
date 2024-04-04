#include "random_gref.h"
#include <random>

std::random_device rd;
std::default_random_engine generator(rd());
const size_t MIN_VALUE = 1024, MAX_VALUE = 4294967296;
std::uniform_int_distribution<size_t> distribution(MIN_VALUE, MAX_VALUE);