#include<iostream>
#include<unordered_map>

using namespace std;


// key : hashtable, doubly linked list

/*  explain:
    create a struct ListNode*, with key and value in it, with next and prev.

    use unordered map as hashtable, to store the unordered_map<int, ListNode*> cache;
        this is use to make the O(1) search time

    use doubly linked list to represent the LRU mechanism. use dummy head and tail for convinience.
*/
class LRUCache {
public:
    struct ListNode{
        int key, value;
        ListNode* next;
        ListNode* prev;

        ListNode(int k, int v){
            this->key = k;
            this->value = v;
        }
    };

    // dummy head and tail
    ListNode* head = new ListNode(-1, -1);
    ListNode* tail = new ListNode(-1, -1);

    LRUCache(int capacity) : capacity(capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail-> prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){     // the key-value pairs is in the cache
            ListNode* node = cache[key];
            int ans = node->value;

            //cache.erase(key);
            removeNode(node);
            addNode(node);

            //cache[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){     // the key-value pairs is in the cache
            ListNode* node = cache[key];
            cache.erase(key);
            removeNode(node);
        }

        if(cache.size() >= this->capacity){
            //cache.erase(tail->prev->key);
            //removeNode(tail->prev);
            ListNode* tail = popTail();
            cache.erase(tail->key);
            delete tail;
        }

        addNode(new ListNode(key, value));
        cache[key] = head->next;

    }

private:
    int capacity;   // the capacity of this cache
    
    //ListNode* head, *tail;
    unordered_map<int, ListNode*> cache;        // hashtable for O(1) searching

    void addNode(ListNode* node){
        ListNode* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    };

    void removeNode(ListNode* node){
        ListNode* prev = node->prev;
        ListNode* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    ListNode* popTail() {
        ListNode* res = tail->prev;
        removeNode(res);
        return res;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */