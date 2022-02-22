#include <catch2/catch_test_macros.hpp>
#include "../include/PrimaryAlgorithm/Tree.h"
#include "../TestUtils.h"
class TreeTestsFixture
{
    public:
    TreeTestsFixture()
    {
     so = Solution();
    }
    Solution so;
    int expectResult{ 0 };
}; // class TreeTestsFixture

TEST_CASE_METHOD(TreeTestsFixture, "findNumberIn2DArray", "[findNumberIn2DArray]""[TreeTests]")
{
    // vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    // auto result = so.findNumberIn2DArray(matrix, 30);
    // REQUIRE(result == true);
    // REQUIRE(so.findNumberIn2DArray(matrix, 20) == false);
    // vector<vector<int>> matrix2 = {{1,4,7,11,15}};
    // REQUIRE(so.findNumberIn2DArray(matrix2, 20) == false);
    // REQUIRE(so.findNumberIn2DArray(matrix2, 1) == true);
    // vector<vector<int>> matrix3 = {{1}, {2,5}};
    // REQUIRE(so.findNumberIn2DArray(matrix3, 4) == true);

    vector<vector<int>> matrix4 = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    REQUIRE(so.findNumberIn2DArray(matrix4, 15) == true);
}
