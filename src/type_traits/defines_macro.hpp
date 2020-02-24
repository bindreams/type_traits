#pragma once
#include <type_traits>
#include "enable_if_defined.hpp"

/// `defines_##nested_type` is-a true_type if T defines nested_type, false_type
/// otherwise.
#define ZH_DECL_DEFINES(nested_type)                                           \
template <class T, class Enable = void>                                        \
struct defines_ ## nested_type : std::false_type {                             \
};                                                                             \
                                                                               \
template <class T>                                                             \
struct defines_ ## nested_type <T,                                             \
	zh::enable_if_defined_t<typename T::nested_type>> : std::true_type {       \
};                                                                             \
                                                                               \
template <class T>                                                             \
constexpr bool defines_ ## nested_type ## _v                                   \
	= defines_ ## nested_type<T>::value;