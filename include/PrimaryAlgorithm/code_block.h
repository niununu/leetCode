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
    // 全排列

    void dfsNum(std::vector<char> input)
    {
        std::vector<char> input = {'A', 'B', 'C'};
        int length = input.size();
        bool booked[length] = { false };

        auto dfs = [&length, &booked](int index, std::string& output){
    // void dfs(int index, std::string& output)
    // {
        if (index == length - 1)
        {
            cout << output << endl;
            return;
        }

        for (int i = 0; i < length; ++i)
        {
            if (!booked[index])
            {
                output.insert(input[index]);
                booked[index] = true;
                dfs(index + 1, output);
                booked[index] = false;
            }
        }
    }
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