#ifndef ROO_BACKPORT_TYPE_TRAITS_H_
#define ROO_BACKPORT_TYPE_TRAITS_H_

namespace roo {

// remove_reference
template <typename T>
struct remove_reference {
  typedef T type;
};

template <typename T>
struct remove_reference<T&> {
  typedef T type;
};

template <typename T>
struct remove_reference<T&&> {
  typedef T type;
};

}  // namespace roo

#endif