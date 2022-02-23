/*
初级算法-搜索和排序
*/
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

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
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        using wordTimesMapPair = std::pair<std::string, int>;
        std::unordered_map<std::string, int> wordTimesMap;
        for (const auto& word : words)
        {
            if (wordTimesMap.find(word) != wordTimesMap.end())
            {
                wordTimesMap[word]++;
            }
            else
            {
                wordTimesMap[word] = 1;
            }
        }

        struct myCmp
        {
            bool operator() (wordTimesMapPair pair1, wordTimesMapPair pair2)
            {
                if (pair1.second > pair2.second)
                {
                    return true;
                }
                else if (pair1.second == pair2.second)
                {
                    return pair1.first < pair2.first;
                }
                else
                {
                    return false;
                }
            }
        };
        std::priority_queue<wordTimesMapPair, std::vector<wordTimesMapPair>, myCmp> heap;

        for (auto iter = wordTimesMap.begin(); iter != wordTimesMap.end(); ++iter)
        {
            if (heap.size() == k)
            {
                auto top = heap.top();
                myCmp x;
                if (!x(top, *iter))
                {
                    heap.pop();
                    heap.push(*iter);
                }
            }
            else
            {
                heap.push(*iter);
            }
        }
        result.resize(k);
        for (int i = k - 1; i >= 0 && !heap.empty(); --i)
        {
            result[i] = heap.top().first;
            heap.pop();
        }
        return result;
    }

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
    }

    // 347. 前 K 个高频元素 https://leetcode-cn.com/problems/top-k-frequent-elements/submissions/
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> hashMap;
        using mapPair = std::pair<int, int>;
        for (const auto& num : nums)
        {
            if (hashMap.find(num) != hashMap.end())
            {
                hashMap[num]++;
            }
            else
            {
                hashMap[num] = 1;
            }
        }
        struct myCmp
        {
            bool operator() (mapPair pair1, mapPair pair2)
            {
                return pair1.second > pair2.second;
            }
        };
        std::priority_queue<mapPair, vector<mapPair>, myCmp> queue;
        for (auto iter = hashMap.begin(); iter != hashMap.end(); ++iter)
        {
            if (queue.size() == k)
            {
                auto top = queue.top();
                myCmp cmp;
                if (!cmp(top, *iter))
                {
                    queue.pop();
                    queue.push(*iter);
                }
            }
            else
            {
                queue.push(*iter);
            }
        }

        while(!queue.empty())
        {
            result.push_back(queue.top().first);
            queue.pop();
        }
        return result;
    }

    // 1. 两数之和 https://leetcode-cn.com/problems/two-sum/
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto diff = target - nums[i];
            if (hashMap.find(diff) != hashMap.end())
            {
                result.push_back(hashMap[diff]);
                result.push_back(i);
                break;
            }
            else
            {
                hashMap[nums[i]] = i;
            }
        }


        return result;
    }
    // 15. 三数之和
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return {};
        }

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            /* code */
        }

        return result;
    }
// 16. 最接近的三数之和
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        int preSum = nums[0] + nums[1] + nums[2];
        int resultPlus = preSum;
        int minDiff = abs(target - preSum);

        for (int begin = 1; begin < nums.size() - 2; ++begin)
        {
            auto end = begin + 2;
            preSum = preSum - nums[begin - 1] + nums[end];
            auto diff = abs(target - preSum);

            if (diff == 0)
            {
                return preSum;
            }

            if (minDiff > diff)
            {
                minDiff = diff;
                resultPlus = preSum;
            }
        }

        return resultPlus;
    }

    vector<vector<int>> fun(int input) {
        vector<vector<int>> result;
        std::vector<int> popVec;
        
        std::list<int> list;
        for (int i = 1; i <= input; ++i)
        {
            list.push_back(i);
        }
        auto iter = list.begin();
        while(list.size() != 2)
        {
            if (iter == list.end())
            {
                iter = list.begin();
            }

            iter = iter++;
            iter = iter++;

            popVec.push_back(*iter);
            list.erase(iter);
        }
        result.push_back(popVec);

        vector<int> remindVec;
        remindVec.push_back(list.front());
        remindVec.push_back(list.back());
        result.push_back(remindVec);


        return result;
    }

    
    std::vector<int> remindTwo(int input)
    {
        std::list<int> list;
        for (int i = 1; i <= input; ++i)
        {
            list.push_back(i);
        }

        auto iter = std::next(list.begin(), 1);
        auto moveOneStep = [&list](std::list<int>::iterator iter){
            auto next = std::next(iter, 1);
            if (next == list.end())
            {
                next = list.begin();
            }
            return next;
        };

        while(list.size() != 2)
        {
            auto next = moveOneStep(iter);
            list.erase(iter);
            iter = moveOneStep(next);
        }

        return {list.front(), list.back()};
    }

    bool searchMatric(std::vector<std::vector<int>> nums, int target)
    {
        int col = nums.size();
        if (col.size() == 0)
        {
            return false;
        }
        int row = nums[0].size();
        if (row.size() == 0)
        {
            return false;
        }

        int i = 0;
        int j = row -1;
        int flag = nums[i][j];

        while((i < col) && (j < row))
        {
            if (target == flag)
            {
                return true;
            }
            else if (target > flag)
            {
                flag = nums[i + 1][j];
            }
            else
            {
                flag = nums[i][j - 1];
            }
        }

        return false;
    }

    int maxProfit(std::vector<int> prices)
    {
        int length = prices.size();
        std::vector<std::vector<int>> dp(length, std::vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];
        int i = 1;
        int max = 0;
        while(i < length)
        {
            dp[i][0] = dp[i - 1][0] > dp[i - 1][1] + prices[i] ? dp[i - 1][0] : dp[i - 1][1] + prices[i];
            dp[i][1] = dp[i - 1][1] > dp[i - 1][0] - prices[i] ? dp[i - 1][1] : dp[i - 1][0] - prices[i];
            if (dp[i][0] > max)
            {
                max = dp[i][0];
            }
        }

        return max;
    }
};// class Solution
