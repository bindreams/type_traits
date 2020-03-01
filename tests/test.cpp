#include <gtest/gtest.h>

#include "type_traits.hpp"

ZH_DECL_DEFINES(is_transparent)

struct comparator {
	using is_transparent = void;
};

TEST(type_traits_test, defines_macro) {
	EXPECT_TRUE (defines_is_transparent_v<comparator>);
	EXPECT_FALSE(defines_is_transparent_v<int>);
}

TEST(type_traits_test, defines_type) {
	EXPECT_TRUE (zh::defines_type_v<std::enable_if<true>> );
	EXPECT_FALSE(zh::defines_type_v<std::enable_if<false>>);
}

TEST(type_traits_test, has_size) {
	EXPECT_TRUE (zh::has_size_v<std::vector<int>>);
	EXPECT_TRUE (zh::has_size_v<int[5]>);
	EXPECT_FALSE(zh::has_size_v<int>);
}

int main() {
	testing::InitGoogleTest();
	int result = RUN_ALL_TESTS();

	system("PAUSE");
	return result;
}