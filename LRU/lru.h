typedef struct _Node_
{
    /* data */
    int key;
    int value;
    struct _Node_ *next;
    struct _Node_ *pre;
} CacheNode;

class LRUCache
{
private:
    /* data */
    int cache_size;
    int cache_real_size;
    CacheNode *p_cache_list_head;
    CacheNode *p_cache_list_near;
    void detachNode(CacheNode *node);
    void addToFront(CacheNode *node);

public:
    LRUCache(int cache_size = 10);
    ~LRUCache();
    int getValue(int key);
    bool putValue(int key, int value);
};

LRUCache::LRUCache(int cache_size)
{
    this->cache_size = cache_size;
    this->cache_real_size = 0;
    this->p_cache_list_head = new CacheNode();
    this->p_cache_list_near = new CacheNode();
    this->p_cache_list_head->next = this->p_cache_list_near;
    this->p_cache_list_head->pre = nullptr;
    this->p_cache_list_near->pre = this->p_cache_list_head;
    this->p_cache_list_near->next = nullptr;
}

LRUCache::~LRUCache()
{
    CacheNode *p;
    p = p_cache_list_head->next;
    while (p != nullptr)
    {
        delete p->pre;
        p = p->next;
    }
    delete p_cache_list_near;
}

void LRUCache::detachNode(CacheNode *node)
{
    node->pre->next = node->next;
    node->next->pre = node->pre;
}

void LRUCache::addToFront(CacheNode *node)
{
    node->next = p_cache_list_head->next;
    p_cache_list_head->next->pre = node;
    p_cache_list_head->next = node;
    node->pre = p_cache_list_head;
}

int LRUCache::getValue(int key)
{
    CacheNode *p = p_cache_list_head->next;
    while (p->next != nullptr)
    {
        if (p->key == key)
        {
            detachNode(p);
            addToFront(p);
            return p->value;
        }
        p = p->next;
    }
    return -1;
}

bool LRUCache::putValue(int key, int value)
{
    CacheNode *p = p_cache_list_head->next;
    while (p->next != nullptr)
    {
        if (p->key == key)
        {
            p->value = value;
            getValue(key);
            return true;
        }
        p = p->next;
    }
}