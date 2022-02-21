/*
初级算法-搜索和排序
*/
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
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

    // Heap_sort
    // 215. 数组中的第K个最大元素 https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
    public:
    int findKthLargest(vector<int>& nums, int k) {
        int result = nums[0];
        int vecLength = nums.size();
        adjustHeap(nums, vecLength);
        k = k <= vecLength ? k : vecLength;
        for (int i = 0; i < k; ++i)
        {
            swap(nums[0], nums.back());
            result = nums.back();
            nums.pop_back();
            std::cout << result << endl;
            vecLength = nums.size();
            adjustHeap(nums, vecLength);
        }
        
        return result;
    }

    void adjustHeap(vector<int>& nums, int& vecLength)
    {
        for (int i = vecLength/2 - 1; i >= 0; --i)
        {
            adjustPerBigHeap(i, nums, vecLength);
        }
    }

    void adjustPerBigHeap(int root, vector<int>& nums, int vecLength)
    {
        int left = 2*root + 1;
        int right = 2*root + 2;
        if (left >= vecLength)
        {
            return;
        }
        int max = left;
        if (right < vecLength)
        {
            max = nums[left] > nums[right] ? left : right;
        }

        if (nums[root] < nums[max])
        {
            swap(nums[root], nums[max]);
        }
    }
    // 692. 前K个高频单词 https://leetcode-cn.com/problems/top-k-frequent-words/
    // vector<string> topKFrequent(vector<string>& words, int k) {
    //     vector<string> result;
    //     std::unordered_map<std::string, int> frequentMap;
    //     int length = 0;
    //     auto adjustPreHeap = [&frequentMap, length](int root){
    //         auto left = root*2 + 1;
    //         auto right = root*2 + 2;
    //         if (left >= length)
    //         {
    //             return;
    //         }

    //         int max = left;
    //         if (right < length)
    //         {
    //             max = frequentMap[left].second() > frequentMap[right].second() ? left : right;
    //         }

    //         if (frequentMap[max].second() < frequentMap[root].second())
    //         {
    //             swap(frequentMap[max], frequentMap[root]);
    //         }
    //     }

    //     auto adjustHeap = [length](){
    //         for (int i = length/2 - 1; i > 0; --i)
    //         {
    //             adjustPreHeap(i);
    //         }
    //     }

    //     for(const auto& word : words)
    //     {
    //         if (frequentMap.find(word) != frequentMap.end())
    //         {
    //             frequentMap[word] = 1;
    //         }
    //         else
    //         {
    //             ++frequentMap[word];
    //         }
    //     }
    //     length = frequentMap.size();

    //     adjustHeap();
    //     for (int i = 0; i < k; ++i)
    //     {
    //         result.push_back(frequentMap[length - 1].first());
    //         swap(frequentMap[0], frequentMap[length - 1]);
    //         frequentMap.erase();
    //     }
    // }

// 46. 全排列 https://leetcode-cn.com/problems/permutations/
    vector<vector<int>> permute(vector<int>& nums) {
        int length = nums.size();
        if (length == 0)
        {
            return {};
        }
        vector<vector<int>> results;
        std::vector<bool> used(length, false);
        vector<int> preResult;
        preResult.resize(length);
        dfsPermute(0, length, preResult, nums, used, results);

        return results;
    }

    void dfsPermute(int depth, int& length, vector<int> preResult, vector<int>& nums, std::vector<bool>& used, vector<vector<int>>& results)
    {
        if (depth == length)
        {
            results.push_back(preResult);
            return;
        }

        for (int i = 0; i < length; ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                preResult.push_back(nums[i]);
                dfsPermute(depth + 1, length, preResult, nums, used, results);
                used[i] = false;
                preResult.pop_back();
            }
        }
    }

    // 剑指 Offer 40. 最小的 K 个数
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result;
        std::priority_queue<int, vector<int>, less<int>> queue;
        for (int i = 0; (i < k) && (i < arr.size()); ++i)
        {
            queue.push(arr[i]);
        }

        for (int i = k; i < arr.size() && !queue.empty(); ++i)
        {
            if (queue.top() > arr[i])
            {
                queue.pop();
                queue.push(arr[i]);
            }
        }

        while (!queue.empty())
        {
            result.push_back(queue.top());
            queue.pop();
        }
        return result;

/*        if (k == 0)
        {
            return {};
        }
        vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k; ++i)
        {
            result.push_back(arr[i]);
        }

        auto adjustHeap = [&k, &result](){
            for (int i = k/2 - 1; i >= 0; --i)
            {
                int root = i;
                auto left = root*2 + 1;
                auto right = left + 1;
                if (left >= k)
                {
                    return;
                }

                auto max = left;
                if (right < k)
                {
                    max = result[left] > result[right] ? left : right;
                }

                if (result[root] < result[max])
                {
                    swap(result[root], result[max]);
                }
            }
        }; 
        adjustHeap();
        for (int i = k; i < arr.size(); ++i)
        {
            if (arr[i] < result[0])
            {
                result[0] = arr[i];
                adjustHeap();
            }
        }

        return result;
*/

    }

    // 347. 前 K 个高频元素
    // public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     using timesPair = std::pair<int, int>();
    //     // vector<timesPair> result;

    //     std::unordered_map<int, int> timesMap;
    //     for (const auto& num : nums)
    //     {
    //         auto iter = timesMap.find(num);
    //         if (iter != timesMap.end())
    //         {
    //             timesMap[num] = 1;
    //         }
    //         else
    //         {
    //             iter->second++;
    //         }
    //     }
    //     auto cmp = [](timesPair m, timesPair n){
    //         return m.second > n.second;
    //     };
    //     std::priority_queue<timesPair,std::vector<timesPair>, cmp> heap;

    //     for (auto& [key, times] : timesMap)
    //     {
            
    //     }
    // }

};// class Solution

// 703. 数据流中的第 K 大元素
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        heapLength = k;
        if (k == 0)
        {
            return;
        }

        for (int i = 0; i < k && i < nums.size(); ++i)
        {
            mHeap.push_back(nums[i]);
        }
        adjustHeap();
        for (int i = k; i < nums.size(); ++i)
        {
            add(nums[i]);
        }
    }

    void adjustHeap()
    {
        int k = mHeap.size();
        for (int i = k/2 - 1; i >= 0; --i)
        {
            int root = i;
            auto left = 2 * root + 1;
            auto right = left + 1;
            if (left >= k)
            {
                return;
            }

            auto min = left;
            if ((right < k) && (mHeap[right] < mHeap[left]))
            {
                min = right;
            }

            if (mHeap[0] > mHeap[min])
            {
                swap(mHeap[0], mHeap[min]);
            }
        }
    }

    int add(int val) {
        if (mHeap.size() < heapLength) {
            mHeap.push_back(val);
            if (mHeap.size() == heapLength) {
                adjustHeap();
            }
        }
        else if (val > mHeap[0])
        {
            mHeap[0] = val;
            adjustHeap();
        }
        std::cout << mHeap[0] << endl;
        return mHeap[0];
    }

private:
    std::vector<int> mHeap;
    int heapLength{ 0 };
}; // class KthLargest

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
