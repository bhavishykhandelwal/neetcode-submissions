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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while(temp) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        while(!pq.empty()) {
            int val = pq.top();
            pq.pop();

            ListNode* node = new ListNode(val);
            res->next = node;
            res = res->next;
        }

        return ans->next;
    }
};