#ifndef RANDOM_NUMBER_GENERATOR_H_
#define RANDOM_NUMBER_GENERATOR_H_

#include <random>

namespace random_number_generator {

using result_type = std::uniform_int_distribution<>::result_type;

inline static std::mt19937 mt(std::random_device {}());

result_type range(result_type min, result_type max);

}  // namespace random_number_generator

#endif  // RANDOM_NUMBER_GENERATOR_H_

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
