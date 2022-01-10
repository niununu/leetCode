#include <catch2/catch_test_macros.hpp>
#include "../include/Solution_Other.h"
#include "SolutionTestUtil.h"

class SolutionOtherTestsFixture
{
public:
    SolutionOtherTestsFixture()
    {
        so = Solution();
    }
    Solution so;
    int input1{0};
    int input2{0};
    int output{0};
    uint32_t input{0};

    // std::vector<int> input;
    // std::vector<int> input2;
    // std::vector<int> output;
    // int index = 0;
    // bool outputBool = false;

}; // class SolutionOtherTestsFixture

TEST_CASE_METHOD(SolutionOtherTestsFixture, "hammingWeight", "[hammingWeight]""[Solution_OtherTests]")
{
    SECTION("")
    {
        input = 0b00000000000000000000000000001011;
        output = 3;
    }
    SECTION("")
    {
        input = 0b00000000000000000000000010000000;
        output = 1;
    }
    SECTION("")
    {
        input = 0b11111111111111111111111111111101;
        output = 31;
    }
    SECTION("")
    {
        input = 0b11111111111111111111111111111111;
        output = 32;
    }
    SECTION("")
    {
        input = 0b00000000000000000000000000000000;
        output = 0;
    }
    REQUIRE(so.hammingWeight(input) == output);
}

TEST_CASE_METHOD(SolutionOtherTestsFixture, "hammingDistance", "[hammingDistance]""[Solution_OtherTests]")
{
    SECTION("")
    {
        input1 = 1;
        input2 = 4;
        output = 2;
    }
    SECTION("")
    {
        input1 = 3;
        input2 = 1;
        output = 1;
    }
    SECTION("")
    {
        input1 = 4;
        input2 = 2;
        output = 2;
    }
    REQUIRE(so.hammingDistance(input1, input2) == output);

}

TEST_CASE_METHOD(SolutionOtherTestsFixture, "reverseBits", "[reverseBits]""[Solution_OtherTests]")
{
    input = 0b00000010100101000001111010011100;
    output = 0b00111001011110000010100101000000;
    REQUIRE(so.reverseBits(input) == output);
}