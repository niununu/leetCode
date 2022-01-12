/*
初级算法-数组
*/
#include <vector>
#include <set>
#include <iostream>
#include <map>
using namespace std;

class Solution {
/*
删除排序数组中的重复项
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
public:
    int removeDuplicates(vector<int>& nums) {
        auto resultSize = nums.size();
        for (int i = 0; i < resultSize; ++i)
        {
            auto base = nums[i];
            if (i + 1 < resultSize)
            {
                auto next = nums[i + 1];
                if (base == next)
                {
                    nums.erase(nums.begin() + i);
                    -- i;
                }
            }

            resultSize = nums.size();
        }

        return resultSize;
    }
/*
买卖股票的最佳时机 II
给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
*/
public:
    int max(int num1, int num2)
    {
        return num1 > num2 ? num1 : num2;
    }

    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length < 2)
        {
            return 0;
        }

        auto dp = new int[length][2];
        dp[0][1] = 0 - prices[0];
        dp[0][0] = 0;
        for (int i = 1; i < length; ++i)
        {
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
        }

        int max = dp[length - 1][0];
        return max;
    }

/*
旋转数组
给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
*/
 void rotate(vector<int>& nums, int k) {
    int tail = nums.size();
    if (k > tail)
    {
        k = k%tail;
    }
    tail = tail - k;
    std::vector<int> v1;
    v1.insert(v1.end(), nums.begin() + tail, nums.end());
    v1.insert(v1.end(), nums.begin(), nums.begin() + tail);
    nums = v1;
 }

/*
存在重复元素
给定一个整数数组，判断是否存在重复元素。
如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 
*/
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> setA;
        for(const auto& num : nums)
        {
            auto ret = setA.insert(num);
            if (!ret.second)
            {
                return true;
            }
        }

        return false;
    }
/*
只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
*/
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (const auto& num : nums)
        {
            result = num ^ result;
        }
        return result;
    }

/*
    两个数组的交集 II
    给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
*/
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> result;
        std::map<int, int> map;
        for (const auto& num1 : nums1)
        {
            auto iter = map.find(num1);
            if (iter != map.end())
            {
                ++ map[num1];
            }
            else
            {
                map[num1] = 1;
            }
        }

        for (const auto& num2 : nums2)
        {
            auto iter = map.find(num2);
            if (iter != map.end())
            {
                if (map[num2] > 0)
                {
                    result.emplace_back(num2);
                }
                -- map[num2];
            }
        }
        return result;
    }

/*
加一
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
*/
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        while(index >= 0)
        {
            digits[index] = digits[index] + 1;
            if (digits[index] == 10)
            {
                digits[index] = 0;
                -- index;
            }
            else
            {
                break;
            }
        }

        if (index < 0)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }

/*
移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
*/
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                int j = i + 1;
                for (int j = i + 1; j < nums.size(); ++j)
                {
                    if (nums[j] != 0)
                    {
                        nums[i] = nums[i] ^ nums[j];
                        nums[j] = nums[i] ^ nums[j];
                        nums[i] = nums[i] ^ nums[j];
                        break;
                    }
                }
            }
        }
    }
/*
有效的数独
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
空白格用 '.' 表示。

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                vector<bool> flagRow (10, false);
                vector<bool> flagColunm (10, false);
                auto numRow = board[i][j];
                auto numColunm = board[j][i];
                if (num == '.' || numColunm == '.')
                {
                    continue;
                }

                if (flagRow[num] || flagColunm[num])
                {
                    return false;
                }
                else
                {
                    flagRow[num] = true;
                    flagColunm[num] = true;
                }
            }
        }

        return true;
    }
*/
};// class Solution
