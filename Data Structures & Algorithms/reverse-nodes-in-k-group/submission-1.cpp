/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        if(len<k){
            return head;
        }
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *next=NULL;
        int c=0;
        while(curr && c<k){
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
           c++;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};
