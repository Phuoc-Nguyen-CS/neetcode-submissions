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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dealing with remainders
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while(l1 || l2 || carry != 0) {
            
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;

            // total = l1 + l2 + carry 
            int total = v1 + v2 + carry;
            
            if (total >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }

            curr->next = new ListNode(total % 10);

            // Move forward 
            curr = curr->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return dummy.next;
    }
};
