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

    ListNode* reverse(ListNode* begin, ListNode* end){
        ListNode* curr = begin;
        ListNode* prev = end;

        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // We can try having a 2 pass approach 
        // One slow and one fast
        // The fast checks if there is k spots 
        // Slow can work to reverse 
        if (head == nullptr) {
            return head;
        }

        ListNode dummy(0, head);
        ListNode* prevGroup = &dummy;
        while(true) {
            ListNode* kth = head;
            // Checks if k nodes exist 
            for (int i = 1; i < k && kth; i++) {
                kth = kth->next;
            }

            if (!kth) break; // No more nodes left 

            ListNode* nextGroup = kth->next; // Start of next group 
            ListNode* newHead = reverse(head, nextGroup);

            prevGroup->next = newHead;

            prevGroup = head;
            head = nextGroup;
        }

        return dummy.next;
    }
};
