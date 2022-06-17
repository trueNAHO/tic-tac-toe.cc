#include <iostream>
#include <vector>

#include "game.h"
#include "input.h"
#include "player.h"
#include "tic_tac_toe.h"

namespace tic_tac_toe {

bool GetPlayAgain() {
  std::cout << "\nPlay again? [y/n] ";
  char yes_or_no{};
  input::OneSpaceSepField(yes_or_no);
  return yes_or_no == 'y' || yes_or_no == 'Y';
}

Player GetPlayer(int player_count) {
  Player::name_type name{};

  std::cout << "\nPlayer #" << player_count << " enter your name: ";
  std::getline(std::cin, name);

  for (int retries{}; name.empty() && ++retries; ) {
    std::cout << "[#" << retries
        << "] Player must have a name. Try again: ";
    std::getline(std::cin, name);
  }

  Player::sign_type sign{};

  std::cout << "Player #" << player_count << " enter your sign: ";
  input::OneSpaceSepField(sign);

  for (int retries{}; !sign && ++retries; ) {
    std::cout << "[#" << retries
        << "] Player must have a sign. Try again: ";
    input::OneSpaceSepField(sign);
  }

  return Player{name, sign};
}

int GetPlayerCounter() {
  std::cout << "Enter number of players: ";

  int player_counter{};
  input::OneSpaceSepField(player_counter);

  for (int retries{}; player_counter <= 0 && ++retries; ) {
    std::cout << "[#" << retries
        << "] Number of players must be positive. Try again: ";
    input::OneSpaceSepField(player_counter);
  }

  return player_counter;
}

void SetRowsCols(Game::board_rows_type& rows, Game::board_cols_type& cols) {
  std::cout
    << "\nEnter in space seperated formated the number of rows and columns for the board: ";

  input::TwoSpaceSepFields(rows, cols);

  for (int retries{}; (rows <= 0 || cols <= 0) && ++retries; ) {
    std::cout << "[#" << retries
        << "] Board size must be non-zero positive number. Try again: ";
    input::TwoSpaceSepFields(rows, cols);
  }
}

void Start() {
  int player_counter{GetPlayerCounter()};
  std::vector<Player> players{};
  for (int i{1}; i < player_counter + 1; ++i) players.push_back(GetPlayer(i));

  Game::board_cols_type board_cols{};
  Game::board_rows_type board_rows{};

  do {
    SetRowsCols(board_rows, board_cols);
    Game{players, board_rows, board_cols}.Start();
  } while (GetPlayAgain());
}

}  // namespace tic_tac_toe

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
