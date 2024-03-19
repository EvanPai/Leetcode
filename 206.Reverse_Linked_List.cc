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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head; 

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;

        }

        return prev;
    }
};

// Time complexity : O(n)
// Space complexity : O(1)

