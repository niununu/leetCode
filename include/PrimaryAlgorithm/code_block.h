// Heap
#include <queue>
using pair = std::pair<int, int>;
struct myCmp
{
    bool operator() (pair pair1, pair pair2) const
    {
        return pair1.second > pair2.second; // true means need adjust
    }
};
std::priority_queue<pair, std::vector<pair>, myCmp> queue;
queue.push(**);
auto top = queue.top();
queue.pop();

// Hash map
#include <unordered_map>
std::unordered_map<int, int> hashMap;

// sort
#include <algorithm>
std::sort(vec.begin(), vec.end(), [](int i, int j){
    return i > j;
}); // default < 

// list
#include <list>
std::list<string> list{ "a", "b", "c"};
string front = list.front();
string back = list.back();
list.erase(iter);
auto it = list.begin();
it = list.insert(it, "200");
list.push_front("a");
list.push_back("a");
list.pop_front();
list.pop_back();
list1.merge(list2);

// iterator
#include <iterator>
auto nextNext = std::next(iter, 2);
auto prevPrev = std::prev(it, 2);
auto items = std::distance(il.begin(), il.end());
// DFS
/*
std::vector<int> nums;
int length = nums.size();
std::vector<bool> used{ length, false };
*/
void dfs(int index, std::vector<int>& oneOption)
{
    if (oneOption.size() == length)
    {
        // cout << oneOption;
        return;
    }

    for (int i = 0; i < length; ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            oneOption.push_back(nums[i]);
            dfs(index + 1, oneOption);
            used[i] = false;
            oneOption.pop_back();
        }
    }
}

// BFS
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
 */
std::vector<std::vector<int>> bfs(TreeNode* root)
{
    std::vector<std::vector<int>> results;
    if (root == nullptr)
    {
        return {};
    }

    std::queue<TreeNode*> queue;
    queue.push_back(root);
    while(!queue.empty())
    {
        auto length = queue.size();
        std::vector<int> oneLevel;

        for (int i = 0; i < length; ++i)
        {
            if (auto top = queue.pop_front())
            {
                oneLevel.push_back(top->val);
                if (top->left)
                {
                    queue.push_back(top->left);
                }

                if (top->right)
                {
                    queue.push_back(top->right);
                }
            }
        }
        results.push_back(oneLevel);
    }
    return results;
}

