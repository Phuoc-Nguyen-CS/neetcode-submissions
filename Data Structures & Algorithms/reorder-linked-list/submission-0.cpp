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
        
        ListNode* slow = head;
        ListNode* fast = head;

        // Find the midde
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse from mid to end
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(secondHalf != nullptr) {
            ListNode* next = secondHalf->next;
            secondHalf->next = prev;

            prev = secondHalf;
            secondHalf = next;
        } // Slow should now be reversed 
        
        // Combine
        ListNode* firstHalf = head;
        secondHalf = prev; // Reset to the top again
        while (secondHalf != nullptr) {
            ListNode* tmp1 = firstHalf->next;
            ListNode* tmp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = tmp1;

            firstHalf = tmp1;
            secondHalf = tmp2;
        }
    }
};
