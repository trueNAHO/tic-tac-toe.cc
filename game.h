#ifndef TIC_TAC_TOE_GAME_H_
#define TIC_TAC_TOE_GAME_H_

#include <functional>
#include <vector>

#include "board.h"
#include "exit_status.h"

namespace tic_tac_toe {

class Game {
 public:
  using board_type = Board;
  using player_type = Player;

  using board_cols_type = board_type::cols_type;
  using board_rows_type = board_type::rows_type;

  using board_field_type = board_type::field_type;

  using board_fields_type = board_type::fields_type;

  using players_type = std::vector<player_type>;

  using max_turns_type = int;
  using turns_type = int;

  using input_retries_type = int;

  // Typename permutations

  using const_board_cols_reference = board_type::const_cols_reference;
  using const_board_field_reference = board_type::const_field_reference;
  using const_board_fields_reference = board_type::const_fields_reference;
  using const_board_reference = const board_type&;
  using const_board_rows_reference = board_type::const_rows_reference;
  using const_input_retries_reference = const input_retries_type&;
  using const_max_turns_reference = const max_turns_type&;
  using const_player_reference = const player_type&;
  using const_players_reference = const players_type&;
  using const_turns_reference = const turns_type&;

  Game(players_type& players, const_board_rows_reference board_rows,
       const_board_cols_reference board_cols);

  void Start();

 private:
  board_type board_;
  players_type& players_;

  max_turns_type max_turns_;
  turns_type turns_{};

  players_type::iterator current_player_;
  ExitStatus exit_status_{};
  input_retries_type input_retries_{};

  void End();
  board_field_type* GetField();
  void Header();
  bool IsGameContinue();
  bool IsDraw();
  bool IsWon();
  void SetField();
  void Status();
  bool WinnerByCols();
  bool WinnerByDiagonalDown();
  bool WinnerByDiagonalUp();
  bool WinnerByDiagonals();
  bool WinnerByRows();
};

}  // namespace tic_tac_toe

#endif  // TIC_TAC_TOE_GAME_H_

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
