#pragma once
#include <type_traits>
#include "enable_if_defined.hpp"

namespace zh {

/// true_type if T defines nested type called `type`, false_type otherwise.
template <class T, class Enable = void>
struct defines_type : std::false_type {
};

template <class T>
struct defines_type<T,
	enable_if_defined_t<typename T::type>> : std::true_type {
};

/// true if T defines nested type called `type`, false otherwise.
template <class T>
constexpr bool defines_type_v = defines_type<T>::value;

} // namespace zh