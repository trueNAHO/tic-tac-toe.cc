#ifndef TIC_TAC_TOE_BOARD_H_
#define TIC_TAC_TOE_BOARD_H_

#include <algorithm>
#include <ostream>
#include <vector>

#include "field.h"

namespace tic_tac_toe {

class Board {
 public:
  using field_type = Field;

  using player_pointer = field_type::player_pointer;

  using fields_type = std::vector<field_type>;

  using cols_type = int;
  using rows_type = int;

  using sep_cols_type = char;
  using sep_rows_type = char;

  using space_type = char;

  // Typename permutations

  using const_field_reference = const field_type&;
  using field_reference = field_type&;

  using const_fields_reference = const fields_type&;
  using fields_reference = fields_type&;

  using const_cols_reference = const cols_type&;
  using cols_reference = cols_type&;

  using const_rows_reference = const rows_type&;
  using rows_reference = rows_type&;

  using const_sep_cols_reference = const sep_cols_type&;
  using sep_cols_reference = sep_cols_type&;

  using const_sep_rows_reference = const sep_rows_type&;
  using sep_rows_reference = sep_rows_type&;

  using const_space_reference = const space_type&;
  using space_reference = space_type&;

  Board(const_rows_reference rows, const_rows_reference cols);

  friend std::ostream& operator<<(std::ostream& stdout, const Board& board);

  const_field_reference operator()(const_rows_reference rows,
                                   const_rows_reference cols) const;
  field_reference operator()(const_rows_reference rows,
                             const_rows_reference cols);

  const_cols_reference cols() const;
  cols_reference cols();

  const_rows_reference rows() const;
  rows_reference rows();

 private:
  inline static constexpr sep_cols_type sep_cols_{'|'};
  inline static constexpr sep_cols_type sep_rows_{'-'};
  inline static constexpr space_type space_{' '};

  cols_type cols_;
  rows_type rows_;

  fields_type fields_;
};

std::ostream& operator<<(std::ostream& stdout, const Board& board);

}  // namespace tic_tac_toe

#endif  // TIC_TAC_TOE_BOARD_H_

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
