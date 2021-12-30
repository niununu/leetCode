#include <catch2/catch_test_macros.hpp>
#include "../include/Solution_Vector.h"
#include <algorithm>

class SolutionTestsFixture
{
public:
    SolutionTestsFixture()
    {
        so = Solution();
    }
    Solution so;
    std::vector<int> input;
    std::vector<int> input2;
    std::vector<int> output;
    int expectResult{ 0 };
}; // class SolutionTestsFixture


template <class T>
void myPrintVec(std::vector<T> vec)
{
    for (const auto& item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << endl;
}

template <class T>
bool isSameVector(std::vector<T> vec1, std::vector<T> vec2)
{
    bool isSame = true;

    auto findDiff = [&isSame, vec1, vec2](){
        isSame = false;
        std::cout << "vec1 :";
        myPrintVec(vec1);

        std::cout << "vec2 :";
        myPrintVec(vec2);
    };

    if (vec1.size() != vec2.size())
    {
        findDiff();
    }
    else
    {
        for (int i = 0; i < vec1.size(); ++i)
        {
            if (vec1[i] != vec2[i])
            {
                findDiff();
                break;
            }
        }
    }

    return isSame;
}

TEST_CASE_METHOD(SolutionTestsFixture, "removeDuplicates", "[removeDuplicates]""[Solution_VectorTests]")
{
    SECTION("1")
    {
        input = { 1,1,2 };
        output = {1, 2};
    }

    SECTION("2")
    {
        input = {0,0,1,1,1,2,2,3,3,4};
        output = {0,1,2,3,4};
    }

    SECTION("3")
    {
        input = {};
        output = {};
    }

    SECTION("4")
    {
        input = {1,1,1};
        output = {1};
    }

    SECTION("5")
    {
        input = {1};
        output = {1};
    }
    REQUIRE(so.removeDuplicates(input) == output.size());
    REQUIRE(isSameVector(input, output));
}

TEST_CASE_METHOD(SolutionTestsFixture, "maxProfit", "[maxProfit]""[Solution_VectorTests]")
{
    SECTION("1")
    {
        input = {1,2,3,4};
        expectResult = 3;
    }

    SECTION("2")
    {
        input = {7,1,5,3,6,4};
        expectResult = 7;
    }

    SECTION("3")
    {
        input = {1,2,3,4,5};
        expectResult = 4;
    }
    SECTION("4")
    {
        input = {7,6,4,3,1};
        expectResult = 0;
    }
    SECTION("5")
    {
        input = {7};
        expectResult = 0;
    }
    SECTION("6")
    {
        input = {1, 1};
        expectResult = 0;
    }
    SECTION("7")
    {
        input = {1, 7};
        expectResult = 6;
    }
    SECTION("8")
    {
        input = {6,1,3,2,4,7};
        expectResult = 7;
    }
    REQUIRE(so.maxProfit(input) == expectResult);
}

TEST_CASE_METHOD(SolutionTestsFixture, "rotate", "[rotate]""[Solution_VectorTests]")
{
    int k = 0;
    SECTION("1")
    {
        input = {1,2,3,4,5,6,7};
        output = {5,6,7,1,2,3,4};
        k = 3;
    }
    SECTION("2")
    {
        input = {-1,-100,3,99};
        output = {3,99,-1,-100};
        k = 2;
    }
    SECTION("3")
    {
        input = {-1,-100,3,99};
        output = {-1,-100,3,99};
        k = 0;
    }
    SECTION("4")
    {
        input = {1,2,3,4,5,6,7};
        output = {1,2,3,4,5,6,7};
        k = 7;
    }
    SECTION("5")
    {
        input = {1,2,3,4,5,6,7};
        output = {7,1,2,3,4,5,6};
        k = 8;
    }
    SECTION("5")
    {
        input = {1,2,3,4};
        output = {1,2,3,4};
        k = 8;
    }
    SECTION("5")
    {
        input = {1,2,3,4};
        output = {4,1,2,3};
        k = 9;
    }
    so.rotate(input, k);
    REQUIRE(isSameVector(input, output));
}

TEST_CASE_METHOD(SolutionTestsFixture, "containsDuplicate", "[containsDuplicate]""[Solution_VectorTests]")
{
    REQUIRE(so.containsDuplicate(input) == false);
    input = {1};
    REQUIRE(so.containsDuplicate(input) == false);
    input = {1,2,3,1};
    REQUIRE(so.containsDuplicate(input) == true);
    input = {1,2,3,4};
    REQUIRE(so.containsDuplicate(input) == false);
    input = {1,1,1,3,3,4,3,2,4,2};
    REQUIRE(so.containsDuplicate(input) == true);
}

TEST_CASE_METHOD(SolutionTestsFixture, "singleNumber", "[singleNumber]""[Solution_VectorTests]")
{
    SECTION("1")
    {
        input = {2,2,1};
        expectResult = 1;
    }
    SECTION("2")
    {
        input = {4,1,2,1,2};
        expectResult = 4;
    }
    REQUIRE(so.singleNumber(input) == expectResult);
}

TEST_CASE_METHOD(SolutionTestsFixture, "intersect", "[intersect]""[Solution_VectorTests]")
{
    SECTION("1")
    {
        input = {1,2,2,1};
        input2 = {2,2};
        output = {2,2};
    }

    SECTION("2")
    {
        input = {4,9,5};
        input2 = {9,4,9,8,4};
        output = {4,9};
    }

    SECTION("3")
    {
        input = {4,9,5,4,4};
        input2 = {9,4,9,8,4};
        output = {4,9,4};
    }

    SECTION("3")
    {
        input = {4,9,5,4,4};
        input2 = {9,4,9,8,4,4,4};
        output = {4,9,4,4};
    }

    SECTION("3")
    {
        input = {4,9,5};
        input2 = {4,9,5};
        output = {4,9,5};
    }
    auto result = so.intersect(input, input2);
    std::sort(result.begin(), result.end());
    std::sort(output.begin(), output.end());

    REQUIRE(isSameVector(result, output));
}

TEST_CASE_METHOD(SolutionTestsFixture, "plusOne", "[plusOne]""[Solution_VectorTests]")
{
    SECTION("1")
    {
        input = {1,2,3};
        output = { 1,2,4 };
    }
    SECTION("2")
    {
        input = {4,3,2,1};
        output = {4,3,2,2};
    }
    SECTION("3")
    {
        input = {0};
        output = {1};
    }
    SECTION("4")
    {
        input = {9,9};
        output = {1,0,0};
    }
    SECTION("5")
    {
        input = {9,9,9,9};
        output = {1,0,0,0,0};
    }
    SECTION("6")
    {
        input = {8,9,9,9};
        output = {9,0,0,0};
    }
    REQUIRE(isSameVector(so.plusOne(input), output));
}

TEST_CASE_METHOD(SolutionTestsFixture, "moveZeroes", "[moveZeroes]""[Solution_VectorTests]")
{
    SECTION("1")
    {
        input = {0,1,0,3,12};
        output = {1,3,12,0,0};
    }
    SECTION("2")
    {
        input = {1,3,12,0,0};
        output = {1,3,12,0,0};
    }
    SECTION("3")
    {
        input = {1,0,3,0,12,0,0};
        output = {1,3,12,0,0,0,0};
    }
    SECTION("4")
    {
        input = {0,0,0,0,0,0,12};
        output = {12,0,0,0,0,0,0};
    }
    SECTION("5")
    {
        input = {45192,0,-659,-52359,-99225,-75991,0,-15155,27382,59818,0,-30645,-17025,81209,887,64648};
        output = {45192,-659,-52359,-99225,-75991,-15155,27382,59818,-30645,-17025,81209,887,64648,0,0,0};
    }
    so.moveZeroes(input);
    REQUIRE(isSameVector(input, output));
}

