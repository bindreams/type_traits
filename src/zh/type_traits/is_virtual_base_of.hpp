#include <type_traits>

namespace zh {

template<class Base, class Derived, class Enable = void>
struct is_virtual_base_of : std::is_base_of<Base, Derived> {};

template<class Base, class Derived>
struct is_virtual_base_of<
	Base, Derived, 
	std::void_t<
		decltype(static_cast<Derived*>(std::declval<Base*>())),
		std::enable_if_t<std::is_base_of_v<Base, Derived>>
	>> : std::false_type {};

template<class Base, class Derived>
constexpr bool is_virtual_base_of_v = is_virtual_base_of<Base, Derived>::value;

} // namespace zh