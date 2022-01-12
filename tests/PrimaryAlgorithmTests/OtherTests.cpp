#include <catch2/catch_test_macros.hpp>
#include "../include/PrimaryAlgorithm/Other.h"
#include "../TestUtils.h"

class OtherTestsFixture
{
public:
    OtherTestsFixture()
    {
        so = Solution();
    }
    Solution so;
    int input1{0};
    int input2{0};
    int output{0};
    uint32_t input{0};

    std::vector<int> intVec;
    // std::vector<int> input2;
    // std::vector<int> output;
    // int index = 0;
    // bool outputBool = false;

}; // class OtherTestsFixture

TEST_CASE_METHOD(OtherTestsFixture, "hammingWeight", "[hammingWeight]""[OtherTests]")
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

TEST_CASE_METHOD(OtherTestsFixture, "hammingDistance", "[hammingDistance]""[OtherTests]")
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

TEST_CASE_METHOD(OtherTestsFixture, "reverseBits", "[reverseBits]""[OtherTests]")
{
    SECTION("")
    {
        input = 0b00000010100101000001111010011100;
        output = 0b00111001011110000010100101000000;
    }
    SECTION("")
    {
        input = 0b11111111111111111111111111111101;
        output = 0b10111111111111111111111111111111;
    }
    SECTION("")
    {
        input = 0b11111111111111111111111111111111;
        output = 0b11111111111111111111111111111111;
    }
    SECTION("")
    {
        input = 0b10000000000000000000000000000000;
        output = 1;
    }
    SECTION("")
    {
        input = 0;
        output = 0;
    }
    REQUIRE(so.reverseBits(input) == output);
}

TEST_CASE_METHOD(OtherTestsFixture, "generate", "[generate]""[OtherTests]")
{
    vector<vector<int>> output;

    SECTION("")
    {
        input1 = 5;
        output = {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
    }
    SECTION("")
    {
        input1 = 1;
        output = {{1}};
    }
    SECTION("")
    {
        input1 = 2;
        output = {{1},{1,1}};
    }
    auto result = so.generate(input1);
    REQUIRE(result.size() == output.size());
    for (int i = 0; i < input1; ++i)
    {
        REQUIRE(SolutionTestUtil::isSameVector(output[i], result[i]));
    }
}

TEST_CASE_METHOD(OtherTestsFixture, "isValid", "[isValid]""[OtherTests]")
{
    std::string inputStr;
    bool result = true;
    SECTION("")
    {
        inputStr = "()";
        result = true;
    }

    SECTION("")
    {
        inputStr = "()[]{}";
        result = true;
    }
    SECTION("")
    {
        inputStr = "(]";
        result = false;
    }
    SECTION("")
    {
        inputStr = "([)]";
        result = false;
    }
    SECTION("")
    {
        inputStr = "{[]}";
        result = true;
    }
    SECTION("")
    {
        inputStr = "{";
        result = false;
    }
    SECTION("")
    {
        inputStr = "}";
        result = false;
    }
    REQUIRE(so.isValid(inputStr) == result);
}

TEST_CASE_METHOD(OtherTestsFixture, "missingNumber", "[missingNumber]""[OtherTests]")
{
    int result = 0;
    SECTION("")
    {
        intVec = {3,0,1};
        result = 2;
    }

    SECTION("1")
    {
        intVec = {0,1};
        result = 2;
    }
    SECTION("2")
    {
        intVec = {9,6,4,2,3,5,7,0,1};
        result = 8;
    }
    SECTION("3")
    {
        intVec = {0};
        result = 1;
    }
    REQUIRE(so.missingNumber(intVec) == result);
}