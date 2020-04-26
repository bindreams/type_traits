#pragma once

namespace zh {

template<class T, class R = void>
struct enable_if_defined {
	/// enable_if_defined is a helper class for defines_type.
	using type = R;
};

template <class T, class R = void>
using enable_if_defined_t = typename enable_if_defined<T, R>::type;

} // namespace zh