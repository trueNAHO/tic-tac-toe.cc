#ifndef TIC_TAC_TOE_H_
#define TIC_TAC_TOE_H_

#include "board.h"

namespace tic_tac_toe {

bool GetPlayAgain();
Player GetPlayer(int player_count);
int GetPlayerCounter();
void SetRowsCols(Board::rows_type& rows, Board::cols_type& cols);
void Start();

}  // namespace tic_tac_toe

#endif  // TIC_TAC_TOE_H_

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
