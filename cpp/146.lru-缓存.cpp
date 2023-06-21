/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 *
 * https://leetcode.cn/problems/lru-cache/description/
 *
 * algorithms
 * Medium (53.49%)
 * Likes:    2715
 * Dislikes: 0
 * Total Accepted:    489.4K
 * Total Submissions: 914.9K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
 * 
 * 实现 LRUCache 类：
 * 
 * 
 * 
 * 
 * LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组
 * key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
 * 
 * 
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= capacity <= 3000
 * 0 <= key <= 10000
 * 0 <= value <= 10^5
 * 最多调用 2 * 10^5 次 get 和 put
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <map>
#include <time.h>

using namespace std;

// @lc code=start

class DLinkNode {
public:
    int key, value;
    DLinkNode *prev, *next;

    DLinkNode() {
        this->key = this->value = 0;
        this->prev = this->next = this;
    }

    DLinkNode(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = this->next = this;
    }
};

class LRUCache {
    map<int, DLinkNode*> lruMap;
    DLinkNode *head;
    int count, capacity;

    void insertToHead(DLinkNode *node) {
        DLinkNode *head = this->head;

        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }

    void remove(DLinkNode *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = node->next = node;
    }

public:
    LRUCache(int capacity) {
        if (capacity <= 0) {
            capacity = 10;
        }
        this->capacity = capacity;
        this->count = 0;
        this->head = new DLinkNode();
    }

    ~LRUCache() {
        delete this->head;
    }
    
    int get(int key) {
        if (this->lruMap.count(key) > 0) {
            DLinkNode *node = this->lruMap[key];
            remove(node);
            insertToHead(node);
            return node->value;
        }

        return -1;
    }
 
    void put(int key, int value) {
        if (this->lruMap.count(key) > 0) {
            DLinkNode *node = this->lruMap[key];
            node->value = value;
            remove(node);
            insertToHead(node);
            return;
        }

        if (this->count >= this->capacity) {
            DLinkNode *tail = this->head->prev;
            this->lruMap.erase(tail->key);
            remove(tail);
            delete tail;
            this->count--;
        }

        DLinkNode *newNode = new DLinkNode(key, value);
        this->lruMap[key] = newNode;
        insertToHead(newNode);
        this->count++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


/*
["LRUCache","put","put","get","put","put","get"]
[[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
*/
int main(void) 
{
    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(2, 2);
    cache.get(2);
    cache.put(1, 1);
    cache.put(4, 1);
    cache.get(2);
}
