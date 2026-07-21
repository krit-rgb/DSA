class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* prev=NULL, *curr=head, *nxt=NULL;

        ListNode* slow=head, *fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        curr=slow->next;

        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev = curr;
            curr = nxt;
        }

        ListNode* first = head;
        ListNode* sec = prev;
        while(sec){
            if(sec->val == first->val){
                sec=sec->next;
                first=first->next;
            }
            else{
                return false;
            }
        }

        return true;
    }
};