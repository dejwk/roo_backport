#ifndef ROO_BACKPORT_BIT_H_
#define ROO_BACKPORT_BIT_H_

#if __cplusplus >= 202002L || (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L)
#if defined(__has_include)
#if __has_include(<bit>)
#include <bit>
#endif
#endif
#endif

#if defined(__cpp_lib_bitops) && __cpp_lib_bitops >= 201907L

namespace roo {

/// Counts trailing zero bits in an unsigned integer, returning its width for
/// zero.
using std::countr_zero;

}  // namespace roo

#else

#include <limits>
#include <type_traits>

#ifndef ROO_BACKPORT_HAS_BUILTIN_CTZ
#if defined(__has_builtin)
#define ROO_BACKPORT_HAS_BUILTIN_CTZ                                \
  (__has_builtin(__builtin_ctz) && __has_builtin(__builtin_ctzl) && \
   __has_builtin(__builtin_ctzll))
#elif defined(__GNUC__)
#define ROO_BACKPORT_HAS_BUILTIN_CTZ 1
#else
#define ROO_BACKPORT_HAS_BUILTIN_CTZ 0
#endif
#endif

namespace roo {
namespace backport_internal {

template <typename T>
struct IsUnsignedInteger {
  using Type = typename std::remove_cv<T>::type;
  static constexpr bool value =
#if defined(__cpp_char8_t)
      !std::is_same<Type, char8_t>::value &&
#endif
      std::is_unsigned<Type>::value && !std::is_same<Type, bool>::value &&
      !std::is_same<Type, char>::value && !std::is_same<Type, wchar_t>::value &&
      !std::is_same<Type, char16_t>::value &&
      !std::is_same<Type, char32_t>::value;
};

// Use recursion so the portable path stays constexpr in C++11.
template <typename T>
constexpr int CountTrailingZerosPortable(T value, int count) noexcept {
  return (value & T{1}) != 0 ? count
                             : CountTrailingZerosPortable(
                                   static_cast<T>(value >> 1), count + 1);
}

template <typename T>
constexpr int CountTrailingZerosNonzero(T value) noexcept {
  return CountTrailingZerosPortable(value, 0);
}

#if ROO_BACKPORT_HAS_BUILTIN_CTZ
constexpr int CountTrailingZerosNonzero(unsigned int value) noexcept {
  return __builtin_ctz(value);
}

constexpr int CountTrailingZerosNonzero(unsigned long value) noexcept {
  return __builtin_ctzl(value);
}

constexpr int CountTrailingZerosNonzero(unsigned long long value) noexcept {
  return __builtin_ctzll(value);
}
#endif

// Promote narrow integers to the intrinsic's argument size and keep the
// signed result of ordinary integer promotion out of the overload set.
template <typename T>
using PromotedUnsigned = typename std::make_unsigned<decltype(+T{})>::type;

}  // namespace backport_internal

/// Counts trailing zero bits in an unsigned integer, returning its width for
/// zero.
template <typename T>
constexpr
    typename std::enable_if<backport_internal::IsUnsignedInteger<T>::value,
                            int>::type
    countr_zero(T value) noexcept {
  return value == 0
             ? std::numeric_limits<T>::digits
             : backport_internal::CountTrailingZerosNonzero(
                   static_cast<backport_internal::PromotedUnsigned<T> >(value));
}

}  // namespace roo

#endif

#endif  // ROO_BACKPORT_BIT_H_
