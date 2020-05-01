/**
 * Author: Amr Elzawawy
 * Date: 24-4-2020
 * Problem Name: LRUCache, Day 24 on the 30-Days LeetCode Challenge.
 */

/*
### Problem
Design and implement a data structure for  [Least Recently Used (LRU) cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU). It should support the following operations:  `get`  and  `put`.
`get(key)`  - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
`put(key, value)`  - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
The cache is initialized with a  **positive**  capacity.

### Reference Link
[https://leetcode.com/problems/lru-cache/](https://leetcode.com/problems/lru-cache/)

### Solution
Use a Hashtable that keeps track of the keys and its values in the double linked list.

Why use List (not say vector) ?
--> iterators are never invalidated by modifiers (unless erasing the element itself).
--> In addition, it takes constant time to add and remove nodes from the head or tail.
--> we store the iterator to the corresponding LRU queue in the values of the hash map.
--> since using erase on a list with an iterator takes constant time, all operations of the LRU cache run in constant time.
*/

#include <map>
#include <vector>
#include <list>

typedef std::pair<int, int> pairii;

class LRUCache {
/**
 * Your LRUCache object should be instantiated and called/used as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
private:
    int max_capacity_;
    int curr_capacity_;
    std::list<pairii> items_;
    std::map<int, std::list<pairii>::iterator> cache_;

public:

    explicit LRUCache(int max_capacity_)
            :max_capacity_(max_capacity_), curr_capacity_(0) { }

    int get(int key)
    {
        //  if the key doesn't exist in the cache
        if (!cache_.count(key))
            return -1;

        // transfers only the element pointed by cache_[key] from items_
        // into the container items_ into position specified by items_.begin()
        items_.splice(items_.begin(), items_, cache_[key]);
        return cache_[key]->second;
    }

    void put(int key, int value)
    {
        // insert if the key is not already present
        if (!cache_.count(key)) {
            // if cache reached capacity, invalidate the LRU before insertion.
            if (curr_capacity_ == max_capacity_)
                evictLRU();
            insertCache(key, value);
        }
            // set the key to new value if already present
        else
            updateCache(key, value);
    }

private:

    void evictLRU()
    {
        curr_capacity_--;
        cache_.erase(items_.back().first);
        items_.pop_back();
    }

    void updateCache(int key, int new_value)
    {
        //update value associated with key with new value.
        cache_[key]->second = new_value;

        // transfers only the element pointed by cache_[key] from items_
        // into the container items_ into position specified by items_.begin()
        items_.splice(items_.begin(), items_, cache_[key]);
    }

    void insertCache(int key, int value)
    {
        curr_capacity_++;
        // insert new element at the beginning of the items list.
        items_.emplace_front(key, value);
        // assign in the cache with the begin() iterator value.
        cache_[key] = items_.begin();
    }
};