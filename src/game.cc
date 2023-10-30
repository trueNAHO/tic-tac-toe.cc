#include <cassert>
#include <iostream>
#include <random>
#include <tuple>

#include "game.h"
#include "exit_status.h"
#include "input.h"
#include "random_number_generator.h"

namespace tic_tac_toe {

Game::Game(players_type& players, const_board_rows_reference board_rows,
           const_board_cols_reference board_cols)
    : board_(board_rows, board_cols)
    , players_(players)
    , max_turns_(board_rows * board_cols)
    , current_player_(players.begin()) {
  assert(players.size() && "Game should contain players");
  std::shuffle(players_.begin(), players_.end(), random_number_generator::mt);
}

void Game::Start() {
  Status();
  for (; IsGameContinue() && ++turns_; input_retries_ = input_retries_type{}) {
    if (current_player_ + 1 == players_.end()) {
      current_player_ = players_.begin();
    } else {
      ++current_player_;
    }
    Header();
    SetField();
    Status();
  }
  End();
}

void Game::End() {
  assert((exit_status_.winner || exit_status_.draw) &&
         "Game must end by draw or by victory");

  if (exit_status_.winner) {
    std::cout << "\n>>> WINNER: " << exit_status_.winner->name() << '\n';
  } else if (exit_status_.draw) {
    std::cout << "\n>>> DRAW\n";
  } else {
  }
}

Game::board_field_type* Game::GetField() {
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
  }

  return &board_(rows - 1, cols - 1);
}

void Game::Header() {
  std::cout << "\n>>> " << current_player_->name() << "'"
      << (current_player_->name().back() == 's' ? char{} : 's') << " turn\n";
}

bool Game::IsGameContinue() {
  return !IsWon() && !IsDraw();
}

bool Game::IsDraw() {
  bool draw{turns_ >= max_turns_};
  if (draw) exit_status_.draw = draw;
  return draw;
}

bool Game::IsWon() {
  return WinnerByRows() || WinnerByCols() ||
      (board_.rows() == board_.cols() ? WinnerByDiagonals() : false);
}

void Game::SetField() {
  board_field_type* field{GetField()};
  while (field->player && ++input_retries_) {
    std::cout << "[#" << input_retries_ << "] Field already occupied by '"
        << field->player->name() << "'. Try again.\n";
    field = GetField();
  }
  field->player = &*current_player_;
}

void Game::Status() {
  std::cout << board_;
}

bool Game::WinnerByCols() {
  ExitStatus::player_type* winner{};
  for (auto [row, col] = std::tuple{board_rows_type{}, board_cols_type{}};
       row < board_.rows(); winner = nullptr, ++row, col = board_cols_type{}) {
    for (; col < board_.cols(); ++col) {
      winner = board_(col, row).player;
      if (winner != &*current_player_) break;
    }
    if (winner == &*current_player_) {
      exit_status_.winner = winner;
      return true;
    }
  }
  return false;
}

bool Game::WinnerByDiagonalDown() {
  assert(board_.rows() == board_.cols() &&
      "Both corners will only meet if the field is a square");

  for (int i{}; i < board_.rows(); ++i) {
    if (board_(i, i).player != &*current_player_) return false;
  }
  exit_status_.winner = board_(0, 0).player;
  return true;
}

bool Game::WinnerByDiagonalUp() {
  assert(board_.rows() == board_.cols() &&
      "Both corners will only meet if the field is a square");

  for (int i{}; i < board_.rows(); ++i) {
    if (board_(board_.rows() - i - 1, i).player != &*current_player_) {
      return false;
    }
  }
  exit_status_.winner = board_(0, board_.rows() - 1).player;
  return true;
}

bool Game::WinnerByDiagonals() {
  assert(board_.rows() == board_.cols() &&
      "Both corners will only meet if the field is a square");
  return WinnerByDiagonalDown() || WinnerByDiagonalUp();
}

bool Game::WinnerByRows() {
  ExitStatus::player_type* winner{};
  for (auto [row, col] = std::tuple{board_rows_type{}, board_cols_type{}};
       row < board_.rows(); winner = nullptr, ++row, col = board_cols_type{}) {
    for (; col < board_.cols(); ++col) {
      winner = board_(row, col).player;
      if (winner != &*current_player_) break;
    }
    if (winner == &*current_player_) {
      exit_status_.winner = winner;
      return true;
    }
  }
  return false;
}

}  // namespace tic_tac_toe

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
