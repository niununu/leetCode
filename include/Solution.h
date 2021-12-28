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
    void buyAndSell(int buyIndex, int& profit, vector<int>& prices, int& max)
    {
        if (buyIndex > prices.size() - 2)
        {
            if (max < profit)
            {
                max = profit;
            }
            //cout << "okkk: " << profit <<endl;
            profit = 0;
            return;
        }
        for (int i = buyIndex; i < prices.size(); ++i)
        {
            for (int j = i + 1; j < prices.size(); ++j)
            {
                if (prices[j] > prices[i])
                {
                    //cout << prices[i] << " " << prices[j] << endl;
                    profit += prices[j] - prices[i];
                    buyAndSell(j + 1, profit, prices, max);
                }
            }
        }
    }

    int maxProfit(vector<int>& prices) {
        int max = 0;
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            int profit = 0;
            buyAndSell(i, profit, prices, max);
        }

        return max;
    }
};