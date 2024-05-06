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
        ListNode *curr = head, *prev = NULL, *temp;
        while(curr) {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;

    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* newHead = reverse(head);

        int mx = 0;
        ListNode *curr = newHead, *prev = NULL, *temp;
        while(curr) {
            mx = max(mx, curr -> val);
            if(mx > curr -> val) {
                if(prev == NULL) {
                    temp = curr -> next;
                    curr -> next = NULL;
                    curr = temp;
                } else {
                    prev -> next = curr -> next;
                    curr = curr -> next;
                }
            } else {
                prev = curr;
                curr = curr -> next;
            }
        }
        return reverse(newHead);
    }
};
