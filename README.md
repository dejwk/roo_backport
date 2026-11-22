# roo_backport

Port of std::string_view and std::byte, introduced in C++17, so that they can be used in projects using older compilers, making it easier to transition to the new standard eventually.

Include `roo_backport/bit.h` for the C++20 operation `roo::countr_zero`.
It counts trailing zeros in an unsigned integer. For zero it returns the
number of value bits in the input type. It supports constant evaluation
in C++11 and uses the standard operation when available.
