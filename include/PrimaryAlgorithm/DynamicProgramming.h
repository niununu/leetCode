#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 300. 最长递增子序列 https://leetcode-cn.com/problems/longest-increasing-subsequence/
    int lengthOfLIS(vector<int>& nums) {
        int maxLength = 1;
        int length = nums.size();
        std::vector<int> dp(length, 1);

        for (int end = 0; end < length; ++end)
        {
            for (int i = 0; i < end; ++i)
            {
                if (nums[end] > nums[i])
                {
                    auto added = dp[i] + 1;
                    dp[end] = dp[end] > added ? dp[end] : added;
                    maxLength = dp[end] > maxLength ? dp[end] : maxLength;
                }
            }
        }
        return maxLength;

        // for (int i = 0; i < length; ++i)
        // {
        //     auto tmp = getLength(i, dp, nums);
        //     if (maxLength < tmp)
        //     {
        //         maxLength = tmp;
        //     }
        // }
    }
// 最长递增子序列的个数
    int findNumberOfLIS(vector<int>& nums) {
        int result = 0;
        int maxLength = 1;
        int length = nums.size();
        std::vector<int> dp(length, 1);

        for (int end = 0; end < length; ++end)
        {
            for (int i = 0; i < end; ++i)
            {
                if (nums[end] > nums[i])
                {
                    auto added = dp[i] + 1;
                    dp[end] = dp[end] > added ? dp[end] : added;
                    if (dp[end] > maxLength)
                    {
                        maxLength = dp[end];
                        result = 1;
                    }
                    else if (dp[end] == maxLength)
                    {
                        result++;
                    }
                }
            }
        }
        if (maxLength == 1)
        {
            result = nums.size();
        }
        return result;
    }
//53. 最大子数组和
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
        {
            return -1;
        }

        int maxAdd = nums[0];
        int length = nums.size();
        // base case
        auto preDp = nums[0];
        for (int i = 1; i < length; ++i)
        {
            auto addedValue = preDp + nums[i];
            preDp = addedValue > nums[i] ? addedValue : nums[i];
            maxAdd = maxAdd > preDp ? maxAdd : preDp;
        }

        return maxAdd;
    } // maxSubArray

    // 俄罗斯套娃信封问题
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int result = 1;
        int length = envelopes.size();
        std::sort(envelopes.begin(), envelopes.end(), [](vector<int> i, vector<int> j){
            return (i[0]<j[0]);
        });

        std::vector<int> dp(length, 1);
        for (int end = 0; end < length; ++end)
        {
            for (int i = 0; i < end; ++i)
            {
                if ((envelopes[end][1] > envelopes[i][1]) && (envelopes[end][0] > envelopes[i][0]))
                {
                    dp[end] = dp[i] + 1 > dp[end] ? dp[i] + 1 : dp[end];
                    result = result < dp[end] ? dp[end] : result;
                }
            }
        }

        return result;
    }

    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int pre = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (pre == 0)
            {
                pre = pre > nums[i] ? pre : nums[i];
            }
            else
            {
                auto plus = nums[i] * nums[i - 1];
                pre = plus > nums[i] ? plus : nums[i];
            }
            result = pre > result ? pre : result;

        }

        return result;
    }
};
