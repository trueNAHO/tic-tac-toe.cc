#ifndef TIC_TAC_TOE_EXIT_STATUS_H_
#define TIC_TAC_TOE_EXIT_STATUS_H_

#include "player.h"

namespace tic_tac_toe {

struct ExitStatus {
  using player_type = Player;

  bool draw{};
  player_type* winner{};
};

}  // namespace tic_tac_toe

#endif  // TIC_TAC_TOE_EXIT_STATUS_H_

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
