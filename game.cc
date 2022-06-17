#include <iostream>
#include <random>
#include <tuple>

#include "game.h"
#include "input.h"
#include "random_number_generator.h"

namespace tic_tac_toe {

Game::Game(const_players_reference players,
           const_board_rows_reference board_rows,
           const_board_cols_reference board_cols)
    : board_(board_rows, board_cols)
    , players_(players)
    , max_turns_(board_rows * board_cols) {
  std::shuffle(players_.begin(), players_.end(), random_number_generator::mt);
}

void Game::Start() {
  std::cout << board_;
  for (auto current_player{players_.begin()}; IsGameContinue();
       current_player = (current_player == players_.end() - 1) ?
       players_.begin() : current_player + 1, ++turns_,
       input_retries_ = input_retries_type{}) {
    SetField(*current_player);
    std::cout << board_;
  };
};

Game::board_field_pointer Game::GetField() {
  board_cols_type cols{};
  board_rows_type rows{};

  std::cout << "Enter rows (1 to " << board_.rows() << ") and colums (1 to "
      << board_.cols() << ") position in space seperated format: ";
  input::TwoSpaceSepFields(rows, cols);

  while ((rows < 1 || rows > board_.rows() || cols < 1 ||
         cols > board_.cols()) && ++input_retries_) {
    std::cout << "[#" << input_retries_
        << "] Invalid rows or columns index. Try again: ";
    input::TwoSpaceSepFields(rows, cols);
  };

  return &board_(rows - 1, cols - 1);
};

bool Game::IsGameContinue() {
  return turns_ < max_turns_;
};

void Game::SetField(player_reference player) {
  board_field_pointer field{GetField()};
  while (field->player && ++input_retries_) {
    std::cout << "[#" << input_retries_ << "] Field already occupied by '"
        << field->player->name() << "'. Try again.\n";
    field = GetField();
  };
  field->player = &player;
};

}  // namespace tic_tac_toe

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
