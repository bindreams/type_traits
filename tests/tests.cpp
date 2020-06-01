#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include <doctest/doctest.h>
#include <zh/type_traits.hpp>

ZH_DECL_DEFINES(is_transparent)

struct comparator {
	using is_transparent = void;
};

TEST_CASE("Unit.DefinesMacro") {
	CHECK( defines_is_transparent_v<comparator>);
	CHECK(!defines_is_transparent_v<int>);
}

TEST_CASE("Unit.DefinesType") {
	CHECK( zh::defines_type_v<std::enable_if<true>> );
	CHECK(!zh::defines_type_v<std::enable_if<false>>);
}

TEST_CASE("Unit.HasSize") {
	CHECK( zh::has_size_v<std::vector<int>>);
	CHECK( zh::has_size_v<int[5]>);
	CHECK(!zh::has_size_v<int>);
}

TEST_CASE("Unit.IsFunctionLike") {
	CHECK(std::is_same_v<int, zh::remove_all_pointers_t<int***>>);
}