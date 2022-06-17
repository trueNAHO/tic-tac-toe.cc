#ifndef TIC_TAC_TOE_FIELD_H_
#define TIC_TAC_TOE_FIELD_H_

#include "player.h"

namespace tic_tac_toe {

struct Field {
  using player_type = Player;
  using player_pointer = Player*;
  player_pointer player{};
};

}  // namespace tic_tac_toe

#endif  // TIC_TAC_TOE_FIELD_H_

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
