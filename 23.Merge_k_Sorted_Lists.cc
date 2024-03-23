#include<vector>
#include<queue>

using namespace std;

// key : min heap
/*  explain:
    use a min heap to store the current elements from each list(ex: 3 lists, so there will be 3 elements in the min heap at a time).
    pop the min element from min heap, and insert the next element of that list into min heap.
    until all the lists are empty.
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min heap
        auto compare = [](ListNode* l1, ListNode* l2) {return l1->val > l2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        // initial the min heap
        for(ListNode* list : lists){
            if(list != nullptr) minHeap.push(list);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // merging
        while(!minHeap.empty()){
            ListNode* top = minHeap.top();
            minHeap.pop();

            tail->next = top;
            tail = tail->next;

            if(top->next != nullptr) minHeap.push(top->next);
        }

        return dummy->next;

    }
};
