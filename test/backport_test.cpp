#include <cstdio>
#include <type_traits>
#include <utility>

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

}  // namespace

// Verifies substring comparison with a string literal in both language modes.
int main() {
  if (kView.substr(4) != "port") {
    std::fputs("Expected substring to equal port\n", stderr);
    return 1;
  }
  return 0;
}
