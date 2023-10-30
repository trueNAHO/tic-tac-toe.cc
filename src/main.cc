#include <iostream>
#include <stdexcept>

#include "tic_tac_toe.h"

int main() {
  try {
    tic_tac_toe::Start();
  } catch(const std::exception& exception) {
    std::cerr << "\n[ERROR] " << exception.what() << '\n';
  } catch(...) {
    std::cerr << "\n[ERROR] Terminated abnormally\n";
  }
}

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
