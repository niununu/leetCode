#include <catch2/catch_test_macros.hpp>
#include "../include/Search.h"

TEST_CASE("Solution", "[SearchTest]")
{
    auto nums = [2,3,1,1,4];
    Solution so;
    auto result = so.jump(nums);
    REQUIRE(result == 2);
}