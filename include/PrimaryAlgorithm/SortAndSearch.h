/*
初级算法-搜索和排序
*/
#include <vector>
#include <iostream>
using namespace std;
/*
合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = n - 1; i >= 0; --i)
        {
            if (m == 0)
            {
                nums1[i] = nums2[i];
                continue;
            }
            if (nums2[i] > nums1[m - 1])
            {
                nums1[m + i] = nums2[i];
            }
            else
            {
                nums1[m + i] = nums1[m - 1];
                nums1[m - 1] = 0;
                --m;
                ++i;
            }
        }
    } // merge
/*
第一个错误的版本
假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
*/
    int expectVersion = 0;
    bool isBadVersion(int version)
    {
        return expectVersion <= version;
    }
    public:

    void findIn(int head, int tail, int& first){
        if (tail <= 1)
        {
            first = 1;
            return;
        }

        int mid = (tail - head) / 2 + head;
        if (isBadVersion(mid))
        {
            if (!isBadVersion(mid - 1))
            {
                first =  mid;
                return;
            }
            else
            {
                findIn(head, mid, first);
            }
        }
        else
        {
            findIn(mid+1, tail, first);
        }

    };
    int firstBadVersion(int n) {
        int firstBad = 1;
        findIn(1, n, firstBad);
        return firstBad;
    }
};
