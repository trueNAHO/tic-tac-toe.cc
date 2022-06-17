#include <string>

#include "player.h"

namespace tic_tac_toe {

Player::Player(const_name_reference name, const_sign_reference sign)
    : name_(name), sign_(sign) {
};

Player::const_name_reference Player::name() const {
  return name_;
};

Player::name_reference Player::name() {
  return name_;
};

Player::const_sign_reference Player::sign() const {
  return sign_;
};

Player::sign_reference Player::sign() {
  return sign_;
};

}

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
