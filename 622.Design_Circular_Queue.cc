#include<vector>

using namespace std;

// key : queue, design
/*  explain:
    use vector to design the circular queue.
    watch out for the edge case where head and tail start with -1;

    and when head == tail, set both to -1;
*/

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;

public:
    MyCircularQueue(int k) : data(k), head(-1), tail(-1), size(0) {}
    
    bool enQueue(int value) {
        if(isFull()) return false;

        if(isEmpty()) head = 0;

        tail = (tail + 1) % data.size();
        data[tail] = value;
        size++;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        if(head == tail){
            head = -1;
            tail = -1;
        }
        else{
            head = (head+1) % data.size();
        }
        size--;

        return true;
    }
    
    int Front() {
        if(!isEmpty()) return data[head];
        else return -1;
    }
    
    int Rear() {
        if(!isEmpty()) return data[tail];
        else return -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == data.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */