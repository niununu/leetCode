//146. LRU 缓存
// https://leetcode-cn.com/problems/lru-cache/
#include <unordered_map>
#include <list>
#include <memory.h>
#include <iostream>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        mCapacity = capacity;
    }
    
    int get(int key) {
        int value = -1;
        if (cacheTable.find(key) != cacheTable.end())
        {
            auto iter = cacheTable[key];
            value = iter->second;
            cacheList.erase(iter);
            cacheList.push_back(std::make_pair(key, value));
            cacheTable[key] = --cacheList.end();
        }
        cout << "value :" << value << std::endl;
        printMap();
        return value;
    }
    
    void put(int key, int value) {
        auto iter = cacheTable.find(key);
        if (iter != cacheTable.end())
        {
            auto index = cacheTable[key];
            cacheList.erase(index);
        }
        else
        {
            if (cacheTable.size() == mCapacity)
            {
                auto head = cacheList.front();
                cacheTable.erase(head.first);
                cacheList.pop_front();
            }
        }
        cacheList.push_back(std::make_pair(key, value));
        cacheTable[key] = --cacheList.end();
        printMap();
    }

    void printMap()
    {
        for (const auto& pair : cacheList)
        {
            cout << "[" << pair.first << ", " << pair.second << "]";
        }
        cout << endl;
    }
private:
    int mCapacity;
    using keyValuePair = std::pair<int, int>;
    std::list<keyValuePair> cacheList;
    unordered_map<int, std::list<keyValuePair>::iterator> cacheTable;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
