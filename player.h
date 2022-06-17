#ifndef TIC_TAC_TOE_PLAYER_H_
#define TIC_TAC_TOE_PLAYER_H_

#include <string>

namespace tic_tac_toe {

class Player {
 public:
  using name_type = std::string;
  using sign_type = char;

  // Typename permutations

  using const_name_reference = const name_type&;
  using const_sign_reference = const sign_type&;

  Player(const_name_reference name, const_sign_reference sign);

  const_name_reference name() const;
  name_type& name();

  const_sign_reference sign() const;
  sign_type& sign();

 private:
  name_type name_;
  sign_type sign_;
};

}  // namespace tic_tac_toe

#endif  // TIC_TAC_TOE_PLAYER_H_

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
