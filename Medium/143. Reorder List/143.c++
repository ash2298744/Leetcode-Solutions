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

        ListNode *curr = head, *prev = NULL;
        while(curr != NULL) {
            ListNode *temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        
        ListNode *slow = head, *fast = head -> next;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode *first = head, *second = reverse(slow -> next);
        slow -> next = NULL;

        while(first && second) {
            ListNode *temp1 = first -> next, *temp2 = second -> next;

            first -> next = second;
            second -> next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
