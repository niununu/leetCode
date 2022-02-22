# 树
# 链表
# 搜索
## 广度优先
[102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

## 深度优先
[46. 全排列](https://leetcode-cn.com/problems/permutations/)

# 排序
## 堆排序
[剑指 Offer 40. 最小的 K 个数]
[215. 数组中的第 K 个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)
[703. 数据流中的第 K 大元素]
[347. 前 K 个高频元素]

```
# include <queue>
std::priority_queue<int, vector<int>, less<int>> queue; // 大顶堆
queue.top(); // 访问顶
queue.push(); // 添加
queue.pop(); // 删除顶
```
# 双指针
[1. 两数之和] (https://leetcode-cn.com/problems/two-sum/)
# 动态规划
[300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)
[53. 最大子数组和](https://leetcode-cn.com/problems/maximum-subarray/)
[俄罗斯套娃信封问题]
[最长递增子序列的个数]

# 系统设计
[146. LRU 缓存](https://leetcode-cn.com/problems/lru-cache/)

# 滑动窗口
[16. 最接近的三数之和](https://leetcode-cn.com/problems/3sum-closest/)

# 常用STL
## hash表 - unordered_map
```
#include <unordered_map>
using stringmap = std::unordered_map<std::string,std::string>;
// init
stringmap first = {{"AAPL","Apple"},{"MSFT","Microsoft"}};

// add
first.insert ( {{"sugar",0.8},{"salt",0.1}} );
stringmap["aaa"] = "aaa";

// modify
stringmap["sugar"] = "sugar";

// remove
stringmap.earse("sugar");
```

## 双向链表 - list
```
#include <list>
// init
std::list<int> mylist;

// modify

auto head = mylist.front();
auto tail = mylist.back();

mylist.push_front(11);
mylist.pop_front();

mylist.push_back(77);
mylist.pop_back(22);

mylist.erase(iter);
mylist.insert(iter);
```

## 堆 - priority_queue
```
#include <queue>
// 小顶堆
using lessHeap = std::priority_queue<int, std::vector<int>, std::greater<int> >;
// 大顶堆 -- default
using bigHeap = std::priority_queue<int, std::vector<int>, std::less<int> >;

// 使用自定义比较
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

typedef std::priority_queue<int, std::vector<int>, mycomparison> mypq_type;

// modify
堆顶 = myHeap.top();
myHeap.pop(); // 删除顶
myHeap.push(11);

// swap
```





