#ifndef YK_OUTER_HPP
#define YK_OUTER_HPP

#include <innerA.hpp>
#include <innerB.hpp>

namespace yk {

struct Outer {
  InnerA a;
  InnerB b;

  int func() const noexcept;
};

}  // namespace yk

#endif  // YK_OUTER_HPP
