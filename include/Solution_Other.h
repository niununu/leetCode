/*
初级算法-其他
*/
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;
/*
位1的个数
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n >= 1)
        {
            if (n & 1)
            {
                result++;
            }
            n = n >> 1;
        }
        return result;
    } // hammingWeight
/*
汉明距离
两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
*/
    int hammingDistance(int x, int y) {
        int result = 0;
        auto z = x ^ y;
        while(z != 0)
        {
            if (z & 1)
            {
                result++;
            }
            z = z >> 1;
        }
        return result;
    } // hammingDistance

/*
颠倒二进制位
颠倒给定的 32 位无符号整数的二进制位
*/
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0)
        {
            return 0;
        }
        uint32_t result = 0;
        bool find = false;
        int count = 32;
        while(count > 0 && n != 0)
        {
            count--;
            if (find)
            {
                result = result << 1;
            }

            if (n & 1)
            {
                if (!find)
                {
                    find = true;
                }

                result ++;
            }
            n = n >> 1;
        }

        while (count > 0)
        {
            result = result << 1;
            count --;
        }
        return result;
    } // reverseBits
/*
杨辉三角
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i)
        {
            if (i == 0)
            {
                result.push_back({ 1 });
                continue;
            }

            vector<int> row;
            row.resize(i + 1);
            auto preVec = result[i - 1];
            for (int j = 0; j < i + 1; ++j)
            {
                if (j == 0 || j == i)
                {
                    row[j] = 1;
                }
                else
                {
                    row[j] = preVec[j] + preVec[j - 1];
                }
            }
            result.push_back(row);
        }

        return result;
    }
};