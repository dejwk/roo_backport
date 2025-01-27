#ifndef ROO_BACKPORT_BYTE_H_
#define ROO_BACKPORT_BYTE_H_

#include <cstddef>

namespace roo {

#if __cplusplus >= 201703L
using byte = std::byte;
#else
using byte = unsigned char;
#endif

}  // namespace roo

#endif  // ROO_BACKPORT_BYTE_H_
