

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Naive solution
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;

        int count = 1;  // length of linked list
        ListNode* n = head;
        while(n->next != nullptr){
            count++;
            n = n->next;
        }

        int target = count/2;
        int num = 0;
        n = head;
        ListNode* prev = n;

        while(num < target){
            num++;
            prev = n;
            n = n->next;

        }

        // delete the middle node
        prev->next = n->next;
        // delete n;
        return head;

    }
};

// slow fast pointer
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slowPrev = nullptr;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slowPrev = slow;
            slow = slow->next;
        }

        slowPrev->next = slow->next;        

        return head;

    }
};