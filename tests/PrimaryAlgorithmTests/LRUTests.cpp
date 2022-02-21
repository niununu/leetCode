#include <catch2/catch_test_macros.hpp>
#include "../TestUtils.h"
#include "../include/PrimaryAlgorithm/146_LRU_cache.h"

TEST_CASE("146_LRUTests", "[146_LRUTests]")
{
    LRUCache* obj = new LRUCache(2);;
    obj->put(1, 1); // 缓存是 {1=1}
    obj->put(2, 2); // 缓存是 {1=1, 2=2}
    obj->get(1);    // 返回 1
    obj->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    obj->get(2);    // 返回 -1 (未找到)
    obj->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    obj->get(1);    // 返回 -1 (未找到)
    obj->get(3);    // 返回 3
    obj->get(4);    // 返回 4
}
