#pragma once
#include <type_traits>
#include <utility>
#include <iterator>
#include "enable_if_defined.hpp"

namespace zh {

/// true_type if you can call std::size on an instance of T.
template <class T, class Enable = void>
struct has_size : std::false_type {
};

template <class T>
struct has_size<T,
	enable_if_defined_t<decltype(std::size(std::declval<T>()))>> : std::true_type {
};

/// true if you can call std::size on an instance of T.
template <class T>
constexpr bool has_size_v = has_size<T>::value;

} // namespace zh