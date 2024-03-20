#include<vector>

using namespace std;
// key : desing Hash table

/*  explain:
    because the problem's condition is simple, so we can simply use an array to implement the hast table

    time complexity : O(1)
    space complexity : O(1000001) = O(1)
*/

class MyHashMap {
public:
    vector<int> map;

    MyHashMap() {
        map.assign(1000001, -1);
    }
    
    void put(int key, int value) {
        map[key] = value;
    }
    
    int get(int key) {
        return map[key];
    }
    
    void remove(int key) {
        map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */