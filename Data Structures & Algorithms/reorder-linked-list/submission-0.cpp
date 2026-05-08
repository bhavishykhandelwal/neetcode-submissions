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
    void reorderList(ListNode* head) {
        if(head==NULL){
            return ;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while (fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode * sec=slow->next;
        slow->next=NULL;
        ListNode *prev=NULL;
        ListNode *curr=sec;
        ListNode *next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        ListNode *first=head;
        sec =prev;
        while(sec){
            ListNode *temp1=first->next;
            ListNode *temp2=sec->next;
            first->next=sec;
            sec->next=temp1;
            first=temp1;
            sec=temp2;
        }



    }
};
