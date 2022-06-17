#include <cassert>
#include <iostream>
#include <string>

#include "board.h"

namespace tic_tac_toe {

Board::Board(const_rows_reference rows, const_rows_reference cols)
    : cols_(cols), rows_(rows), fields_(static_cast<std::size_t>(rows * cols),
    field_type{}) {
  assert(rows > 0 && cols > 0 && "Board must have a positive size");
}

std::ostream& operator<<(std::ostream& stdout, const Board& board) {
  const std::string sep_row(static_cast<std::size_t>(
      2 * board.cols_ + 1), board.sep_rows_);

  for (Board::rows_type rows{}; rows < board.rows_; ++rows) {
    stdout << sep_row << '\n';

    for (Board::cols_type cols{}; cols < board.cols_; ++cols) {
      Board::field_player_type* player{board(rows, cols).player};
      std::cout << board.sep_cols_ << (player ? player->sign() : Board::space_);
    }

    stdout << board.sep_cols_ << '\n';
  }

  stdout << sep_row << '\n';

  return stdout;
}

Board::const_field_reference Board::operator()(
    const_rows_reference rows, const_rows_reference cols) const {
  return fields_.at(static_cast<std::size_t>(rows * cols_ + cols));
}

Board::field_type& Board::operator()(const_rows_reference rows,
                                     const_rows_reference cols) {
  return fields_.at(static_cast<std::size_t>(rows * cols_ + cols));
}

Board::const_cols_reference Board::cols() const {
  return cols_;
}

Board::cols_type& Board::cols() {
  return cols_;
}

Board::const_rows_reference Board::rows() const {
  return rows_;
}

Board::rows_type& Board::rows() {
  return rows_;
}

}  // namespace tic_tac_toe

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
