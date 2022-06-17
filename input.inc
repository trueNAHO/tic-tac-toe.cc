#ifndef INPUT_INC_
#define INPUT_INC_

namespace input {

template void OneSpaceSepField<char>(char&);
template void OneSpaceSepField<int>(int&);

template void TwoSpaceSepFields<int>(int&, int&);
template void TwoSpaceSepFields<std::string, char>(std::string&, char&);

}  // namespace input

#endif  // INPUT_INC_

// vim: ft=cpp fdm=marker et sts=2 sw=2 ts=8 tw=80
