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
            cout << bitset<32>(n) << ", "<< bitset<32>(n & 1) << endl;
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
        uint32_t result = 0;
        while(n != 0)
        {
            result = result << 1;
            if (!(n ^ 1))
            {
                result ++;
            }
            n = n >> 1;
        }

        return result;
    } // reverseBits
};