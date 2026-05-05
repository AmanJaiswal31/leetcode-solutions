// Problem: Add Two Numbers
// Link: https://leetcode.com/problems/add-two-numbers/
// Difficulty: Medium
// Approach: Linked List Simulation (Digit-wise Addition)
// Time: O(max(n, m)) | Space: O(max(n, m))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* l3 = new ListNode(0); // dummy node
        ListNode* head = l3;
        int carry = 0;

        // Traverse both lists
        while (l1 && l2) {
            int value = l1->val + l2->val + carry;
            carry = value / 10;

            l3->next = new ListNode(value % 10);
            l3 = l3->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        // Remaining l1
        while (l1) {
            int value = l1->val + carry;
            carry = value / 10;

            l3->next = new ListNode(value % 10);
            l3 = l3->next;

            l1 = l1->next;
        }

        // Remaining l2
        while (l2) {
            int value = l2->val + carry;
            carry = value / 10;

            l3->next = new ListNode(value % 10);
            l3 = l3->next;

            l2 = l2->next;
        }

        // If carry remains
        if (carry) {
            l3->next = new ListNode(carry);
        }

        return head->next; // skip dummy
    }
};