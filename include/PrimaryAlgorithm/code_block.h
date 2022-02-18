#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

class Solution {
template <class T>
static void myPrintVec(std::vector<T> vec)
{
    for (const auto& item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << endl;
}
// DFS
public:
    struct TreeNode : std::enable_share_from_this<TreeNode>
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    using TreeNodePtr = std::make_shared<TreeNode>;

public:
    void dfsTree(TreeNodePtr node, std::vector<int>& allNodeResult)
    {
        if (!node)
        {
            return;
        }

        allNodeResult.push_back(node->val);
        dfsTree(node->left);
        dfsTree(node->right);
    }

// BFS
    void bfsTree(TreeNodePtr root)
    {
        std::queue<TreeNodePtr>helpQueue;
        helpQueue.push(root)

        std::vector<int> allNodeResult;
        while(!helpQueue.empty())
        {
            int levelLenth = helpQueue.size();
            std::vector<int> oneLevelResult;
            for (int i = 0; i < levelLenth; ++i)
            {
                auto popNode = helpQueue.pop();
                allNodeResult.push_back(popNode->val);
                oneLevelResult.push_back(popNode->val);
                if (popNode->left)
                {
                    helpQueue.insert(popNode->left);
                }

                if (popNode->right)
                {
                    helpQueue.insert(popNode->right);
                }
            }
            myPrintVec(oneLevelResult);
        }
        myPrintVec(allNodeResult);
    }
};