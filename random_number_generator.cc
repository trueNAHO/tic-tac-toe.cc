#include <random>

#include "random_number_generator.h"

namespace random_number_generator {

result_type range(result_type min, result_type max) {
  return std::uniform_int_distribution{min, max}(mt);
}

}

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
