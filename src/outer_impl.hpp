#ifndef YK_OUTER_IMPL_HPP
#define YK_OUTER_IMPL_HPP

#include "outer.hpp"

namespace yk::detail {

int outer_func(const Outer& _) noexcept { return 42; }

}  // namespace yk::detail

#endif  // YK_OUTER_IMPL_HPP
