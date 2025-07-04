#ifndef ROO_BACKPORT_BYTE_H_
#define ROO_BACKPORT_BYTE_H_

#if __cplusplus >= 201703L
#include <cstddef>

namespace roo {
using byte = std::byte;
}
#else
namespace roo {
using byte = unsigned char;
}
#endif

#endif  // ROO_BACKPORT_BYTE_H_
