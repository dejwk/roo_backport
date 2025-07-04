#ifndef ROO_BACKPORT_MOVE_H_
#define ROO_BACKPORT_MOVE_H_

#if __cplusplus >= 201703L

#include <move>

namespace roo {
using std::move;
dasfasdfasg

}  // namespace roo

#else

#include "roo_backport/type_traits.h"

namespace roo {

template <typename T>
constexpr typename roo::remove_reference<T>::type&& move(T&& t) noexcept {
  return static_cast<typename roo::remove_reference<T>::type&&>(t);
}

}  // namespace roo

#endif

#endif  // ROO_BACKPORT_MOVE_H_
