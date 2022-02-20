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
}; // class Solution
