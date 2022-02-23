#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
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
// 53. 最大子数组和
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
// 买卖股票的最佳时机
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

// 买卖股票的最佳时机 III
    int maxProfit_III(std::vector<int> prices)
    {
        int max = 0;
        int length = prices.size();
        int min1 = prices[0];
        for (int i = 0; i < length; ++i)
        {
            auto profit1 = prices[i] - min1;
            min1 = std::min(min1, prices[i]);

            int max2 = 0;
            int nextStart = i + 2;
            if (nextStart < length)
            {
                int min2 = prices[nextStart - 1];
                for (int j = nextStart; j < length; ++j)
                {
                    auto profit2 = prices[j] - min2;
                    min2 = std::min(min2, prices[j]);
                    max2 = std::max(max2, profit2);
                }

            }

            auto profit = profit1 + max2;
            max = std::max(max, profit);
        }

        return max;
    }

// 买卖股票的最佳时机含手续费
    int maxProfit(std::vector<int> prices, int fee)
    {
        int length = prices.size();
        if (length < 2)
        {
            return 0;
        }
        std::vector<std::vector<int>> dp(length, std::vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];
        int max = 0;

        for (int i = 1; i < length; ++i)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            max = std::max(max, std::max(dp[i][0], dp[i][1]));
        }

        return max;
    }

// 打家劫舍
    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 0)
        {
            return 0;
        }
        std::vector<std::vector<int>> dp(length, std::vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        int max1 = nums[0];

        for (int i = 1; i < length - 1; ++i)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];

            max1 = std::max(max1, std::max(dp[i][0], dp[i][1]));
        }
        if (length < 2) {
            return  max1;
        }
        dp[1][0] = 0;
        dp[1][1] = nums[1];
        int max2 = nums[1];

        for (int i = 2; i < length; ++i)
        {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];

            max2 = std::max(max2, std::max(dp[i][0], dp[i][1]));
        }

        return std::max(max1, max2);
    }

// 740. 删除并获得点数 https://leetcode-cn.com/problems/delete-and-earn/
    int deleteAndEarn(vector<int>& nums) {
        std::unordered_map<int, int> map;
        int maxNum = 0;
        for(const auto& num : nums)
        {
            maxNum = std::max(maxNum, num);
            // if (map.find(num) != map.end())
            // {
            //     map[num]++;
            // }
            // else
            // {
            //     map[num] = 1;
            // }
            map[num] = map[num] + 1;
        }

        std::vector<std::vector<int>> dp(maxNum+1, std::vector<int>(2, 0));
        int max = 0;
        for(auto iter = map.begin(); iter != map.end(); ++iter)
        {
            int i = iter->first;
            int times = iter->second;
            // if (map.find(i - 1) == map.end())
            // {
            //     /* code */
            // }
            dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][0] + i * times;
            max = std::max(max, std::max(dp[i][0], dp[i][1]));
        }

        return max;
    }
}; // class Solution
