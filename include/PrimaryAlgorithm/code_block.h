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

// DFS
std::vector<int> nums;
int length = nums.size();
std::vector<bool> used{ length, false };
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
std::vector<std::vector<int>> bfs(std::vector<int> nums)
{
}