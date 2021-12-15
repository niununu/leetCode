#include <iostream>
#include <vector>
#include "../include/Sort.h"

std::vector<int> Buddle::sortFun(std::vector<int> input)
{
    int size = input.size();
    for (auto i = 0; i < size; ++i)
    {
        for (auto j = 0; j + 1 < size - i; ++j)
        {
            if (input[j] > input[j + 1])
            {
                SortBase::swapFun(input[j], input[j + 1]);
            }
        }
    }

    return input;
}

std::vector<int> Quick::sortFun(std::vector<int> input)
{
    quickSort(0, int(input.size() - 1), input);
    return input;
}

void Quick::quickSort(int left, int right, std::vector<int> &mInput)
{
    if (left > right)
    {
        return;
    }
    auto tmp = mInput[left];
    auto i = left;
    auto j = right;
    while (i != j)
    {
        while (mInput[j] >= tmp && i < j)
        {
            j--;
        }
        while (mInput[i] <= tmp && i < j)
        {
            i++;
        }

        if (i < j)
        {
            swapFun(mInput[i], mInput[j]);
        }
    }

    swapFun(mInput[left], mInput[i]);

    quickSort(left, i - 1, mInput);
    quickSort(i + 1, right, mInput);
}

std::vector<int> Chain::sortFun(std::vector<int> input)
{
    nodePtr head{nullptr};
    // nodePtr tail{ nullptr };
    // nodePtr mNodeChain = std::make_shared<Node>();
    nodePtr headNodeChain = std::make_shared<Node>();

    for (const auto &data : input)
    {
        if (!head)
        {
            headNodeChain->data = data;
            head = headNodeChain;
            // tail = mNodeChain->next;
        }
        else
        {
            for (auto iter = head; iter != nullptr; iter = iter->next)
            {
                nodePtr nodeChain = std::make_shared<Node>();
                if (data > iter->data)
                {
                    // hou
                    if (!iter->next)
                    {
                        iter->next = nodeChain;
                        nodeChain->before = iter;
                        break;
                        // tail = nodeChain->next;
                    }
                    else if (iter->next->data <= iter->data)
                    {
                        iter->next->before = nodeChain;
                        nodeChain->next = iter->next;
                        iter->next = nodeChain;
                        nodeChain->before = iter;
                        break;
                    }
                }
                else
                {
                    // qian
                    if (!iter->before)
                    {
                        iter->before = nodeChain;
                        nodeChain->next = iter;
                        head = nodeChain;
                        break;
                    }
                    else if (iter->before->data >= iter->data)
                    {
                        iter->before->next = nodeChain;
                        nodeChain->before = iter->before;
                        iter->before = nodeChain;
                        nodeChain->next = iter;
                        break;
                    }
                }

                if (iter->next == nullptr)
                {
                    iter->next = nodeChain;
                    nodeChain->before = iter;
                }
            }
        }
    }
    std::vector<int> output;
    for (auto iter = head; iter != nullptr; iter = iter->next)
    {
        output.push_back(iter->data);
    }

    return output;
}

std::vector<int> Heap::sortFun(std::vector<int> input)
{
    int size = input.size();
    // create heap
    for (int i = size/2; i >= 0; --i)
    {
        siftDown(i, input);
        std::cout << "[" << i << "] : ";
        for (const auto& o : input)
        {
            std::cout << o << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> output;
    for (int i = size - 1; i >= 0; --i)
    {
        output.push_back(input[0]);
        swapFun(input[i], input[0]);
        siftDown(0, input);
    }
    
    return output;
}

void Heap::siftDown(int i, std::vector<int>& input)
{
    auto size = (int)input.size();
    bool ok = false;
    while(2 * i < size && !ok)
    {

    // }
    // for (; i < input.size(); ++i)
    // {
		int index = i;
        // if (2 * i < input.size())
        {
            if (input[i] < input[2*i])
            {
                index = 2*i;
            }
        }

        if ((2*i + 1) < size)
        {
            if (input[i] < input[2*i + 1])
            {
                index = 2*i + 1;
            }
        }

        if (index != i)
        {
            swapFun(input[index], input[i]);
            i = index;
        }
        else
        {
            ok = true;
        }
    }
}