class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow->next;

        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next=prev;
            prev = curr;
            curr = next;
        }  

        slow->next = NULL;

        ListNode* first = head;
        ListNode* second = prev;

        while(second!=NULL){
            ListNode* fn = first->next;
            ListNode* sn = second->next;
            first->next = second;
            second->next = fn;
            first = fn;
            second = sn;
        }
    }
};