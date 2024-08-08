#include "outer.hpp"

#include <innerA.hpp>

#include "outer_impl.hpp"

namespace yk {

int Outer::func() const noexcept { return detail::outer_func(*this); }

}  // namespace yk
