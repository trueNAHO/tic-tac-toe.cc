#ifndef INPUT_H_
#define INPUT_H_

namespace input {

void HandleCtrlD();

template <typename T>
void OneSpaceSepField(T& field);

template <typename T, typename U>
void TwoSpaceSepFields(T& field_first, U& field_second);

}  // namespace input

#endif  // INPUT_H_

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
