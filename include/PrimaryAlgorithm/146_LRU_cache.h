//146. LRU 缓存
// https://leetcode-cn.com/problems/lru-cache/
#include <map>
#include <memory.h>

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity = capacity;
    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {

    }

private:
    int capacity;
    struct Node
    {
        Node* prev;
        Node* back;
        int val;
    };
 
    std::map<int, Node*> cacheMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
