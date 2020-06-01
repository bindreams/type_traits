#include <iostream>
#include <zh/type_traits.hpp>

ZH_DECL_DEFINES(is_transparent)

struct comparator {
	using is_transparent = void;
};

int main() {
	std::cout << defines_is_transparent_v<comparator> << "\n";
	std::cout << defines_is_transparent_v<int> << "\n";
}