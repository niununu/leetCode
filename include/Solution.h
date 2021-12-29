#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution {
/*
面试题 01.01. 判定字符是否唯一
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
*/
public:
    bool isUnique(std::string astr) {
        bool unique = true;
        std::vector<bool> book (26 * 2, false);
        for (int i = 0; i < astr.length(); ++i)
        {
            auto index = astr[i] - 'A';
            if (book[index])
            {
                unique = false;
                break;
            }
            else
            {
                book[index] = true;
            }
        }

        return unique;
    }

/*
3.给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/
public:
    int lengthOfLongestSubstring(std::string s) {
        int Longest = 0;
        int current_index = 0;
        while(current_index != s.length())
        {
            int substrLenth = 0;
            std::set<char> substr;
            for (int i = current_index; i < s.length(); ++i)
            {
                substr.insert(s[i]);
                if (substrLenth == substr.size() || i == s.length() - 1)
                {
                    if (Longest < substr.size())
                    {
                        Longest = substr.size();
                    }
                    break;
                }
                else
                {
                    ++substrLenth;
                }
            }
            ++current_index;
        }

        return Longest;
    }

/*
4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。
*/
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    }

/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。
*/
public:
    std::string longestPalindrome(std::string s) {
    }

/*
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
};// class Solution
