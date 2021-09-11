/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include <unordered_map>
using namespace std;
// @lc code=start
class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node() : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
class LRUCache
{
    int capacity;
    unordered_map<int, Node *> cache;
    int size;
    Node *head;
    Node *tail;

public:
    LRUCache(int capacity) : capacity(capacity), size(0)
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }
        Node *tempNode = cache[key];
        moveToHead(tempNode);
        return tempNode->value;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            Node *node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity)
            {
                Node *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
        else
        {
            Node *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
    void addToHead(Node *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(Node *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void moveToHead(Node *node)
    {
        removeNode(node);
        addToHead(node);
    }
    Node *removeTail()
    {
        Node *node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
