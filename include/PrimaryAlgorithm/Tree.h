/*
初级算法-树
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
/*
二叉树的最大深度
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
*/
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        auto leftDep = maxDepth(root->left);
        auto rightDep = maxDepth(root->right);
        auto max = leftDep > rightDep ? leftDep : rightDep;
        return max + 1;
    }

// 102. 二叉树的层序遍历 https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
   public:
   vector<vector<int>> levelOrder(TreeNode* root) {
       if (root == nullptr)
       {
           return {};
       }
       vector<vector<int>> result;
       std::queue<TreeNode*> myQueue;
       myQueue.push(root);
       while(!myQueue.empty())
       {
           vector<int> oneLevel;
           int length = myQueue.size();

           while(length != 0)
           {
               if (auto node = myQueue.front())
               {
                   oneLevel.push_back(node->val);
                   if (node->left)
                   {
                       myQueue.push(node->left);
                   }
                   if (node->right)
                   {
                       myQueue.push(node->right);
                   }
               }
               --length;
           }
           result.push_back(oneLevel);
       }

       return result;
   }

   // 199. 二叉树的右视图 https://leetcode-cn.com/problems/binary-tree-right-side-view/
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root)
        {
            return {};
        }
        std::queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            int length = queue.size();
            TreeNode* top = nullptr;
            for (int i = 0; i < length; ++i)
            {
                top = queue.front();
                if (top)
                {
                    if (top->left)
                    {
                        queue.push(top->left);
                    }
                    if (top->right)
                    {
                        queue.push(top->right);
                    }
                }
                queue.pop();
            }
            result.push_back(top->val);
        }
        return result;
    }

    // 剑指 Offer II 045. 二叉树最底层最左边的值 https://leetcode-cn.com/problems/LwUNpT/
    int findBottomLeftValue(TreeNode* root) {
        int result = root->val;
        int maxDepth = 0;
        dfs_depth(1, root, result, maxDepth);

        return result;
    }

    void dfs_depth(int depth, TreeNode* root, int& result, int& maxDepth)
    {
        if (!root)
        {
            return;
        }
        if (depth > maxDepth)
        {
            maxDepth = depth;
            result = root->val;
        }
        dfs_depth(depth + 1, root->left, result, maxDepth);
        dfs_depth(depth + 1, root->right, result, maxDepth);
    }

    // 剑指 Offer II 044. 二叉树每层的最大值 https://leetcode-cn.com/problems/hPov7L/
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root)
        {
            return {};
        }

        std::queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            auto length = queue.size();
            int max = INT_MIN;
            for (int i = 0; i < length; ++i)
            {
                if (auto top = queue.front())
                {
                    if (top->left)
                    {
                        queue.push(top->left);
                    }
                    if (top->right)
                    {
                        queue.push(top->right);
                    }

                    if (top->val > max)
                    {
                        max = top->val;
                    }
                }
                queue.pop();
            }

            result.push_back(max);
        }
        return result;
    }

    // 剑指 Offer 38. 字符串的排列 https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
    vector<string> permutation(string s) {
        std::set<string> result;
        std::vector<bool> used(s.size(), false);
        std::string output;
        dfs_permutation(0, used, s, output, result);

        vector<string> outputVec;
        for(const auto& item : result) {
            outputVec.push_back(item);
        }
        return outputVec;
    }

    void dfs_permutation(int index, std::vector<bool>& used, string s, string& output, std::set<string>& result)
    {
        if (index == s.size())
        {
            result.insert(output);
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                output.push_back(s[i]);
                dfs_permutation(index + 1, used, s, output, result);
                used[i] = false;
                output.pop_back();
            }
        }
    }

    //剑指 Offer 26. 树的子结构 https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B)
        {
            return false;
        }
        auto rootA = A;

        if (rootA->val == B->val)
        {
            if (dfs_isSameStructure(rootA, B))
            {
                return true;
            }
        }

        if (rootA->left && isSubStructure(rootA->left, B))
        {
            return true;
        }

        if (rootA->right && isSubStructure(rootA->right, B))
        {
            return true;
        }

        return false;
    }

    bool dfs_isSameStructure(TreeNode* A, TreeNode* B)
    {
        if ((!B && A) || (B && !A))
        {
            return false;
        }

        if (B && A)
        {
            if (A->val != B->val)
            {
                return false;
            }
            else
            {
                if (!dfs_isSameStructure(A->left, B->left))
                {
                    return false;
                }

                if (!dfs_isSameStructure(A->right, B->right))
                {
                    return false;
                }
            }
        }

        return true;
    }

    // 剑指 Offer 04. 二维数组中的查找 https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int colum = matrix.size();
        if (colum == 0)
        {
            return false;
        }
        int row = matrix[0].size();
        if (row == 0)
        {
            return false;
        }

        bool find = find_findNumberIn2DArray(0, colum - 1, 0, row - 1, matrix, target);

        return find;
    }

    bool find_findNumberIn2DArray(int startCol, int endCol, int startRow, int endRow, vector<vector<int>>& matrix, int& target)
    {

        if (endCol-startCol <= 1 || endRow-startRow <= 1)
        {
            for (int j = startCol; j <= endCol; ++j)
            {
                for (int i = startRow; i <= endRow; ++i)
                {
                    if (target == matrix[j][i])
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        int midCol = (startCol + endCol) / 2;
        int midRow = (startRow + endRow) / 2;
        auto midNum = matrix[midCol][midRow];
        if (midNum == target)
        {
            return true;
        }
        else if (midNum > target)
        {
            endCol = midCol;
            endRow = midRow;
        }
        else
        {
            startCol = midCol;
            startRow = midRow;
        }

        return find_findNumberIn2DArray(startCol, endCol, startRow, endRow, matrix, target);
    }

    // 128. 最长连续序列 https://leetcode-cn.com/problems/longest-consecutive-sequence/
    int longestConsecutive(vector<int>& nums) {
//        int max = 0;
//        std::unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            map[num] = i;
//        }
//        
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            int start = 1;
//            int count = 1;
//            while(map.find(nums[i] + start) != end())
//            {
//                index++;
//                count++;
//            }
//
//            if (count > max)
//            {
//                max = count;
//            }
//        }
//
//        return max;
    }
}; // class Solution
