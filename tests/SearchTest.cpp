#include <catch2/catch_test_macros.hpp>
#include "../include/Search.h"

TEST_CASE("Solution", "[SearchTest]")
{
	auto checkResult = [](vector<int>& nums, const int& expectResult) {
		Solution so;
		auto result = so.jump(nums);
		REQUIRE(result == expectResult);
	};

	vector<int> nums;
	int expectResult = 0;
	SECTION("case1")
	{
		nums = { 2, 3, 1, 1, 4 };
		expectResult = 2;
		checkResult(nums, expectResult);
	}

	SECTION("case11")
	{
		nums = { 2, 3, 0, 1, 1, 4 };
		expectResult = 3;
		checkResult(nums, expectResult);
	}

	SECTION("case2")
	{
		nums = { 8, 2, 4, 4, 4, 9, 5, 2, 5, 8, 8, 0, 8, 6, 9, 1, 1, 6, 3, 5, 1, 2, 6, 6, 0, 4, 8, 6, 0, 3, 2, 8, 7, 6, 5, 1, 7, 0, 3, 4, 8, 3, 5, 9, 0, 4, 0, 1, 0, 5, 9, 2, 0, 7, 0, 2, 1, 0, 8, 2, 5, 1, 2, 3, 9, 7, 4, 7, 0, 0, 1, 8, 5, 6, 7, 5, 1, 9, 9, 3, 5, 0, 7, 5 };
		expectResult = 13;
		checkResult(nums, expectResult);
	}

	SECTION("case3")
	{
		// nums = {5,8,1,8,9,8,7,1,7,5,8,6,5,4,7,3,9,9,0,6,6,3,4,8,0,5,8,9,5,3,7,2,1,8,2,3,8,9,4,7,6,2,5,2,8,2,7,9,3,7,6,9,2,0,8,2,7,8,4,4,1,1,6,4,1,0,7,2,0,3,9,8,7,7,0,6,9,9,7,3,6,3,4,8,6,4,3,3,2,7,8,5,8,6,0 };
		checkResult(nums, expectResult);
	}
}

