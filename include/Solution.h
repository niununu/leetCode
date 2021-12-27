#include <vector>
#include <set>
class Solution {
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

};