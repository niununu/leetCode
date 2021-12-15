#include <stdio.h>
#include <vector>
#include <memory>

class SortBase : public std::enable_shared_from_this<SortBase>//Sort from small to large
{
public:
    virtual std::vector<int> sortFun(std::vector<int> input) = 0;

    template <class T> void swapFun(T &a, T &b)
    {
        auto tmp = a;
        a = b;
        b = tmp;
    }
};
using SortBasePtr = std::shared_ptr<SortBase>;

// class Proxy : public SortBase, public std::enable_shared_from_this<Proxy>
// {
// public:
//     std::vector<int> sortFun(std::vector<int> input) override
//     {
//         if (mSortBasePtr)
//         {
//             return mSortBasePtr->sortFun(input);
//         }
//         else
//         {
//             return input;
//         }
//     }

//     void setSortPtr(SortBasePtr ptr)
//     {
//         mSortBasePtr = ptr;
//     }
// private:
//     SortBasePtr mSortBasePtr;
// };

class Buddle : public SortBase, public std::enable_shared_from_this<Buddle>
{
public:
    std::vector<int> sortFun(std::vector<int> input) override;
};

class Quick : public SortBase, public std::enable_shared_from_this<Quick>
{
public:
    std::vector<int> sortFun(std::vector<int> input) override;

private:
    void quickSort(int left, int right, std::vector<int> &mInput);
};

class Chain : public SortBase, public std::enable_shared_from_this<Chain>
{
public:
    std::vector<int> sortFun(std::vector<int> input) override;

private:
    struct Node
    {
        int data;
        std::shared_ptr<Node> next{nullptr};
        std::shared_ptr<Node> before{nullptr};
    };
    using nodePtr = std::shared_ptr<Node>;
};

class Heap : public SortBase, public std::enable_shared_from_this<Heap>
{
public:
    std::vector<int> sortFun(std::vector<int> input) override;

private:
    void siftDown(int i, std::vector<int>& input);
};