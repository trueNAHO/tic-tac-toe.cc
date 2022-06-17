#include <iostream>
#include <limits>

#include "input.h"

namespace input {

template <typename T, typename U>
void TwoSpaceSepFields(T& a, U& b) {
  if (std::cin.eof()) throw std::runtime_error("CTRL-D was pressed");
  if (!(std::cin >> a >> b)) std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};

}  // namespace input

#include "input.inc"
