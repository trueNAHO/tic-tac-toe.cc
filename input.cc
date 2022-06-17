#include <iostream>
#include <limits>

#include "input.h"

namespace input {

void HandleCtrlD() {
  if (std::cin.eof()) throw std::runtime_error("CTRL-D was pressed");
}

template <typename T>
void OneSpaceSepField(T& field) {
  HandleCtrlD();
  if (!(std::cin >> field)) std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T, typename U>
void TwoSpaceSepFields(T& field_first, U& field_second) {
  HandleCtrlD();
  if (!(std::cin >> field_first >> field_second)) std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

}  // namespace input

// Includes template declarations
#include "input.inc"

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
