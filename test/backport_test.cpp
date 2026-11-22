#include <cstdio>
#include <limits>
#include <type_traits>
#include <utility>

#include "roo_backport/bit.h"
#include "roo_backport/byte.h"
#include "roo_backport/move.h"
#include "roo_backport/string_view.h"

namespace {

static_assert(static_cast<unsigned char>(static_cast<roo::byte>(0xa5)) == 0xa5,
              "roo::byte preserves the byte value");

static_assert(std::is_same<decltype(roo::move(std::declval<const int&>())),
                           const int&&>::value,
              "roo::move returns an rvalue reference and preserves const");

constexpr char kText[] = "backport";
constexpr roo::string_view kView(kText, sizeof(kText) - 1);
static_assert(kView.data() == kText && kView.size() == 8 && kView[0] == 'b',
              "roo::string_view borrows and indexes the original text");

// Verifies the return type and the counts at the low and high ends of T.
template <typename T>
constexpr bool CountsTrailingZeros() {
  return std::is_same<decltype(roo::countr_zero(T{0})), int>::value &&
         noexcept(roo::countr_zero(T{0})) &&
         roo::countr_zero(T{0}) == std::numeric_limits<T>::digits &&
         roo::countr_zero(T{1}) == 0 && roo::countr_zero(T{12}) == 2 &&
         roo::countr_zero(
             static_cast<T>(T{1} << (std::numeric_limits<T>::digits - 1))) ==
             std::numeric_limits<T>::digits - 1;
}

static_assert(CountsTrailingZeros<unsigned char>(), "narrow unsigned integers");
static_assert(CountsTrailingZeros<unsigned short>(), "short unsigned integers");
static_assert(CountsTrailingZeros<unsigned>(), "unsigned integers");
static_assert(CountsTrailingZeros<unsigned long>(), "long unsigned integers");
static_assert(CountsTrailingZeros<unsigned long long>(),
              "long long unsigned integers");

template <typename T, typename = void>
struct CanCountTrailingZeros : std::false_type {};

template <typename T>
struct CanCountTrailingZeros<T, decltype(void(roo::countr_zero(
                                    std::declval<T>())))> : std::true_type {};

static_assert(!CanCountTrailingZeros<bool>::value, "bool is excluded");
static_assert(!CanCountTrailingZeros<int>::value,
              "signed integers are excluded");
static_assert(!CanCountTrailingZeros<char>::value, "plain char is excluded");
static_assert(!CanCountTrailingZeros<wchar_t>::value, "wchar_t is excluded");
static_assert(!CanCountTrailingZeros<char16_t>::value, "char16_t is excluded");
static_assert(!CanCountTrailingZeros<char32_t>::value, "char32_t is excluded");
#if defined(__cpp_char8_t)
static_assert(!CanCountTrailingZeros<char8_t>::value, "char8_t is excluded");
#endif

}  // namespace

// Verifies substring comparison with a string literal in both language modes.
int main() {
  if (kView.substr(4) != "port") {
    std::fputs("Expected substring to equal port\n", stderr);
    return 1;
  }
  return 0;
}
