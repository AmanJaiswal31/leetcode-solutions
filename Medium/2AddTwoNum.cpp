// Problem: Add Two Numbers
// Link: https://leetcode.com/problems/add-two-numbers/
// Difficulty: Medium
// Approach: Dummy Node + Carry Simulation — traverse both lists
//           simultaneously, add digits + carry, store result in
//           new linked list. carry = sum/10, digit = sum%10
// Time: O(max(n,m)) | Space: O(max(n,m))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy->next;
    }
};