#include<iostream>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

 

// only switch the value in node
class Solution1 {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode* n = head;

        while(n){
            length++;
            n = n->next;
        }

        int num = length - k + 1;
        int count = 0;
        ListNode* curr = head;
        ListNode* begin = nullptr;
        ListNode* end = nullptr;

        while(curr){
            count++;
            if(count == k) begin = curr;
            
            if(count == num) end = curr;

            if(begin != nullptr && end != nullptr) break;

            curr = curr->next;
        }
        swap(begin->val, end->val);

        return head;
    }
};

// Time complexity : O(2n) = O(n)
// Space complexity : O(1)


// swap the node it self
class Solution2 {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head || !head->next) return head; // If the list is empty or has only one node, return it as is.
        
        int length = 0;
        ListNode* n = head;
        while(n){
            length++;
            n = n->next;
        }

        //if (2*k - 1 == length) return head; // If kth node from start and end are the same, no swap needed.

        int swapIndex = length - k + 1;
        ListNode *prevX = nullptr, *currX = head; // To keep track of kth node and its previous node.
        ListNode *prevY = nullptr, *currY = head; // To keep track of (length-k+1)th node and its previous node.

        // Find the kth node and its previous node.
        for (int i = 0; i < k - 1; ++i) {
            prevX = currX;
            currX = currX->next;
        }

        // Find the (length-k+1)th node and its previous node.
        for (int i = 0; i < swapIndex - 1; ++i) {
            prevY = currY;
            currY = currY->next;
        }

        // If either node to swap is head of the list, update head pointer.
        if (!prevX) head = currY;
        else prevX->next = currY;
        
        if (!prevY) head = currX;
        else prevY->next = currX;
        
        ListNode* temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;

        return head;

        // Time complexity : O(2n) = O(n)
        // Space complexity : O(1)
    }
};