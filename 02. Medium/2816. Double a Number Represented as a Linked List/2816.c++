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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *curr = head;
        while(curr) {
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode *newHead = reverse(head);

        ListNode *prev = newHead;
        int carry = 0;
        while(prev) {
            int t = prev -> val;
            prev -> val = (t + t) % 10 + carry;
            carry = (t + t) / 10;
            prev = prev -> next;
        }
        return carry ? new ListNode(1, reverse(newHead)) : reverse(newHead);
    }
};