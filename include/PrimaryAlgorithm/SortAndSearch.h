/*
初级算法-搜索和排序
*/
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
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
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            auto twoSum = twoSum_threeSum(nums, 0 - nums[i], i);
            for (auto& item : twoSum)
            {
                item.push_back(nums[i]);
                results.push_back(item);
            }
        }

        return results;
    }
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        if (nums.size() < 3)
//        {
//            return {};
//        }
//        std::sort(nums.begin(), nums.end());
//        vector<vector<int>> results;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            if (i > 0 && nums[i] == nums[i - 1])
//            {
//                continue;
//            }
//            auto twoSum = twoSum_threeSum(nums, 0 - nums[i], i);
//            for (auto& item : twoSum)
//            {
//                item.push_back(nums[i]);
//                results.push_back(item);
//            }
//        }
//
//        return results;
//    }

    vector<vector<int>> twoSum_threeSum(std::vector<int> nums, int target, int cur)
    {
        vector<vector<int>> results;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == cur || (i > 0 && nums[i] == nums[i - 1]))
            {
                continue;
            }
            auto iter = map.find(target - nums[i]);
            if (iter != map.end())
            {
                int index = map[target - nums[i]];
                results.push_back({nums[index], nums[i]});
                map.erase(iter);
            }
            else
            {
                map[nums[i]] = i;
            }
        }

        return results;
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
        if (col == 0)
        {
            return false;
        }
        int row = nums[0].size();
        if (row == 0)
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

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        int length = nums.size();
        std::vector<bool> used (length, false);
        std::sort(nums.begin(), nums.end());
        std::vector<int> oneResult;
        dfs(0, used, oneResult, results, nums);

        return results;
    }

    void dfs(int index, std::vector<bool>& used, std::vector<int>& oneResult, vector<vector<int>>& results, vector<int>& nums)
    {
        if (oneResult.size() == nums.size())
        {
            results.push_back(oneResult);
            return;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            if (used[i] || (i > 1 && (nums[i - 1] == nums[i])))
            {
                continue;
            }
            else
            {
                used[i] = true;
                oneResult.push_back(nums[i]);
                dfs(index + 1, used, oneResult, results, nums);
                used[i] = false;
                oneResult.pop_back();
            }
        }
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2)
        {
            return intervals;
        }

        vector<vector<int>> results;
        std::sort(intervals.begin(), intervals.end(), [](vector<int> vec1, vector<int> vec2){
            return(vec1[0] < vec2[0]);
        });
        auto iter = intervals.begin();
        while(iter != intervals.end())
        {
            auto next = std::next(iter, 1);
            if (next != intervals.end())
            {
                if (next->at(0) <= iter->at(1))
                {
                    next->at(0) = iter->at(0);
                    next->at(1) = std::max(next->at(1), iter->at(1));
                    intervals.erase(iter);
                    iter = next;
                    continue;
                }
            }
            iter++;
        }

        return intervals;
    }

public:
    int removeElement(vector<int>& nums, int val) {
        std::sort(nums.begin(), nums.end(), [](int num1, int num2){
            return num1 < num2;
        });
        int start = 0;
        int end = nums.size() - 1;
        while(start < end)
        {
            int mid = (end + start) / 2;
            if (nums[mid] == val)
            {
                int i = mid - 1;
                int j = mid + 1;
                int result = 1;
                while(i >= 0 && nums[i] == val)
                {
                    --i;
                    result++;
                }
                while(j < nums.size() && nums[j] == val)
                {
                    ++j;
                    result++;
                }
                nums.erase(nums.begin() + i, nums.begin()+ j);

                return result;

            }
            else if (nums[mid] > val)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return 0;
    }

    bool checkInclusion(string s1, string s2) {
        std::sort(s1.begin(), s1.end());
        int length = s1.length();
        int length2 = s2.length();
        int start = 0;

        auto isSameStr = [&s1](string str){
            std::sort(str.begin(), str.end());
            return s1 == str;
        };

        while(start + length - 1 < length2)
        {
            if (isSameStr(s2.substr(start, length)))
            {
                return true;
            }
            start++;
        }

        return false;
    }

    int numSquares(int n) {
        // int result = 0;
        vector<int> nums;
        func(nums, n);
        return nums.size();
    }

    void func(vector<int>& nums, int target)
    {
        if (target == 0)
        {
            return;
        }
        float sqrtResult = sqrt(target);
        nums.push_back((int)sqrtResult);
        if ((sqrtResult - (int)sqrtResult) == 0)
        {
            return;
        }
        func(nums, target - (int)sqrtResult*(int)sqrtResult);
    }

    int longestArithSeqLength(vector<int>& nums) {
        int length = nums.size();
        if(length < 3)
        {
            return length;
        }
        int result = 2;
        unordered_map<int, set<int>> indexMap;
        vector<vector<int>> len(length, vector<int>(length, 2));
        indexMap[nums[0]] = {0};
        for(int i = 1; i < length - 1; ++i)
        {
            indexMap[nums[i]].insert(i);
            for(int j = i + 1; j < length; ++j)
            {
                auto expectBefore = nums[i] - (nums[j] - nums[i]);
                //cout<<"J:"<<nums[j]<<", I:"<<nums[i]<<", B:"<< expectBefore<<endl;
                if(indexMap.find(expectBefore) != indexMap.end())
                {
                    auto indexVec = indexMap[expectBefore];
                    int maxlen = 0;
                    for(const auto& index : indexVec)
                    {
                        if(index < i)
                        {
                            //cout<<"???: "<<index << endl;
                            maxlen = std::max(maxlen, len[index][i] + 1);
                        }
                    }
                    len[i][j] = maxlen;
                    result = std::max(result, len[i][j]);
                }
            }
        }

        return result;
    }

    int findNumberOfLIS2(vector<int>& nums) {
        int length = nums.size();
        int count = 1;
        int maxLen = 1;
        vector<int> dp (length, 1);
        vector<int> maxCount(length, 1);
        for(int i = 1; i < length; ++i)
        {
            int _count = 0;
            for(int j = i - 1; j >= 0; --j)
            {
                if(nums[j] < nums[i])
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        _count = maxCount[j];
                    }
                    else if(dp[j] + 1 == dp[i])
                    {
                        _count += maxCount[j];
                    }
                    //dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            maxCount[i] = std::max(maxCount[i], _count);
            if(dp[i] > maxLen)
            {
                maxLen = dp[i];
                count = maxCount[i];
            }
            else if (dp[i] == maxLen)
            {
                //count += _count > 0 ? _count : 1;
                count += maxCount[i];
            }
        }

        return count;
    }

    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> dp (length, vector<int>(length, 0));
        int start = length / 2;
        int end = start + 1;

        dp[start][end] = std::max(nums[start] + nums[end], std::max(nums[start], nums[end]));
        int maxSum = dp[start][end];
        while(start >= 0 && end < length)
        {
            start--;
            end++;
            dp[start][end] = dp[start + 1][end - 1] + std::max(nums[start] + nums[end], std::max(nums[start], nums[end]));
            maxSum = std::max(maxSum, dp[start][end]);
        }
        if(end == length - 1 && start > 0)
        {
            while(start - 1 >= 0)
            {
                start--;
                if(nums[start] > 0)
                {
                    maxSum += nums[start];
                }
            }
        }
        else if (start == 0 && end < length)
        {
            while(end < length - 1)
            {
                end++;
                if(nums[start] > 0)
                {
                    maxSum += nums[end];
                }
            }
        }
        return maxSum;
    }

    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        if(length == 1)
        {
            return nums[0];
        }    
        int maxPlus = nums[0];
        int plusWindow = nums[0];
        int start = 0;
        int end = start + 1;
        while(end < length && start <= end)
        {
            if(plusWindow * nums[end] > plusWindow)
            {
                plusWindow = plusWindow * nums[end];
                end++;
            }
            else
            {
                maxPlus = std::max(maxPlus, plusWindow);
                if(nums[start] != 0)
                {
                    plusWindow = plusWindow / nums[start];
                }
                else
                {
                    plusWindow = 1;
                    for(int i = start + 1; i < length && i <= end; ++i)
                    {
                        plusWindow *= nums[i];
                    }
                }
                start++;
            }
        }
        maxPlus = std::max(maxPlus, plusWindow);
        return maxPlus;
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> result;
        std::priority_queue<int> heap;
        //for(auto num : arr)
        for(int i = 0; i < arr.size(); ++i)
        {
            if(heap.size() == k)
            {
                auto top = heap.top();
                if(top > arr[i])
                {
                    heap.pop();
                    heap.push(arr[i]);
                }
            }
            else
            {
                heap.push(arr[i]);
            }
        }

        while(!heap.empty())
        {
            result.push_back(heap.top());
            heap.pop();
        }

        return result;
    }


    int longestCommonSubsequence(string text1, string text2) {
        int maxLen = 0;
        int length1 = text1.length();
        int length2 = text2.length();
        vector<vector<int>> dp (length1 + 1, vector<int>(length2 + 1, 0));
        for(int i = 1; i < length1 + 1; ++i)
        {
            for(int j = 1; j < length2 + 1; ++j)
            {
                if(text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
                maxLen = std::max(maxLen, dp[i][j]);
            }
        }

        return maxLen;
    }

    int longestPalindromeSubseq(string s) {
        int length = s.length();
        vector<vector<int>> dp (length, vector<int>(length, -1));
        if (length == 1)
        {
            return 1;
        }
//        for(int j = 1; j < length; ++j)
//        {
//            for(int i = 0; i < j; ++i)
//            {
//                if(j - i == 1)
//                {
//                    dp[i][j] = s[i] == s[j] ? 2 : 1;
//                }
//                else if(s[i] == s[j])
//                {
//                    dp[i][j] = dp[i + 1][j - 1] + 2;
//                }
//                else
//                {
//                    dp[i][j] = std::max(dp[i + 1][j - 1], std::max(dp[i][j - 1], dp[i + 1][j]));
//                }
//            }
//        }

        return getDp(0, length - 1, dp, s);
    }
    
    int getDp(int i, int j, vector<vector<int>>& dp, string& s)
    {
        if (i > j || j > s.length() -1 || i < 0) {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
            if(j - i == 1)
            {
                dp[i][j] = s[i] == s[j] ? 2 : 1;
            }
            else if(i == j)
            {
                dp[i][j] = 1;
            }
            else if(s[i] == s[j])
            {
//                dp[i][j] = dp[i + 1][j - 1] + 2;
                dp[i][j] = getDp(i + 1, j - 1, dp, s) + 2;

            }
            else
            {
                dp[i][j] = std::max(getDp(i + 1, j - 1, dp, s), std::max(getDp(i, j - 1, dp, s), getDp(i + 1, j, dp, s)));
            }
        return dp[i][j];
    }

    int searchaaa(vector<int>& nums, int target) {
        int length = nums.size();
        return searchHelper(0, length - 1, nums, target);
    }

    int searchHelper(int left, int right, vector<int>& nums, int target)
    {
        if(left > right || left > nums.size() - 1 || right > nums.size() - 1)
        {
            return -1;
        }

        if(left == right)
        {
            return nums[left] == target ? left : -1;
        }

        int mid = (right + left) / 2;
        if(nums[mid] == target)
        {
            return mid;
        }

        if (target > nums[mid])
        {
//            if (nums[left] < nums[mid] && nums[])
//            {
//                right = mid + 1;
//            }
//            else
            {
                if (nums[right] < target)
                {
                    left = mid - 1;
                }
                else
                {
                    right = mid + 1;
                }
            }
        }
        else // target < nums[mid]
        {
            if (nums[left] < nums[mid] && nums[left] < target)
            {
                left = mid - 1;
            }
            else
            {
                if (nums[left] > target)
                {
                    right = mid + 1;
                }
                else
                {
                    left = mid - 1;
                }
            }
        }


        searchHelper(left, right, nums, target);
    }

};// class Solution
