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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        while(2024) {
            ListNode *curr = dummy;
            bool flag = false;
            while(curr && !flag) {
                ListNode *curr2 = curr -> next;
                int val = 0;
                while(curr2 && !flag) {
                    val += curr2 -> val;
                    curr2 = curr2 -> next;

                    if(val == 0) {
                        curr -> next = curr2;
                        flag = false;
                    }
                }
                curr = curr -> next;
            }
            if(!flag) break;
        }
        return dummy -> next;
    }
};