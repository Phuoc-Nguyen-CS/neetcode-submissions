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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // Handles any left overs 
        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        ListNode *res = lists[0];

        for (int i = 1; i < lists.size(); ++i){
            res = mergeTwoLists(res, lists[i]);
        }

        return res;
    }
};
