/*
初级算法-字符串
*/
#include <vector>
using namespace std;

class Solution {
/*
反转字符串
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
*/
public:
    void reverseString(vector<char>& s) {
        int index = s.size() / 2;
        int i = 0;
        int j = s.size() - 1;
        while(i < index)
        {
            s[i] = s[i] ^ s[j];
            s[j] = s[i] ^ s[j];
            s[i] = s[i] ^ s[j];
            ++i;
            --j;
        }
    }
/*
整数反转
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
假设环境不允许存储 64 位整数（有符号或无符号）。
*/
public:
    int reverse(int x) {
        long result = 0;
        while(x != 0)
        {
            result = result * 10 + x % 10;
            x = x / 10;
        }

        return (int)result == result ? result : 0;
    }
/*
字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
*/
    int firstUniqChar(string s) {
        int result = -1;
        std::vector<int> flags (26, 0);
        for (int i = 0; i < (int)s.size(); ++i)
        {
            ++ flags[s[i] - 'a'];
        }

        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (flags[s[i] - 'a'] == 1)
            {
                result = i;
                break;
            }
        }

        return result;
    }

/*
有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
*/
public:
    bool isAnagram(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        if (size1 != size2)
        {
            return false;
        }

        bool result = true;
        std::vector<int> flags1 (26, 0);
        std::vector<int> flags2 (26, 0);
        for (int i = 0; i < size1; ++i)
        {
            ++ flags1[s[i] - 'a'];
        }

        for (int i = 0; i < size2; ++i)
        {
            ++ flags2[t[i] - 'a'];
        }

        for (int i = 0; i < (int)flags1.size(); ++i)
        {
            if (flags1[i] != flags2[i])
            {
                result = false;
                break;
            }
        }

        return result;
    }

/*
验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。*/
public:
    bool isPalindrome(string s) {
        bool result = true;
        auto isValid = [](char& ch){
            if ((ch >= 'a' && ch <= 'z')
                || (ch >= '0' && ch <= '9'))
            {
                return true;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + 'a' - 'A';
                return true;
            }
            else
            {
                return false;
            }
        };
        int j = (int)s.size() - 1;
        int i = 0;
        while(j > i)
        {
            if (!isValid(s[i]))
            {
                ++i;
                continue;
            }

            if (!isValid(s[j]))
            {
                --j;
                continue;
            }

            if (s[i] != s[j])
            {
                return false;
            }
            ++i;
            --j;
        }

        return result;
    } // isPalindrome

/*
字符串转换整数 (atoi)
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
*/
public:
    int myAtoi(string s) {
        int result = 0;
        bool findFirstChar = false;
        bool isPositive = true;
        for (const auto& ch : s)
        {
            if (!findFirstChar && ch == ' ')
            {
                continue;
            }
            else if (!findFirstChar && ch == '+')
            {
                isPositive = true;
                findFirstChar = true;
            }
            else if (!findFirstChar && ch == '-')
            {
                isPositive = false;
                findFirstChar = true;
            }
            else if ('0' <= ch && '9' >= ch)
            {
                findFirstChar = true;
                if (result <= (INT_MAX - (ch - '0')) / 10)
                {
                    result = result * 10 +(ch - '0');
                }
                else
                {
                    if (isPositive)
                    {
                        return INT_MAX;
                    }
                    else
                    {
                        return INT_MIN;
                    }
                }
            }
            else
            {
                break;
            }
        }

        if (!isPositive)
        {
            result = 0 - result;
        }

        return result;
    } // myAtoi

/*
实现 strStr()
实现 strStr() 函数。
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
 
说明：

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。
*/
    int strStr(string haystack, string needle) {
        int result = -1;

        return result;
    }

/*
最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
*/
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
        {
            return "";
        }
        string result = "";
        auto firstStr = strs[0];
        for (int i = 0; i < (int)firstStr.size(); ++i)
        {
            auto ch = firstStr[i];
            bool isSame = false;
            for (int j = 1; j < (int)strs.size(); ++j)
            {
                if (i >= strs[j].size() || ch != strs[j][i])
                {
                    return result;
                }
            }
            result.push_back(ch);
        }

        return result;
    } // longestCommonPrefix
}; // class Solution 
