#include <iostream>

#include "input.h"
#include "tic_tac_toe.h"

namespace tic_tac_toe {

void Start() {
  Player player1{"Player1", 'X'};
  Player player2{"Player2", 'O'};

  Game::board_rows_type board_rows{};
  Game::board_cols_type board_cols{};

  // TODO: check false input. letters or negative numbers. put this while loop
  // logic into a function in this tic_tac_toe namespace directly.
  std::cout << "Enter amount of rows and columns for board in space seperated format: ";
  input::TwoSpaceSepFields(board_rows, board_cols);

  Game game{Game::const_players_reference{player1, player2},
            board_rows, board_cols};

  game.Start();
};

}  // namespace tic_tac_toe

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
